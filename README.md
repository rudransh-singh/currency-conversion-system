# Currency Conversion Program

## Overview

This is a simple program to convert one currency to another in accordance with the corresponding currency conversion rates and to find the best method of conversion between two currencies using Dijkstra's algorithm. The program can also detect a cycle of conversions among currencies in a trade bank.

## Usage

The main.c program has an infinite while loop to facilitate multiple queries. Each query is made by entering the number of the operation to be performed followed by additional information if required, like the name of the trade bank, currency conversion rate or currency name.


The list of possible operations along with their input command syntax is given below:
(Note: The quotes ("") in the command syntax indicate strings, not actual quotes)

1. Add Trade Bank<br>
    $ 1 "Trade Bank Name"

2. Remove Trade Bank<br>
    $ 2 "Trade Bank Name"

3. Add Currency Exchange<br>
    $ 3 "Trade Bank Name" "Source Currency" "Destination Currency" "Conversion Rate"<br>
This is to convert from source to destination currency. A directed edge is added to the graph of the trade bank from source currency to destination currency.

4. Remove Currency Exchange<br>
    $ 4 "Trade Bank Name" "Currency 1" "Currency 2"<br>
This removes the conversion from currency 1 to currency 2 in the specified trade bank.

5. Add Currency to Trade Bank<br>
    $ 5 "Trade Bank Name" "Currency"

6. Remove Currency from Trade Bank<br>
    $ 6 "Trade Bank Name" "Currency"

7. Search for Cycle (of currency exchanges) in Trade Bank<br>
    $ 7 "Trade Bank Name"<br>
If a cycle is found, "cycle found" is printed and the actual cycle (currency 1 -----> currency 2) is printed on a new line.

8. Print Trade Bank list<br>
    $ 8<br>
Lists the current trade banks present in the list.

9. Find best path to convert from currency A to currency B<br>
    $ 9 "Currency A" "Currency B"<br>
Outputs a positive integer to indicate the least cost of the required conversion. Prints INT_MAX if it is impossible to convert. 

10. Exit<br>
    $ 10<br>
This command breaks out of the while loop and terminates the program.

## Compilation and Execution

The 4 files that need to be compiled to generate the final executable binary file are priorityqueue.c, graph.c, UserInterface.c 
and main.c. For user interface, compile the mainfinal.c file and for input text files, compile the main.c file.<br> 
The command to compile without user interface is:<br>
$ gcc priorityqueue.c graph.c UserInterface.c main.c -o final

Here, final is the binary file that can be executed. To run the program, type the following command:<br>
$ ./final < input.txt

### Shell scripts

The program can also be run using the shell scripts runUI.sh or runwithoutUI.sh<br>

runUI.sh<br>
```c 
#!/bin/sh
gcc priorityqueue.c graph.c UserInterface.c mainfinal.c -o MainWithUI
./MainWithUI
```
runwithoutUI.sh<br>
```c
#!/bin/sh
gcc randominputgenerator.c -o inputgenerator
./inputgenerator > randominput.txt
gcc priorityqueue.c graph.c UserInterface.c main.c -o MainNoUI
./MainNoUI < randominput.txt
```
In order to use the program without ui use ./runwithoutUI and to use with UI do ./runUI.sh

The file input.txt contains a list of all user inputs for a single run of the program. The list of user commands in the file usually starts with "Add Trade Bank" and ends with "Exit". Each user command in input.txt is on a separate line. 

## Running Program on Terminal

```C
git clone https://github.com/rudransh-singh/currency-conversion-system.git
cd currency-conversion-system
gcc main.c graph.c priorityqueue.c UserInterface.c
```



