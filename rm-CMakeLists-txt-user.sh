#!/bin/sh

set -e

find . -type f -name "*CMakeLists.txt.user" -exec rm {} \;
