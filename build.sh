#!/bin/bash

rm ./ok

gcc main.c -o ok -L. -lquicksort -Wl,-rpath,.
