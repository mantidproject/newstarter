#!/bin/env python
"""
Python Buildscript for Jenkins

Very basic at the moment. It finds every directory under
$WORKSPACE/exercises-cpp, excluding the one named "template" and builds all
projects under there in separate directories.

It assumes the WORKSPACE environment variable exists and points to the root
of the clone repository.
"""
import os
import platform
import shutil
import subprocess as subp
import sys

# Common variables
try:
    WORKSPACE = os.environ["WORKSPACE"]
except KeyError:
    print("WORKSPACE environment variable not found.\nThe build script assumes that a WORKSPACE environment variable points at the root of the source directory.")
    sys.exit(1)

PROJECTS_ROOT = os.path.abspath(os.path.join(WORKSPACE, "exercises-cpp"))
HELLO_WORLD_DIR_NAME = "hello_world"
TEMPLATE_DIR_NAME = "template"  # skip this directory

# Build directory structure
#   builds/
#         dirname1/
#         dirname2/
#         ...
# where dirname1 etc are the directories under PROJECTS_ROOT
BUILDS_ROOT = os.path.abspath(os.path.join(WORKSPACE, "builds"))

################### Functions #########################################################


def make_scl_command(command_list):
    dist = platform.linux_distribution()
    command_str = " ".join(command_list)
    quoted_command_str = "\"{0}\"".format(command_str)
    if dist[0] in ('Red Hat', 'CentOS Linux'):
        if dist[1].startswith('6') or dist[1].startswith('7'):
            devtoolset = '7' if dist[1].startswith('7') else '2'
            return " ".join(["scl", "enable", "devtoolset-{0}".format(devtoolset), "{0}".format(quoted_command_str)])
        else:
            return command_str
    else:
        return command_str


def is_windows():
    if sys.platform == "win32":
        return True
    else:
        return False


def run_cmake(cmakelists_path):
    if is_windows():
        cmake_exe = "cmake"
        generator = 'Visual Studio 16 2019'
        arch = 'x64'
        cmd = [cmake_exe, "-G", generator, "-A", arch, cmakelists_path]
        print(f"Running '{' '.join(cmd)}'")
    else:
        try:
            cmake_exe = "cmake3"
            subp.check_call([cmake_exe, "--version"])
        except OSError:
            cmake_exe = "cmake"
        generator = '\'Unix Makefiles\''
        cmd = [cmake_exe, "-G", str(generator), str(cmakelists_path)]
        cmd = make_scl_command(cmd)
        print(f"Running '{cmd}'")
    status = subp.call(cmd, shell=True)


def generate_project(src_root, build_root):
    """
    Run cmake in the given build_root., assuming there is a CMakeLists.txt file
    in the src_dir
    """
    saveddir = os.getcwd()
    try:
        os.chdir(build_root)
        run_cmake(src_root)
    except Exception as exc:
        print(f"Error: {str(exc)}")
    # Get back to where we started
    os.chdir(saveddir)


def build(build_root):
    """
    Build the code in the build_root directory
    """
    if is_windows():
        cmd = ["cmake", "--build", build_root, "--", "/nologo",
               "/verbosity:minimal", "/p:Configuration=Release"]
    else:
        cmd = make_scl_command(["make", "-C", build_root])
    print(f"Running '{cmd}'")
    return subp.call(cmd, shell=True)


def check_build_is_sane():
    src_dir = os.path.join(PROJECTS_ROOT, HELLO_WORLD_DIR_NAME)
    dest_dir = os.path.join(BUILDS_ROOT, HELLO_WORLD_DIR_NAME)
    os.mkdir(dest_dir)
    generate_project(src_dir, dest_dir)
    print("Checking a sample project can be built")
    if build(dest_dir) != 0:
        raise RuntimeError("Cannot build sample project")

################### Main #########################################################


# Always perform a clean build
if os.path.exists(BUILDS_ROOT):
    print(f"Removing {BUILDS_ROOT}")
    shutil.rmtree(BUILDS_ROOT)
print(f"Making {BUILDS_ROOT}")
os.mkdir(BUILDS_ROOT)

dirnames = os.listdir(PROJECTS_ROOT)
dirnames.remove(TEMPLATE_DIR_NAME)
dirnames.remove(HELLO_WORLD_DIR_NAME)

check_build_is_sane()

if len(dirnames) == 0:
    raise RuntimeError("No projects found to build")

statuses = []
for dirname in dirnames:
    print("Building", dirname)
    src_root = os.path.join(PROJECTS_ROOT, dirname)
    build_root = os.path.join(BUILDS_ROOT, dirname)
    os.mkdir(build_root)
    generate_project(src_root, build_root)
    statuses.append(build(build_root))
    ##
all_passed = all([x == 0 for x in statuses])
sys.exit(0 if all_passed else 1)
