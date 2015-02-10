# $Id: BUILD.sh 15916 2012-06-17 09:16:37Z stahlman $

if [ "$1" = "clean" ]; then
    make distclean
    exit 0
fi

make default
