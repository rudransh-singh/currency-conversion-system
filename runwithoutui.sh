#!/bin/sh
gcc randominputgenerator.c -o inputgenerator
./inputgenerator > randominput.txt
gcc priorityqueue.c graph.c UserInterface.c main.c -o MainNoUI
./MainNoUI < randominput.txt