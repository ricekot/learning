import sys
from enum import Enum
from pathlib import Path


class BlockType(Enum):
    FILE = 0
    FREE = 1


class Block:
    block_type: BlockType
    size: int
    id_number: int

    def __init__(self, block_type: BlockType, size: int, id_number: int = 0):
        self.block_type = block_type
        self.size = size
        self.id_number = id_number

    def __repr__(self):
        match self.block_type:
            case BlockType.FILE:
                return str(self.id_number % 10) * self.size
            case BlockType.FREE:
                return "." * self.size


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python part2.py input.txt")
        sys.exit(1)

    input_file = Path(sys.argv[1])
    with open(input_file, "r") as f:
        disk_map = list(map(lambda x: int(x), f.readline().strip()))

    disk: list[Block] = []
    id_number = 0
    for file_idx, size in enumerate(disk_map):
        if size == 0:
            continue
        if file_idx % 2 == 0:
            disk.append(Block(BlockType.FILE, size, id_number))
            id_number += 1
        else:
            disk.append(Block(BlockType.FREE, size))

    # print(disk)

    file_idx: int = len(disk) - 1
    while file_idx >= 0:
        if disk[file_idx].block_type == BlockType.FREE:
            file_idx -= 1
            continue
        for free_idx in range(file_idx):
            if disk[free_idx].block_type == BlockType.FILE:
                continue
            if disk[file_idx].size <= disk[free_idx].size:
                difference = disk[free_idx].size - disk[file_idx].size
                if difference > 0:
                    disk[free_idx].size -= difference
                    disk[free_idx], disk[file_idx] = disk[file_idx], disk[free_idx]
                    disk.insert(free_idx + 1, Block(BlockType.FREE, difference))
                    file_idx += 1
                else:
                    disk[free_idx], disk[file_idx] = disk[file_idx], disk[free_idx]
                # print(disk)
                break
        file_idx -= 1

    result = 0
    size_so_far = 0
    for idx, block in enumerate(disk):
        if block.block_type == BlockType.FILE:
            # for i in range(size_so_far, size_so_far+block.size):
            #     print(f"{i} * {block.id_number}")
            result += sum(
                map(
                    lambda x: x * block.id_number,
                    range(size_so_far, size_so_far + block.size),
                )
            )
        size_so_far += block.size
    print(result)
