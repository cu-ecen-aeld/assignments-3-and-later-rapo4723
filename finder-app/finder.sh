#!/bin/sh

# Check to find if two arguments are entered during execution or not
if [ $# -ne 2 ]; then
    echo "Error: Two arguments required."
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

dirfiles=$1
strsearch=$2

# Check if filesdir is a valid directory
if [ ! -d "$dirfiles" ]; then
    echo "Error: $dirfiles is not a valid directory."
    exit 1
fi

# Count number of files in the directory and subdirectories
filecount=$(find "$dirfiles" -type f | wc -l)

# Count number of matching lines containing searchstr
matchcount=$(grep -r "$strsearch" "$dirfiles" | wc -l)

# Print the result
echo "The number of files are $filecount and the number of matching lines are $matchcount"
