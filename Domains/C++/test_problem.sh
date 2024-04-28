#!/bin/bash

# Compile the main.cpp file
g++ main.cpp -o main

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Running the solution for the problem: $(basename "$PWD")"

    # Navigate to the input directory
    cd input

    # For each file in the input directory
    for file in *; do
        # Execute the compiled program and pass the file as an argument, redirect its output to a file
        ../main < "$file" > temp_output.txt

        # Extract the number from the input file name
        number=$(echo $file | grep -oP '(?<=input)\d+(?=.txt)')

        # Construct the output file name
        output_file="output$number.txt"

        # Use diff to compare the output
        diff -q -b -B temp_output.txt "../output/$output_file" > /dev/null
        if [ $? -eq 0 ]; then
            echo "Test $file passed"
        else
            echo "Test $file failed"
        fi

        # Remove the temporary output file
        rm temp_output.txt
    done

    # Delete the main file after using it
    rm ../main

else
    echo "Compilation failed"
fi