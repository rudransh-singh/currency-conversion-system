//Area to test out our codes for multiple functions
#include "graph.h"
#include "priorityqueue.h"
#include "UserInterface.h"
#include <stdio.h>
#include <assert.h>
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
    // assert(c->next==NULL);
    // searchforcurrency("Dollar",c);
    // // printcurrencylist(c);
    // // deletecurrency("rupee",c);
    // // printcurrencylist(c);
    addcurrency("dollar",1,c);
    // // printcurrencylist(c);
    addcurrency("dirham",2,c);
    printcurrencylist(c);
    DeleteCurrList(c);
    // // printf("%d",searchforcurrency("Dollar",c));
    // addcurrency("dollar",8,c);
    // printcurrencylist(c);

    //testing out the delete graph function
    // PtrToGraphList G=NULL;
    // G=CreateGraph(1000);
    // InsertEdge(G,0,1,10);
    // InsertEdge(G,1,2,10);
    // InsertEdge(G,3,1,10);
    // InsertEdge(G,2,1,10);
    // InsertEdge(G,4,5,10);
    // InsertEdge(G,6,1,10);
    // InsertEdge(G,0,8,10);
    // InsertEdge(G,7,1,10);
    // InsertEdge(G,9,1,10);
    // PrintGraph(G);
    // // InsertEdge(G,10,1,10);
    // // InsertEdge(G,11,1,10);
    // // InsertEdge(G,8,2,10);
    // // InsertEdge(G,7,3,10);
    // // InsertEdge(G,78,1,10);
    // // InsertEdge(G,1,10,10);
    // // InsertEdge(G,12,1,10);
    // DeleteGraph(G);
    //using valgrind to test out these function
}