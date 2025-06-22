#!/usr/bin/env python3

import argparse

from Solution import Solution

def main():
    soln = Solution()

    parser = argparse.ArgumentParser()
    parser.add_argument("fname", help="Relative path to the test case.")
    args = parser.parse_args()

    try:
        with open(f"{args.fname}", 'r') as fin:
            s = fin.readline().strip()
            expected = fin.readline().strip()

            print(f"{s}: s")
            print(f"{expected}: expected")
            print(f"{soln.romanToInt(s)}: actual")
    except FileNotFoundError:
        print(f"Error: The file '{args.fname}' was not found.")

if __name__ == '__main__':
    main()
