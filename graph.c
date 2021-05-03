#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
PtrToGraphList CreateGraph(int NumberOfVertices)
{
    PtrToGraphList G;//making temporary Graphlist which we will return in the end
    //Allocating memory to the List
    G= (PtrToGraphList)malloc(sizeof(GraphList));//malloc'ed memory here
    //asserting whether memory has been allocated or not
    if(G==NULL)
    {
        printf("Malloc failed!\n");
        exit(0);
    }
    G->NumberOfVertices=NumberOfVertices;
    G->GraphVertexArray=(PtrToGraphNode*)malloc(NumberOfVertices*sizeof(PtrToGraphNode));
    //asserting for memory allocation
    if(G->GraphVertexArray==NULL)
    {
        printf("Malloc failed");
        exit(0);
    }
    //Now we create an empty Graph
    for(int i=0;i<NumberOfVertices;i++)
    {
        G->GraphVertexArray[i]=NULL;//Initialize all of the graph node pointers to NULL since an empty graph does not have neighbours for any vertex
    }
    return G;
}
void InsertEdge(PtrToGraphList G,int source,int destination,int inputweight)//this function will add an edge to the graphlist from the source vertex to the destination 
{
 int found=0;//In case there already exists an edge between source to destination this flag will change to 1
 PtrToGraphNode temp;//making a temporary NodePtr which will be inserted later
 temp=G->GraphVertexArray[source];//go to the source vertex of the array
 if(temp==NULL)
 {
     temp=(PtrToGraphNode)malloc(sizeof(GraphNode));
     temp->VertexID=destination;
     temp->weight=inputweight;//these three lines create the temp node and then set its ID and weight
     temp->next=G->GraphVertexArray[source];
     G->GraphVertexArray[source]=temp;//standard code for inserting a node to the front of the linked list   
 }
 for(;temp;temp=temp->next)//traversing through the list of the source vertex to check whether the edge already exists
 {
     int checker=temp->VertexID;//stores the vertex ID of the node being traversed right now
     if(checker==destination)
     {
         found=1;
     }
 }
 if(!found)
 {
     temp=(PtrToGraphNode)malloc(sizeof(GraphNode));
     temp->VertexID=destination;
     temp->weight=inputweight;//these three lines create the temp node and then set its ID and weight
     temp->next=G->GraphVertexArray[source];
     G->GraphVertexArray[source]=temp;//standard code for inserting a node to the front of the linked list
 }
 else
 {
     printf("Edge already exists\n");//incase the edge already exists then print this statement
 }
 return;
}
void PrintGraph(PtrToGraphList G)
{
    PtrToGraphNode temp;//temporary node structure which we will use to traverse the entire graph structure
    for(int i=0;i<G->NumberOfVertices;i++)
    {   
        if(G->GraphVertexArray[i]==NULL)//in case the i-th vertex has no neighbours then no need to traverse through the entire array
        {
            printf("%d node has no neighbours\n",i);
            continue;
        }
        printf("%d---->",i);//in case the i-th vertex has neighbours then print all the neighbours
        for(temp=G->GraphVertexArray[i];temp->next;temp=temp->next)
        {
            printf("%d(w=%d)---->",temp->VertexID,temp->weight);
        }
        printf("%d(w=%d)\n",temp->VertexID,temp->weight);//to make sure that the last neighbour doesn't get printed with an arrow we print it separately

    }
    return;
}

