#!/usr/bin/env python3

import os
from pathlib import Path
import subprocess
import sys
import unittest

if "GITHUB_WORKSPACE" in os.environ:
    WORKSPACE = Path(os.environ["GITHUB_WORKSPACE"])
else:
    print("GITHUB_WORKSPACE environment variable not found.\nThe build script assumes that a GITHUB_WORKSPACE environment variable points at the root of the source directory.")
    sys.exit(1)

source_dirs = [x for x in (WORKSPACE/"exercises-python").iterdir() if x.is_dir()]
source_dirs = [x for x  in source_dirs if x.name != "template"]

if len(source_dirs) == 0:
    print("No user directory found in exercises-python. Skipping.")
    exit(0)

if len(source_dirs) > 1:
    print("Multiple user directories found in exercises-python")
    exit(1)

user_source_dir = source_dirs[0]
user_ex1_main = user_source_dir / "ex01_basics" /"main.py"
user_ex2_main = user_source_dir / "ex02_oo_basics" /"main.py"

TEST_FILE = os.path.expanduser("~/files/Holmes.txt")


class TestEx(unittest.TestCase):
    def test_ex1_01_exists(self):
        self.assertTrue(user_ex1_main.exists())

    def test_ex1_02_executes(self):
        subprocess.check_output(["python3", user_ex1_main, TEST_FILE])

    def test_ex1_03_output(self):
        out = subprocess.check_output(["python3", user_ex1_main, TEST_FILE], encoding="UTF-8")
        lines = out.split("\n")

        self.assertEqual(lines[0].split(), ["Word", "Usage"])
        self.assertEqual(lines[1].split(), ["which", "55"])
        self.assertEqual(lines[2].split(), ["holmes", "49"])
        self.assertEqual(lines[6].split(), ["would", "20"])

    def test_ex2_01_exists(self):
        self.assertTrue(user_ex2_main.exists())

    def test_ex2_02_executes(self):
        subprocess.check_output(["python3", user_ex2_main])

    def test_ex2_03_output(self):
        out = subprocess.check_output(["python3", user_ex2_main], encoding="UTF-8")

        out = out.lower()
        self.assertIn("square", out)
        self.assertIn("rectangle", out)
        self.assertIn("circle", out)
        self.assertIn("triangle", out)

if __name__ == '__main__':
    unittest.main(verbosity=2)
