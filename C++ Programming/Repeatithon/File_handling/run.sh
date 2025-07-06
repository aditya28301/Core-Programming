#!/bin/bash

# Step 1: Compile the code
echo "Compiling the application..."
g++ -o app text_shuffle.cpp # Replace with your compiler and source file
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi
echo "Compilation successful. Executable created: ./app"

# Step 2: Process files in batches of 1,000
for dir in dir_*; do
    echo "Processing files in $dir"
    find "$dir" -maxdepth 1 -type f -name "file_*.txt" | xargs -n 1000 ./app
done


