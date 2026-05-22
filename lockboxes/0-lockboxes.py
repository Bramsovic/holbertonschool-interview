#!/usr/bin/python3
"""Determine whether a collection of lockboxes can all be opened."""


def canUnlockAll(boxes):
    """Return True when every box in boxes can be reached from box 0."""
    if not boxes:
        return True

    unlocked = {0}
    boxes_to_open = [0]

    while boxes_to_open:
        box_index = boxes_to_open.pop()
        for key in boxes[box_index]:
            if key < len(boxes) and key not in unlocked:
                unlocked.add(key)
                boxes_to_open.append(key)

    return len(unlocked) == len(boxes)
