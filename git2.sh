# a series of commands to clean up after pushing

#!/bin/bash

git switch main
git branch
echo Choose the branch to clean up
read varname
git merge $varname
git push origin main
git push origin -d $varname
git branch -d $varname
