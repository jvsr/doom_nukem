#!/bin/bash

LIBPATH=./libft
LIBREPO=https://github.com/Eathox/libft.git
rm -rf $LIBPATH
git clone $LIBREPO $LIBPATH
rm -rf $LIBPATH/.git
rm -rf $LIBPATH/.gitignore
rm -rf $LIBPATH/.travis.yml
rm -rf $LIBPATH/.codecov.yml
rm -rf $LIBPATH/tests
rm -rf $LIBPATH/travis.bash