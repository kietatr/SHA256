#!/bin/bash

# For expediting the git commit process
# Usage:
#     ./git-commit.sh Your git commit message

MESSAGE="$*"

if [ $# -eq 0 ]
then
    printf "Need to add a commit message, like this:\n"
    printf "\t./git-commit.sh Your git commit message in no quotes\n"
else
    git add -A
    git commit -m "$MESSAGE"
    git push
fi