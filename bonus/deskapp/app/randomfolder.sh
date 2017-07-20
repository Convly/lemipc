#!/bin/bash

dir=$1
folder=`/bin/ls -d "$dir"/* | sort --random-sort | head -1`

echo "$folder";
