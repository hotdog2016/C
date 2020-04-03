#!/bin/bash
#1.creat dir
mkdir -p .rootdir/{cscope,scripts}
#2.creat cscope file
rm -f ./.rootdir/cscope/cscope.files
find $PWD -name "*.[ch]" > .rootdir/cscope/cscope.files
cd ./.rootdir/cscope
echo current path is $PWD
cscope -Rbq -i $PWD/cscope.files

