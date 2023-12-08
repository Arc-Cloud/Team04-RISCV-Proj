#!/bin/bash

# Check if a file path is provided as an argument
if [ $# -eq 0 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

# Get the absolute path of the file
absolute_path=$(realpath "$1")

# Check if the file exists
if [ ! -e "$absolute_path" ]; then
    echo "Error: File not found: $absolute_path"
    exit 1
fi

echo "Absolute path of the file: $absolute_path"
