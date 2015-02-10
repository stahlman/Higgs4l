# $Id: BUILD.sh 17003 2012-08-10 12:45:42Z stahlman $

if [ "$1" = "clean" ]; then
    make distclean
    exit 0
fi

make default
