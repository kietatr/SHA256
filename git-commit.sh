#!/bin/bash

# For expediting the git commit process
# Usage:
#     ./git-commit "Your git commit message"

git add -A 
git commit -m $1
git push