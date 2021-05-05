#include "graph.h"
#include "priorityqueue.h"
#include <stdio.h>
#include <limits.h>
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
     return;
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

dijkstra dijkstraalgo(PtrToGraphList G, int NumberOfVertices, int startindex)
{
    int vis[NumberOfVertices];//Creates a array which will store the visited nodes
    dijkstra answer;
    answer.dist=(int*)malloc(sizeof(int)*NumberOfVertices);
    answer.prev=(int*)malloc(sizeof(int)*NumberOfVertices);
    for(int i=0;i<NumberOfVertices;i++)
    {
        answer.dist[i]=INT_MAX;//setting all dist values to inf(INT_MAX)
        answer.prev[i]=-1;//setting all prev values to NULL(here -1)
        vis[i]=0;//setting visited array to 0 for all elements in the array
    }
    answer.dist[startindex]=0;//set startindex dist to zero to kickstart algo
    PtrToMinHeap PQ=NULL;//create empty priority queue
    PQ=CreateHeap(10000);
    InsertMinHeapKeyValue(PQ,startindex,0);//This will ensure that algo is kickstarted properly
    while(PQ->heap_size!=0)
    {
        HeapNode tempheapnode;
        tempheapnode=ExtractMin(PQ);//Extract the most promising key-value pair
        vis[tempheapnode.key]=1;//set vis of index in tempnode to true meaning that node has been visited
        if(answer.dist[tempheapnode.key]<tempheapnode.value)
            continue;//Stale Node optimization to ensure that nodes aren't visited multiple times
        PtrToGraphNode tempgraphnode;
        tempgraphnode=G->GraphVertexArray[tempheapnode.key];
        if(tempgraphnode==NULL)//if the vertex has no neighbours then skip(control flow will definitely not reach here but still)
        continue;
        for(;tempgraphnode->next;tempgraphnode=tempgraphnode->next)// traversing through the adjacency list of a particular index
        {
            if(vis[tempgraphnode->VertexID])//if the node has already been visited(i.e smallest distance has been found) then skip
            continue;
            int newDist=0;
            newDist=answer.dist[tempheapnode.key]+tempgraphnode->weight;
            if(newDist < answer.dist[tempgraphnode->VertexID])//This is the relaxation part of dijkstra algo
            {
                //if we have found a better distance then update the prev dist array as well as the heap
                answer.prev[tempgraphnode->VertexID]=tempheapnode.key;
                answer.dist[tempgraphnode->VertexID]=newDist;
                InsertMinHeapKeyValue(PQ,tempgraphnode->VertexID,newDist);
            }
        }
    }
    free(PQ);
    free(PQ->Harr);
    return answer;
}
void DeleteGraph(PtrToGraphList G)
{

    for (int i = 0; i < G->NumberOfVertices; i++)
    {
        PtrToGraphNode temp;
        if (G->GraphVertexArray[i] == NULL)
            continue;
        while (G->GraphVertexArray[i]->next != NULL)
        {
            temp = G->GraphVertexArray[i];
            G->GraphVertexArray[i] = G->GraphVertexArray[i]->next;
            free(temp);
        }
        free(G->GraphVertexArray[i]);
        G->GraphVertexArray[i] = NULL;
    }
    free(G->GraphVertexArray);
    free(G);
}
void DeleteVertex(PtrToGraphList G, int vertex)
{
    PtrToGraphNode tempgraphnode;//temporary node 
    PtrToGraphNode prevgraphnode;//pointer to previous node
    for(int i=0;i<G->NumberOfVertices;i++)
    {
        if(i==vertex)
        continue;
        else
        {
            tempgraphnode=G->GraphVertexArray[i];
            if(tempgraphnode==NULL)
            continue;
            if(tempgraphnode->VertexID==vertex)
            {
                free(tempgraphnode);
                G->GraphVertexArray[i]=NULL;
                continue;
            }
            else
            {
                tempgraphnode=G->GraphVertexArray[i]->next;
                prevgraphnode=G->GraphVertexArray[i];
                for(;tempgraphnode;tempgraphnode=tempgraphnode->next,prevgraphnode=prevgraphnode->next)
                {
                    if(tempgraphnode->VertexID==vertex)
                    {
                        prevgraphnode->next=tempgraphnode->next;
                        free(tempgraphnode);
                        break;
                    }
                }
            }

        }
    }
    PtrToGraphNode temp;
    if (G->GraphVertexArray[vertex] == NULL)
        return;
    while (G->GraphVertexArray[vertex]->next != NULL)
    {
        temp = G->GraphVertexArray[vertex];
        G->GraphVertexArray[vertex] = G->GraphVertexArray[vertex]->next;
        free(temp);
    }
    free(G->GraphVertexArray[vertex]);
    G->GraphVertexArray[vertex] = NULL;
}