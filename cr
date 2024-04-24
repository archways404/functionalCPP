#!/bin/bash
# This script compiles and runs a C++ program.
# Usage: "cr filename" (without extension)
# Example: "cr input_text" (for input_text.cpp)

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 filename (without extension)"
    exit 1
fi

filename=$1

# Compile the C++ program
g++ -Wall -o $filename $filename.cpp
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running..."
    ./$filename
else
    echo "Compilation failed."
fi
