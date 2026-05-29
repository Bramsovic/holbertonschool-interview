#!/usr/bin/python3
"""Read log lines from stdin and print aggregated metrics."""

import re
import sys


STATUS_CODES = (200, 301, 400, 401, 403, 404, 405, 500)
LINE_PATTERN = re.compile(
    r'^\S+ - \[[^\]]+\] "GET /projects/260 HTTP/1\.1" (\S+) (\d+)$'
)


def print_stats(total_size, status_counts):
    """Print the total file size and status code counts."""
    print("File size: {}".format(total_size))
    for status_code in STATUS_CODES:
        count = status_counts.get(status_code, 0)
        if count:
            print("{}: {}".format(status_code, count))


def parse_line(line):
    """Return parsed status and file size, or None if the line is invalid."""
    match = LINE_PATTERN.match(line)
    if match is None:
        return None

    status, file_size = match.groups()
    try:
        status = int(status)
    except ValueError:
        status = None

    return status, int(file_size)


def main():
    """Process stdin and print metrics after every 10 lines and at EOF."""
    total_size = 0
    line_count = 0
    status_counts = {}

    try:
        for line in sys.stdin:
            line_count += 1
            parsed_line = parse_line(line.rstrip("\n"))

            if parsed_line is not None:
                status, file_size = parsed_line
                total_size += file_size

                if status in STATUS_CODES:
                    status_counts[status] = status_counts.get(status, 0) + 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

        if line_count == 0 or line_count % 10 != 0:
            print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise


if __name__ == "__main__":
    main()
