#!/bin/sh
gcc priorityqueue.c graph.c UserInterface.c main.c -o MainNoUI
./MainNoUI < input.txt