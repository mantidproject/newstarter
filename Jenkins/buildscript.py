#!/bin/env python
"""
Python Buildscript for Jenkins

Very basic at the moment. It finds every directory under
$WORKSPACE/exercises, excluding the one named "template" and builds all
projects under there in separate directories.

It assumes the WORKSPACE environment variable exists and points to the root
of the clone repository.
"""
import os
import shutil
import subprocess as subp
import sys

# Common variables
try:
  WORKSPACE = os.environ["WORKSPACE"]
except KeyError:
  print "WORKSPACE environment variable not found.\nThe build script assumes that a WORKSPACE environment variable points at the root of the source directory."
  sys.exit(1)
  
PROJECTS_ROOT = os.path.join(WORKSPACE, "exercises")
TEMPLATE_DIR_NAME = "template" #skip this directory

# Build directory structure
#   builds/
#         dirname1/
#         dirname2/
#         ...
# where dirname1 etc are the directories under PROJECTS_ROOT
BUILDS_ROOT = os.path.join(WORKSPACE, "builds")

################### Functions #########################################################

def make_scl_command(command_list):
    command_str = " ".join(command_list)
    quoted_command_str = "\"{0}\"".format(command_str)
    return " ".join(["scl", "enable", "devtoolset-2", "{0}".format(quoted_command_str)])
    
def is_windows():
    if sys.platform == "win32":
        return True
    else:
        return False

def run_cmake(cmakelists_path):

    cmake_exe = "cmake"
    if is_windows():
        generator = 'Visual Studio 14 Win64'
        cmd = [cmake_exe, "-G", generator, cmakelists_path]
        print "Running '%s'" % " ".join(cmd)
    else:
        generator = '\'Unix Makefiles\''
        cmd = [str(cmake_exe), "-G", str(generator), str(cmakelists_path)]
        cmd = make_scl_command(cmd)
        print "Running '%s'" % cmd
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
    except Exception, exc:
        print "Error: %s" % str(exc)
    # Get back to where we started
    os.chdir(saveddir)

def build(build_root):
    """
    Build the code in the build_root directory
    """
    if is_windows():
        msbuild_exe = r'C:\Windows\Microsoft.NET\Framework64\v4.0.30319\msbuild.exe'
        sln = os.path.join(build_root, "Project.sln")
        cmd = ["msbuildscript.bat", "/p:Configuration=Release", sln, msbuild_exe]
    else:
        cmd = make_scl_command(["make", "-C", build_root])
    print "Running '%s'" % cmd
    return subp.call(cmd, shell=True)

################### Main #########################################################

# Always perform a clean build
if os.path.exists(BUILDS_ROOT):
    print "Removing %s" % BUILDS_ROOT
    shutil.rmtree(BUILDS_ROOT)
print "Making %s" % BUILDS_ROOT
os.mkdir(BUILDS_ROOT)

dirnames = os.listdir(PROJECTS_ROOT)
dirnames.remove(TEMPLATE_DIR_NAME)
if len(dirnames) == 0:
    raise RuntimeError("No projects found to build")

statuses = []
for dirname in dirnames:
    print "Building",dirname
    src_root = os.path.join(PROJECTS_ROOT, dirname)
    build_root = os.path.join(BUILDS_ROOT, dirname)
    os.mkdir(build_root)
    generate_project(src_root, build_root)
    statuses.append(build(build_root))
    ##
all_passed = all(map(lambda x: x == 0, statuses))
sys.exit(0 if all_passed else 1)
