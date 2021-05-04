//Area to test out our codes for multiple functions
#include "graph.h"
#include "priorityqueue.h"
#include "UserInterface.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    // char string1[100]="dollar";
    // char string2[100]="rupee";
    // char string3[100]="dirham";
    // AddCurrencyToGlobalList(string1);
    // AddCurrencyToGlobalList(string2);
    // AddCurrencyToGlobalList(string3);
    // PrintAllCurrencies();
    // printf("\n\n%d",LookupCurrencyVertex("rupppee"));
    PtrToCurrencyNode c=NULL;
    c=CreateEmptyCurrList();
    addcurrency("rupee",0,c);
    printcurrencylist(c);
    deletecurrency("rupee",c);
    printcurrencylist(c);
    addcurrency("dollar",1,c);
    printcurrencylist(c);
    addcurrency("dirham",2,c);
    printcurrencylist(c);
    // printf("%d",searchforcurrency("Dollar",c));
    addcurrency("dollar",8,c);
    printcurrencylist(c);

}