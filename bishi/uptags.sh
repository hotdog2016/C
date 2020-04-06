#!/bin/zsh
find $PWD -name "*.[ch]" > .rootdir/cscope/cscope.files

cd ./.rootdir/cscope
cscope -bqk -i cscope.files
ctags -R

