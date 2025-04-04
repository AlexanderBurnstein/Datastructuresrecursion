# Copyright (c) 2024 Nathan Greenfield. All rights reserved

# Require CMAKE 3.12 or higher
cmake_minimum_required(VERSION 3.12)

# If you create new headers files, add them to these list!
set(HEADER_FILES
    disk.h
    peg.h
    towers.h
)

# If you create new cpp files, add them to these list!
set(SOURCE_FILES
    disk.cpp
    peg.cpp
    towers.cpp
)

# Don't change this
add_library(src ${SOURCE_FILES} ${HEADER_FILES})

