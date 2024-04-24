#!/bin/bash
# Check if the filename is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Extract the base name for the file
filename=$(basename -- "$1")
executable="${filename%.*}"

# Compile the program
g++ -Wall -o "$executable" "$1.cpp"
if [ $? -eq 0 ]; then  # Check if compilation was successful
    echo "Compilation successful, running..."
    ./"$executable"
else
    echo "Compilation failed"
fi

# To run the script:
# 1. -> Make the script executable
# 2. -> chmod +x cpp.sh
# 3. -> ./cpp.sh filename.cpp