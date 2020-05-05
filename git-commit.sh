#!/bin/bash

# For expediting the git commit process
# Usage:
#     ./git-commit Your git commit message

MESSAGE="'$*'"
git add -A 
git commit -m "$MESSAGE"
git push