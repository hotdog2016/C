#bin/bash

CURRENT=$(date "+%Y-%m-%d %H:%M:%S")
git add .
git commit -am "$CURRENT" && git push c master

