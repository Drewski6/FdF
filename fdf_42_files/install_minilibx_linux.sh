#!/usr/bin/bash

###############################################################################
# INSTALLATION SCRIPT FOR MINILIBX
#
# NOTE: THIS SCRIPT MAY REQUIRE SUDO
###############################################################################

printf "This script will install your MinilibX for your user."
printf "NOTE: This script may require sudo to copy files to certain user directories."
read -p "Would you like to continue? [y/n]" yn
case $yn in
	[Yy]* ) printf "you typed yes" ;;
	[Nn]* ) printf "you typed no"
		exit;;
	* ) printf "I didnt understand"
		exit;;
esac

###############################################################################
# VARIABLES
LIBPATH="minilibx-linux/"
###############################################################################

printf "\n"
FILE1="${LIBPATH}libmlx.a"
if test -f "$FILE1"; then
	FILE1_EXISTS=1
else
	FILE1_EXISTS=0
fi

FILE2="${LIBPATH}mlx.h"
if test -f "$FILE2"; then
	FILE2_EXISTS=1
else
	FILE2_EXISTS=0
fi

FILE3="${LIBPATH}man/man3/mlx.3"
if test -f "$FILE3"; then
	FILE3_EXISTS=1
else
	FILE3_EXISTS=0
fi


if [[ FILE1_EXISTS -eq 1 && FILE2_EXISTS -eq 1 && FILE3_EXISTS -eq 1 ]]; then
	printf "All files exist. Starting copy.\n"
else
	printf "Not all files exist.\n"
	printf "Summary:\n"
	printf "FILE1_EXISTS = $FILE1_EXISTS\n"
	printf "FILE2_EXISTS = $FILE2_EXISTS\n"
	printf "FILE3_EXISTS = $FILE3_EXISTS\n"
	printf "EXITING..."
	exit
fi

cp ${LIBPATH}libmlx.a /usr/local/lib
cp ${LIBPATH}mlx.h /usr/local/include
mkdir /usr/local/man/man3
cp ${LIBPATH}man/man3/mlx*.3 /usr/local/man/man3

printf "Installation Complete"
