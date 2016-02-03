#!/bin/sh

files=`ls`

file_list=""

for file in $files
do
    if [ $file != "rendu.sh" ]
    then
        file_list="$file_list $file"
    fi
done

if [ $# -ne 1 ]
then
    echo "entrez un parametre pour le nom de tarball"
    exit 1
fi

tar -cvf $1 $file_list
