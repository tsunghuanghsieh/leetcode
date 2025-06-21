#!/usr/bin/env python3

import argparse
import re

from Solution import Solution

def main():
    soln = Solution()

    parser = argparse.ArgumentParser()
    parser.add_argument("fname", help="Relative path to the test case.")
    args = parser.parse_args()

    try:
        with open(f"{args.fname}", 'r') as fin:
            line = fin.readline().strip()
            k = int(fin.readline().strip())
            expected = fin.readline().strip()

            nums = [int(n) for n in re.findall("[0-9]+", line)]

            print(f"{line}: nums")
            print(f"{k}: k")
            print(f"{expected}: expected")
            print(f"{soln.minimumDifference(nums, k)}: actual")
    except FileNotFoundError:
        print(f"Error: The file '{args.fname}' was not found.")

if __name__ == '__main__':
    main()
