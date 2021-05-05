#ifndef GRAPH__H
#define GRAPH__H

//now defining a linklist for Currencies in a particular Tradebank
//This will only be used when we want to check whether a particular currency exists for a node or not







//now we add info on graph nodes
typedef struct GraphNode GraphNode;//standard typedef
typedef GraphNode* PtrToGraphNode;//standard typedef
struct GraphNode
{
    int VertexID; //stores the VertexID of the Node
    int weight;//will be useful for storing weights of edges
    PtrToGraphNode next;//stores the pointer to the next node
    
};
//now the actual adjacency list
typedef struct GraphList GraphList;
typedef GraphList* PtrToGraphList;
struct GraphList
{
    int NumberOfVertices;//stores the number of vertices that are currently present in the graph
    PtrToGraphNode* GraphVertexArray;//essentially an array of ptrtonodes
                                //which will essentially store pointers to the neighbouring vertices of a given vertex
};
typedef struct dijkstra dijkstra;
struct dijkstra{
    int* dist;  //contains the shortest cost 
   
    int* prev;  //contains the node previous to the end node for the shortest code, will be used to figure out the path
};//this is what we will have to return from the dijkstra function at the end




typedef struct currencynode currencynode;
typedef struct currencynode* PtrToCurrencyNode;
typedef PtrToCurrencyNode CurrencyList;
struct currencynode{
    char NameOfCurrency[100];// stores the name of the currency
    int Vertexid;//stores the VertexID of that currency
    PtrToCurrencyNode next;//pointer to next node
};
 




typedef struct Tradebank Tradebank;//typdefing structures
typedef Tradebank* PtrToTradebank;//typedefing pointers to tradebank
struct Tradebank{
    char NameOfTradeBank[100];//Stores the name of the trade bank
    PtrToTradebank next;
    PtrToGraphList G;
    // int currentcurrencynumber;//contains the number of currencies currently supported by the tradebank
    // char AvailableCurrencies[1000][100];//will contain the list of all available currencies
    int availablevertices[1000];
    PtrToCurrencyNode CurrencyHead;//Head of the linked list
    // add graph details later
};






//functions for currency linked list 
//these are present inside the tradebank struct
PtrToCurrencyNode CreateEmptyCurrList();
int searchforcurrency(char *inputcurrency, PtrToCurrencyNode C);//searches for the currency in the given linkedlist
void addcurrency(char *inputcurrency, int vertexid,PtrToCurrencyNode C);//adds a currency to the given linked list
void deletecurrency(char *inputcurrency, PtrToCurrencyNode C);//deletes the given currency from the linked list
void DeleteCurrList(PtrToCurrencyNode C);
void printcurrencylist(PtrToCurrencyNode C);//just a utility/testing function to check whether the linked list works

//functions for the tradebank







void DeleteGraph(PtrToGraphList G);//deletes the entire graph struct;
PtrToGraphList CreateGraph(int NumberOfVertices);//This function will create a graph with the given number of vertices, for our case it will be 1e3
void InsertEdge(PtrToGraphList G,int source,int destination,int weight);//this function will add an edge to the graphlist from the source vertex to the destination vertex with a given weight
void PrintGraph(PtrToGraphList G);//just some utility function to print the graph to see whether it is working or not
dijkstra dijkstraalgo(PtrToGraphList G, int NumberOfVertices, int startindex);//This function is the dijkstra algo to calculate minimum cost path from a given vertex to all other vertices
#endif // !GRAPH__H

