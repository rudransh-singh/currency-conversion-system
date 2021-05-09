#!/bin/sh
gcc priorityqueue.c graph.c UserInterface.c main.c -o final
./final<input.txt