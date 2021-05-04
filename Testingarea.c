//Area to test out our codes for multiple functions
#include "graph.h"
#include "priorityqueue.h"
#include "UserInterface.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char string1[100]="dollar";
    char string2[100]="rupee";
    char string3[100]="dirham";
    AddCurrencyToGlobalList(string1);
    AddCurrencyToGlobalList(string2);
    AddCurrencyToGlobalList(string3);
    PrintAllCurrencies();
    printf("\n\n%d",LookupCurrencyVertex("rupppee"));

}