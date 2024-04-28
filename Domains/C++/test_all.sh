#!/bin/bash

# Save the current IFS
OLDIFS=$IFS

# Change IFS to newline
IFS=$'\n'

# Find all subdirectories in the current directory recursively
directories=$(find . -type d)

# Loop through each subdirectory
for dir in $directories; do
    # Check if the subdirectory contains a main, input, and output directory
    if [[ -f "$dir/main.cpp" && -d "$dir/input" && -d "$dir/output" ]]; then
        # Change directory to the subdirectory
        cd "$dir"
        
        # Run the test_problem.sh script in the current subdirectory
        ../../test_problem.sh
        
        # Change directory back to C++
        cd ../../
    fi
done

# Restore the original IFS
IFS=$OLDIFS