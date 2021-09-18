#!/bin/bash

TARGET="../bin/funkcje.o"
[ ! -f "$TARGET" ] && TARGET="./bin/funkcje.o";

IN_FILES=$(find . -type f -name '*.in' -printf '%P\n')

if [ ! -f "$TARGET" ]
then
    echo "[ERROR] '$TARGET' does not exist!"
    echo "[ERROR] Run 'make all' command to compile target executable."
    exit
fi

for in_file in $IN_FILES
do
    out_file=${in_file/.in/.out}

    if [ -f "$in_file" ] && [ -f "$out_file" ]
    then
        out_tmp_file="$out_file.tmp"

        $TARGET < $in_file > $out_tmp_file

        if cmp -s "$out_file" "$out_tmp_file";
        then
            echo "[SUCCESS] '$in_file'"
            rm $out_tmp_file
        else
            echo "[ERROR] '$in_file' failed"
            echo "[ERROR] '$out_tmp_file' not removed"
        fi


    else
        echo "[ERROR] '$out_file' does not exist!"
    fi
done

echo "[SUCCESS] finished"