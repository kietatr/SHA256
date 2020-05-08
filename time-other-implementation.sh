#!/bin/bash

# Make sure you have run this command first:
#     make other-implementation

for (( i=1; i<=10; ++i)); do
    echo ""
    echo "-----------------------------------------------------------"
    printf "TRIAL #%d\n" $i 
    printf "> Output: "
    \time -f "- Program: %C\n- Elapsed time: %e seconds" ./other-implementation
    echo "-----------------------------------------------------------"
done
