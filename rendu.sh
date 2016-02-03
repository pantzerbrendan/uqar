#!/bin/sh

if [ $# -ne 2 ]
then
    echo "Deux parametres minimum sont requis"
    echo "Utilisation : ./rendu.sh PATH output_file"
    echo "Exemple : ./rendu.sh ./TP1 archive.tar"
    exit 1
fi

files=`ls $1`

file_list=""

for file in $files
do
    if [ $file != "rendu.sh" ]
    then
        file_list="$file_list $1/$file"
    fi
done

tar -cvf $2 $file_list
