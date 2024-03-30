#!/bin/bash
gcc -fPIC -C *.c
gcc -shared *.c -o liball.so
