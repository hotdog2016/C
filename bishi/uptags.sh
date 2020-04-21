#!/bin/zsh
ctags -R
find $PWD -name "*.[ch]" > .rootdir/cscope/cscope.files

cd ./.rootdir/cscope
cscope -bqk -i cscope.files

