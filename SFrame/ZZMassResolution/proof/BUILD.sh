# $Id: BUILD.sh 17002 2012-08-10 12:44:42Z stahlman $

if [ "$1" = "clean" ]; then
    make distclean
    exit 0
fi

make default
