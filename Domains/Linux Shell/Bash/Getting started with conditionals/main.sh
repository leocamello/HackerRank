#!/bin/bash

read c

if [ $c = 'y' ] || [ $c = 'Y' ]; then
    echo "YES"
else
    echo "NO"
fi
