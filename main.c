#include "graph.h"
#include "priorityqueue.c"
#include <stdio.h>
#include <stdlib.h>
#include "UserInterface.c"
int main()
{   
    // while(1){
    // printf("Enter Bank Name ->");
    // char BankName[50];
    // scanf("%s",BankName);
    // AddTradeBank(BankName);
    // if(strcmp(BankName,"quit") == 0)break;
    // }
    // while(Head!=NULL){
    //     printf("%s ",Head->NameOfTradeBank);
    //     Head = Head->next;
    // }
    //checking whether Graphlist works
    // PtrToGraphList G=NULL;
    // G=CreateGraph(10);
    // InsertEdge(G,1,2,12);
    // InsertEdge(G,1,3,10);
    // InsertEdge(G,1,4,10);
    // InsertEdge(G,1,5,11);
    // InsertEdge(G,1,6,10);
    // InsertEdge(G,1,7,13);
    // InsertEdge(G,1,8,12);
    // InsertEdge(G,1,8,10);
    // InsertEdge(G,2,8,10);
    // InsertEdge(G,4,7,10);
    // InsertEdge(G,3,8,10);
    // InsertEdge(G,3,6,10);

    // PrintGraph(G);

    //Checking whether Heap works
/*
    PtrToMinHeap H=NULL;
    H=CreateHeap(11); //CreateMinHeap of size 11
    InsertMinHeapKeyValue(H,1,3);
    PrintHeap(H);

    InsertMinHeapKeyValue(H,1,2);
    PrintHeap(H);

    InsertMinHeapKeyValue(H,1,1);
    PrintHeap(H);

     DeleteKeyHeap(H,1);
    PrintHeap(H);

    InsertMinHeapKeyValue(H,1,15);
    PrintHeap(H);

    InsertMinHeapKeyValue(H,1,5);
    PrintHeap(H);

    InsertMinHeapKeyValue(H,1,4);
    PrintHeap(H);

    InsertMinHeapKeyValue(H,1,45);
    PrintHeap(H);

    
    HeapNode t;
    DecreaseKey(H,4,1);
    PrintHeap(H);

    t=ExtractMin(H);
    PrintHeap(H);

    printf("min-keyvalue pair for H is \n Key=%d and value= %d \n",t.key,t.value);
    printf("min-keyvalue pair for H is \n Key=%d and value= %d \n",GetMin(H).key,GetMin(H).value);
*/

}
