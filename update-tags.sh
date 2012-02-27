#!/bin/sh
#
# update-tags.sh
#
# rebuilds ctags file for faster sourcecode navigation.
# Ctrl+] to go to code under cursor, 
# Ctrl+t to return where you were
#
# Ctrl+W+] to go to code under cursor, in a new window
#

CTAGS=`which ctags`

exit_usage() {
    echo "ERROR: MISSING ctags command."
    echo " on a debian box, use apt-get install exuberant-ctags to get it."
    exit 1
}

[ -z ${CTAGS} ] && exit_usage

${CTAGS} -R

