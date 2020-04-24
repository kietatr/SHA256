:: For expediting the git commit process
:: Usage:
::     git-commit.bat "Your git commit message"

@echo off
git add -A 
git commit -m %1
git push