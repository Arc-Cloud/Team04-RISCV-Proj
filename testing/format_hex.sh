#!/bin/bash

while read -r line; do
    # Extract pairs of characters and add a space in between
    formatted_line=$(echo $line | sed 's/../& /g')
    
    # Trim leading and trailing whitespace
    formatted_line=$(echo $formatted_line | sed 's/^[ \t]*//;s/[ \t]*$//')
    
    echo $formatted_line
done
