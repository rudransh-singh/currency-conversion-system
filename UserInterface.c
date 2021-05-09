#include "graph.h"
#include "UserInterface.h"
#include "priorityqueue.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// char CurrencyList[1000][100];//Global Currency List
int CurrencyListCounter = 0;    //will keep track of the number of currencies inserted to the graph
PtrToTradebank ListofTradeBank; // Linked List to store the TradeBanks
PtrToTradebank Tail;            // To keep track of last added bank
PtrToTradebank Head;            // To keep track of first added bank
int NoOfTradeBanks = 0;         // To keep track of number of banks added

// void AddCurrencyToGlobalList(char* inputcurrency)
// {
//     strcat(CurrencyList[CurrencyListCounter],inputcurrency);
//     CurrencyListCounter++;
// }

// int LookupCurrencyVertex(char* inputcurrency)//will convert the currency name to the corresponding vertex from the currencylist
// {
//     for(int i=0;i<CurrencyListCounter;i++)//going through the array to figure out the index where the given currency is stored
//     {
//         if(strcmp(CurrencyList[i],inputcurrency)==0)//if currency found then return the index(which will also be our vertex)
//         return i;
//     }
//     return -1;//if not found then return -1
// }

// void PrintAllCurrencies()
// {
//     for(int i=0;i<CurrencyListCounter;i++)
//     {
//         printf("%s---->",CurrencyList[i]);
//     }
//     return;
// }
PtrToCurrencyNode CreateEmptyCurrList() //creates a dummy node and returns it's value
{
    PtrToCurrencyNode t;
    t = (PtrToCurrencyNode)(malloc)(sizeof(currencynode));
    strcpy(t->NameOfCurrency, "undefined");
    t->Vertexid = -1;
    t->next = NULL;
    return t;
}

int searchforcurrency(char *inputcurrency, PtrToCurrencyNode C) //search for the input currency in the given currency linked list
{
    if (C->next == NULL)
    {
        // printf("list is empty");
        return -1;
    }
    PtrToCurrencyNode tempnode; //temporary pointer used to traverse the entire linked list
    tempnode = C->next;         //set the tempnode to point to head of linked list
    for (; tempnode; tempnode = tempnode->next)
    {
        if (strcmp(inputcurrency, tempnode->NameOfCurrency) == 0)
        {
            return tempnode->Vertexid; //return the vertex id of the currency in the linked list
        }
    }
    return -1; //if the element is not found in the linked list then return zero
}

void addcurrency(char *inputcurrency, int vertexid, PtrToCurrencyNode c) //add the input currency to the currency linked list
{
    //if list is empty then do nothing
    if (c->next == NULL)
    {
        PtrToCurrencyNode temp;
        temp = (PtrToCurrencyNode)malloc(sizeof(currencynode));
        strcpy(temp->NameOfCurrency, inputcurrency);
        temp->Vertexid = vertexid;
        temp->next = c->next;
        c->next = temp;
        return;
    }
    //first search for the currency in the given linked list
    else
    {
        int search = searchforcurrency(inputcurrency, c); //searches for the currency in the linked list
        if (search != -1)
        {
            // printf("currency already exists"); //if the function returns -1 that means the currency wasn't there in the linked list
            return;
        }
        else
        {
            PtrToCurrencyNode temp;                                 //create a temporary currency node which will be inserted
            temp = (PtrToCurrencyNode)malloc(sizeof(currencynode)); //malloc a node and return it's pointer to temp
            strcpy(temp->NameOfCurrency, inputcurrency);
            temp->Vertexid = vertexid;
            temp->next = c->next;
            c->next = temp; //inserting the node to the front of the linked list
        }
    }
}

void deletecurrency(char *inputcurrency, PtrToCurrencyNode c) //deletes the node from the given currency list
{
    int search = searchforcurrency(inputcurrency, c); //searches for the currency in the linked list
    if (search == -1)
    {
        // printf("currency does not exist");
        return;
    }
    else
    {
        if (strcmp(c->next->NameOfCurrency, inputcurrency) == 0) //if the first node itself is the node to be deleted
        {
            PtrToCurrencyNode temp = c->next;
            c->next = c->next->next;
            free(temp);
        }
        else
        {
            PtrToCurrencyNode temp = c->next->next;
            PtrToCurrencyNode prev = c->next;
            for (; temp; temp = temp->next, prev = prev->next)
            {
                if (strcmp(temp->NameOfCurrency, inputcurrency) == 0)
                {
                    prev->next = temp->next;
                    free(temp);
                }
            }
        }
        return;
    }
}

void printcurrencylist(PtrToCurrencyNode C)
{
    PtrToCurrencyNode temp;
    temp = C->next;
    for (; temp; temp = temp->next)
    {
        printf("{%s,%d}", temp->NameOfCurrency, temp->Vertexid);
    }
    printf("\n");
    return;
}

void DeleteCurrList(PtrToCurrencyNode C)
{
    PtrToCurrencyNode temp;
    if (C->next == NULL)
    {
        free(C);
        return;
    }
    while (C->next->next != NULL)
    {
        temp = C->next;
        C->next = C->next->next;
        free(temp);
    }
    free(C->next);
    C->next = NULL;
    free(C);
    return;
}

void AddTradeBank(char *BankName)
{                            // we use this function to open a new bank in the sense to creat a head structure
    if (NoOfTradeBanks == 0) //this is the first TradeBank to be added
    {
        ListofTradeBank = (PtrToTradebank)malloc(sizeof(Tradebank));

        strcpy(ListofTradeBank->NameOfTradeBank, BankName);
        ListofTradeBank->G = CreateGraph(1000);
        ListofTradeBank->CurrencyHead = (PtrToCurrencyNode)malloc(sizeof(currencynode));
        strcpy(ListofTradeBank->CurrencyHead->NameOfCurrency, "undefined");
        ListofTradeBank->CurrencyHead->Vertexid = -1;
        ListofTradeBank->CurrencyHead->next = NULL;

        for (int i = 0; i < 1000; i++)
            ListofTradeBank->availablevertices[i] = 0; //initialises currency array to 0

        Tail = ListofTradeBank;
        Head = ListofTradeBank;

        Tail->next = NULL;
        NoOfTradeBanks++;
    }
    else
    {

        PtrToTradebank Traverse = Head; // We check if the bank exists or not
        bool BankExists = true;
        while (Traverse != NULL && BankExists) //traversing to check if the bank already exists
        {
            if (strcmp(Traverse->NameOfTradeBank, BankName) == 0)
            {
                BankExists = false;
                break;
            }
            Traverse = Traverse->next;
        }

        if (BankExists) //if the bank does not exist but other banks already exist in the list
        {
            Tradebank *NewBank = (Tradebank *)malloc(sizeof(Tradebank));

            strcpy(NewBank->NameOfTradeBank, BankName); //Storing bank name in the node created

            NewBank->G = CreateGraph(1000);
            NewBank->CurrencyHead = (PtrToCurrencyNode)malloc(sizeof(currencynode));
            strcpy(NewBank->CurrencyHead->NameOfCurrency, "undefined");
            NewBank->CurrencyHead->Vertexid = -1;
            NewBank->CurrencyHead->next = NULL;

            for (int i = 0; i < 1000; i++)
                NewBank->availablevertices[i] = 0; //initialises currency array to 0

            Tail->next = NewBank; // adding the node to end
            Tail = NewBank;       // updating the tail

            Tail->next = NULL;
            NoOfTradeBanks++; //incrementing the number of TradeBanks
        }
        else //if the bank already exists
        {
            printf("Bank Already exists");
            return;
        }
    }
}

void AddCurrencyExchange(char *BankName, char *Currency1, char *Currency2, int ConversionRate)
{
    PtrToTradebank Traverse = Head;
    bool BankExists = false;

    while (Traverse != NULL && !BankExists)                   // We check if the bank exists or not by traversing the list
    {                                                         // using the temporary Pointer to struct TradeBank 'Traverse'
        if (strcmp(Traverse->NameOfTradeBank, BankName) == 0) //if the bank is found we change the bool variable to true and exit the loop
        {
            BankExists = true;
            break;
        }
        Traverse = Traverse->next;
    }

    if (BankExists) //if the bank is found we check if the currencies exist
    {
        PtrToCurrencyNode Checker = Traverse->CurrencyHead;
        bool Currency1Exists = false, Currency2Exists = false;

        while (Checker != NULL)
        {
            if (strcmp(Checker->NameOfCurrency, Currency1) == 0)
                Currency1Exists = true;
            if (strcmp(Checker->NameOfCurrency, Currency2) == 0)
                Currency2Exists = true;
            Checker = Checker->next;
        }                                         //to check which of the two currency exists
        if (!Currency1Exists && !Currency2Exists) // both currency dont exists in the list
        {
            int id1 = 0, id2 = 0;
            PtrToTradebank Duplicate = Traverse;
            while (Traverse->availablevertices[id1] != 0)
                id1++;
            while (Duplicate->availablevertices[id2] != 0)
                id2++;

            Traverse->availablevertices[id1] = 1; // finds available index and creates currency there
            Duplicate->availablevertices[id2] = 1;

            if (Traverse->CurrencyHead->Vertexid == -1) // no currency added to the currency list of the selected trade bank yet
            {

                Traverse->CurrencyHead->Vertexid = id1;
                strcpy(Traverse->CurrencyHead->NameOfCurrency, Currency1);

                PtrToCurrencyNode NewCurrency2 = (PtrToCurrencyNode)malloc(sizeof(currencynode));
                NewCurrency2->Vertexid = id2;
                NewCurrency2->next = NULL;
                strcpy(NewCurrency2->NameOfCurrency, Currency2);
                Traverse->CurrencyHead->next = NewCurrency2;

                InsertEdge(Traverse->G, id1, id2, ConversionRate); //inserting edge between the two added currency

                printf("BOTH DOESNT EXIST\n");
            }
            else
            {
                PtrToCurrencyNode NewCurrency1 = (PtrToCurrencyNode)malloc(sizeof(currencynode));
                PtrToCurrencyNode NewCurrency2 = (PtrToCurrencyNode)malloc(sizeof(currencynode));

                while (Traverse->CurrencyHead->next != NULL)
                    Traverse->CurrencyHead = Traverse->CurrencyHead->next; // so that we reach end of currency list

                NewCurrency1->Vertexid = id1;
                NewCurrency1->next = NULL;
                Traverse->CurrencyHead->next = NewCurrency1;
                strcpy(NewCurrency1->NameOfCurrency, Currency1);
                PtrToTradebank DuplicateForSecondCurrency = Traverse;
                DuplicateForSecondCurrency->CurrencyHead = DuplicateForSecondCurrency->CurrencyHead->next;

                NewCurrency2->Vertexid = id2;
                NewCurrency2->next = NULL;
                strcpy(NewCurrency2->NameOfCurrency, Currency2);
                DuplicateForSecondCurrency->CurrencyHead->next = NewCurrency2;

                InsertEdge(Traverse->G, id1, id2, ConversionRate);

                printf("BOTH DOESNT EXIST BUT THERE WERE SOME CURRENCY IN BANK\n");
            }
        }
        else if (!Currency2Exists && Currency1Exists) // Currency 1 exists but currency 2 doesnt
        {
            int id1 = 0, id2 = 0;
            PtrToTradebank Duplicate = Traverse;
            while (strcmp(Currency1, Duplicate->CurrencyHead->NameOfCurrency) != 0)
            {
                Duplicate->CurrencyHead = Duplicate->CurrencyHead->next;
            }
            id1 = Duplicate->CurrencyHead->Vertexid;

            while (Traverse->availablevertices[id2] != 0)
                id2++;

            Traverse->availablevertices[id2] = 1;

            PtrToCurrencyNode NewCurrency2 = (PtrToCurrencyNode)malloc(sizeof(currencynode));

            NewCurrency2->Vertexid = id2;
            NewCurrency2->next = NULL;
            strcpy(NewCurrency2->NameOfCurrency, Currency2);
            Duplicate->CurrencyHead->next = NewCurrency2;

            InsertEdge(Traverse->G, id1, id2, ConversionRate);

            printf("CURR 2 DOESNT EXIST BUT 1 DOES\n");
        }
        else if (Currency2Exists && !Currency1Exists) // Currency 1 doesntexists but currency 2 exists
        {
            int id1 = 0, id2 = 0;
            PtrToTradebank Duplicate = Traverse;
            while (strcmp(Currency2, Duplicate->CurrencyHead->NameOfCurrency) != 0)
            {
                Duplicate->CurrencyHead = Duplicate->CurrencyHead->next;
            }
            id2 = Duplicate->CurrencyHead->Vertexid;

            while (Traverse->availablevertices[id1] != 0)
                id1++;

            Traverse->availablevertices[id1] = 1;

            while (Traverse->CurrencyHead->next != NULL)
                Traverse->CurrencyHead = Traverse->CurrencyHead->next; // so that we reach end of currency list

            PtrToCurrencyNode NewCurrency1 = (PtrToCurrencyNode)malloc(sizeof(currencynode));

            NewCurrency1->Vertexid = id1;
            NewCurrency1->next = NULL;
            strcpy(NewCurrency1->NameOfCurrency, Currency1);
            Traverse->CurrencyHead->next = NewCurrency1; // added latest currency at the end of the currency list

            InsertEdge(Traverse->G, id1, id2, ConversionRate);

            printf("CURR 1 DOESNT EXIST CURR 2 DOES\n");
        }
    }
    else
    {
        printf("The Bank Does not Exist.\n");
        return;
    }
}

// void RemoveCurrencyExchange(char *BankName, char *source, char *dest)
// {
//     PtrToTradebank temp = Head;

//     //check if Tradebank exists in linked list
//     while (temp != NULL && strcmp(temp->NameOfTradeBank, BankName) != 0)
//     {
//         temp = temp->next;
//     }

//     if (temp == NULL)
//     {
//         printf("Bank does not exist! \n\n");
//         return;
//     }

//     PtrToGraphList CurrGraph = temp->G;
//     PtrToGraphNode *CurrGraphArray = CurrGraph->GraphVertexArray;

//     PtrToGraphNode curr, prev;
//     int source_idx, dest_idx;

//     //check if source and dest currencies exist in the linked list of the Tradebank
//     source_idx = searchforcurrency(source, temp->CurrencyHead);
//     dest_idx = searchforcurrency(dest, temp->CurrencyHead);

//     if (source_idx == -1)
//     {
//         printf("%s does not exist in this Tradebank! \n\n", source);
//         return;
//     }
//     if (dest_idx == -1)
//     {
//         printf("%s does not exist in this Tradebank! \n\n", dest);
//         return;
//     }

//     //check for edge between source_idx and dest_idx in adjacency list
//     curr = CurrGraphArray[source_idx]->next;
//     prev = CurrGraphArray[source_idx];

//     while (curr != NULL && curr->VertexID != dest_idx)
//     {
//         curr = curr->next;
//         prev = prev->next;
//     }

//     if (curr != NULL)
//     {
//         prev->next = curr->next;
//         free(curr);
//     }

//     //check for edge between dest_idx and source_idx in adjacency list
//     curr = CurrGraphArray[dest_idx]->next;
//     prev = CurrGraphArray[dest_idx];

//     while (curr != NULL && curr->VertexID != source_idx)
//     {
//         curr = curr->next;
//         prev = prev->next;
//     }

//     if (curr != NULL)
//     {
//         prev->next = curr->next;
//         free(curr);
//     }

//     return;
// }

void RemoveTradeBank(char *BankName)
{
    PtrToTradebank current, previous, position;       //creates 3 temporary Pointers to struct TradeBank for traversal
    current = Head->next;                             //Points to the 2nd TradeBank
    previous = Head;                                  //Points to the 1st TradeBank
    if (strcmp(Head->NameOfTradeBank, BankName) == 0) //if the bank to be deleted is the first Trade bank in the list
    {
        position = Head;
        Head = Head->next; //the 1st bank shall then point to the second bank(which now becomes the first bank)
    }
    else
    {
        while (current != NULL) //traversing the list of trade banks to find the Trade bank to be deleted
        {
            if (strcmp(current->NameOfTradeBank, BankName) == 0)
            {
                break;
            }
            current = current->next;
            previous = previous->next;
        }
        if (current == NULL) //we have reached the end of the list but could not find the name of the bank indicating it does not exist
        {
            printf("The Trade bank does not exist.\n");
            return;
        }
        previous->next = current->next;
        position = current;
    }

    DeleteCurrList(position->CurrencyHead); //deletes currency list of the Position pointer
    DeleteGraph(position->G);               //deletes the graph
    position->next = NULL;
    free(position); //frees the memory allocated to the Pointer Position
}

void PrintTradeBankList()
{ //this function creates a temporary pointer for traversal and then prints each TradeBank as it traverses the list of trade banks
    PtrToTradebank temp;
    temp = Head;
    while (temp != NULL)
    {
        printf("%s\n", temp->NameOfTradeBank);
        temp = temp->next;
    }
}

void PrintTradeBankList2()
{
    printf("\n\n\n");
    PtrToTradebank temp;
    temp = Head;
    while (temp != NULL)
    {
        printf("Name of TradeBank->%s\n", temp->NameOfTradeBank); //prints name of the bank
        printf("Currencies supported by the Tradebank are \n");   // prints name of currencies in the bank
        PtrToCurrencyNode tc = temp->CurrencyHead->next;
        for (; tc; tc = tc->next)
        {
            printf("%s\n", tc->NameOfCurrency);
        }
        printf("\nCurrency conversion rates are\n");
        PrintTradeBankGraph(temp);
        temp = temp->next;
        printf("--------------------\n\n\n");
    }
}

// void UpdateConversionRate(char* BankName, char* Currency1, char* Currency2, int ConversionRate)
// {
//     PtrToGraphNode temp;

//     //update commission for conversion from currency 1 to currency 2
//     temp = BankName->CurrencyGraph->GraphList[currency1_id];

//     while(temp != NULL && temp->VertexID != currency2_id) {
//         temp = temp->next;
//     }
//     if (temp)
//         temp->weight = commission;

//     //update commission for conversion from currency 2 to currency 1
//     temp = BankName->CurrencyGraph->GraphList[currency2_id];

//     while(temp != NULL && temp->VertexID != currency1_id) {
//         temp = temp->next;
//     }
//     if (temp)
//         temp->weight = commission;

//     return;
// }

void AddCurrencyExchange1(char *BankName, char *Currency1, char *Currency2, int ConversionRate)
{
    PtrToTradebank Traverse = Head; //declaring temporary pointer to struct TradeBank to traverse the List of Tradebanks
    bool BankExists = false;        //declaring bool variable to check if the bank exists or not

    while (Traverse != NULL && !BankExists) // We check if the bank exists or not by traversing the list
                                            // using the temporary Pointer to struct TradeBank 'Traverse'
    {                                       // finds the bank
        if (strcmp(Traverse->NameOfTradeBank, BankName) == 0)
        {
            BankExists = true;
            break;
        }
        Traverse = Traverse->next;
    }

    if (BankExists)
    {
        PtrToCurrencyNode Checker = Traverse->CurrencyHead;
        bool Currency1Exists = false, Currency2Exists = false;

        while (Checker != NULL)
        {
            if (strcmp(Checker->NameOfCurrency, Currency1) == 0)
                Currency1Exists = true;
            if (strcmp(Checker->NameOfCurrency, Currency2) == 0)
                Currency2Exists = true;
            Checker = Checker->next;
        }                                         //to check which of the two currency exists
        if (!Currency1Exists && !Currency2Exists) // both currency dont exists in the list
        {
            printf("neither currency exists");
            return;
        }

        else if (!Currency2Exists && Currency1Exists) // Currency 1 exists but currency 2 doesnt
        {
            printf("one of the two currencies does not exist");
            return;
        }
        else if (Currency2Exists && !Currency1Exists) // Currency 1 doesntexists but currency 2 exists
        {
            printf("one of the two currencies does not exist");
            return;
        }
        else
        {
            int sourceid = searchforcurrency(Currency1, Traverse->CurrencyHead); //finds the vertexID of currency1
            int destid = searchforcurrency(Currency2, Traverse->CurrencyHead);   //finds the vertexID of currency2
            if (EdgeExists(Traverse->G, sourceid, destid))
                printf("There already exists a conversion between the two given currencies");
            else
            {
                InsertEdge(Traverse->G, sourceid, destid, ConversionRate); //if edge deos not exist we create an edge between the two vertices(currencies)
            }
        }
    }

    else
    {
        printf("The Bank Does not Exist.\n");
        return;
    }
}

void AddCurrencyToTradeBank(char *Bankname, char *inputcurrency)
{
    PtrToTradebank Traverse = Head; // We check if the bank exists or not
    bool BankExists = false;

    while (Traverse != NULL && !BankExists)
    { // finds the bank
        if (strcmp(Traverse->NameOfTradeBank, Bankname) == 0)
        {
            BankExists = true;
            break;
        }
        Traverse = Traverse->next;
    }

    if (BankExists)
    {
        int currencyid = searchforcurrency(inputcurrency, Traverse->CurrencyHead);
        if (currencyid == -1)
        {
            int insertid = 0;
            for (; insertid < 1000; insertid++)
            {
                if (Traverse->availablevertices[insertid] == 0)
                    break;
            }
            if (insertid == 1000)
            {
                printf("Max Currency Limit Reached, Cannot Insert More Currencies\n");
            }
            else
            {
                Traverse->availablevertices[insertid] = 1;
                addcurrency(inputcurrency, insertid, Traverse->CurrencyHead);
            }
        }
        else
        {
            printf("Currency already exists");
            return;
        }
    }
    else
    {
        printf("Bank does not exist");
        return;
    }
}

void printcurrencyofvertexid(PtrToCurrencyNode C, int vertexid)
{
    PtrToCurrencyNode t = C->next;
    for (; t; t = t->next)
    {
        if (t->Vertexid == vertexid)
        {
            printf("%s", t->NameOfCurrency);
            return;
        }
    }
    return;
}

void PrintTradeBankGraph(PtrToTradebank T)
{
    PtrToGraphList TradebankGraph = T->G;
    for (int i = 0; i < TradebankGraph->NumberOfVertices; i++)
    {
        PtrToGraphNode tempgraphnode = TradebankGraph->GraphVertexArray[i];
        for (; tempgraphnode; tempgraphnode = tempgraphnode->next)
        {
            printcurrencyofvertexid(T->CurrencyHead, i);
            printf("----->");
            printcurrencyofvertexid(T->CurrencyHead, tempgraphnode->VertexID);
            printf("(conversion rate=%d)", tempgraphnode->weight);
            printf("\n");
        }
    }
}

void RemoveCurrencyExchange(char *BankName, char *Currency1, char *Currency2)
{

    PtrToTradebank Traverse = Head; // We check if the bank exists or not
    bool BankExists = false;
    while (Traverse != NULL && !BankExists)
    { // finds the bank
        if (strcmp(Traverse->NameOfTradeBank, BankName) == 0)
        {
            BankExists = true;
            break;
        }
        Traverse = Traverse->next;
    }
    if (BankExists)
    {
        PtrToCurrencyNode Checker = Traverse->CurrencyHead;
        bool Currency1Exists = false, Currency2Exists = false;

        while (Checker != NULL)
        {
            if (strcmp(Checker->NameOfCurrency, Currency1) == 0)
                Currency1Exists = true;
            if (strcmp(Checker->NameOfCurrency, Currency2) == 0)
                Currency2Exists = true;
            Checker = Checker->next;
        }
        if (!Currency1Exists && !Currency2Exists) // both currency dont exists in the list
        {
            printf("neither currency exists");
            return;
        }

        else if (!Currency2Exists && Currency1Exists) // Currency 1 exists but currency 2 doesnt
        {
            printf("one of the currencies does not exist");
            return;
        }
        else if (Currency2Exists && !Currency1Exists) // Currency 1 doesntexists but currency 2 exists
        {
            printf("one of the two currencies does not exist");
            return;
        }
        else
        {
            int sourceid = searchforcurrency(Currency1, Traverse->CurrencyHead);
            int destid = searchforcurrency(Currency2, Traverse->CurrencyHead);
            if (EdgeExists(Traverse->G, sourceid, destid))
            {
                RemoveEdge(Traverse->G, sourceid, destid);
            }
            else
            {
                printf("no conversion rate exists between the two currencies");
            }
        }
    }

    else
    {
        printf("The Bank Does not Exist.\n");
        return;
    }
}

DijkstraBankInfo DijkstraOnBankList(char *sourcecurrency, char *destcurrency)
{
    DijkstraBankInfo solution;
    PtrToTradebank t = Head;
    solution.mincost = INT_MAX;
    for (; t; t = t->next)
    {
        int sourceid = searchforcurrency(sourcecurrency, t->CurrencyHead);
        int destid = searchforcurrency(destcurrency, t->CurrencyHead);
        if (sourceid != -1 && destid != -1)
        {
            dijkstra answer;
            answer = dijkstraalgo(t->G, 10, sourceid);
            if (answer.dist[destid] < solution.mincost)
            {
                solution.mincost = answer.dist[destid];
                strcpy(solution.TradeBankName, t->NameOfTradeBank);
            }
        }
        else
        {
            continue;
        }
    }
    return solution;
}

void RemoveCurrencyFromTradeBank(char *BankName, char *inputcurrency)
{
    PtrToTradebank Traverse = Head; // We check if the bank exists or not
    bool BankExists = false;
    while (Traverse != NULL && !BankExists)
    { // finds the bank
        if (strcmp(Traverse->NameOfTradeBank, BankName) == 0)
        {
            BankExists = true;
            break;
        }
        Traverse = Traverse->next;
    }
    if (BankExists)
    {
        int currencyid = searchforcurrency(inputcurrency, Traverse->CurrencyHead);
        if (currencyid == -1)
        {
            printf("currency does not exist");
            return;
        }
        else
        {
            DeleteVertex(Traverse->G, currencyid);
            return;
        }
    }
    else
    {
        printf("Bank Does Not Exist");
        return;
    }
}

void CycleCheckinTradeBank(char *BankName)
{
    PtrToTradebank Traverse = Head; // We check if the bank exists or not
    bool BankExists = false;
    while (Traverse != NULL && !BankExists)
    { // finds the bank
        if (strcmp(Traverse->NameOfTradeBank, BankName) == 0)
        {
            BankExists = true;
            break;
        }
        Traverse = Traverse->next;
    }
    if (BankExists)
    {
        int currencycount = 0;
        PtrToCurrencyNode t = Traverse->CurrencyHead->next;
        for (; t; t = t->next)
        {
            currencycount++;
        }
        int low[currencycount];
        int scccount = Tarjan(Traverse->G, low, currencycount);
        if (currencycount == scccount)
        {

            printf("no cycle exists");
        }
        else
        {

            printf("cycle exists\n");
            // int cyclecounter = 0;
            // for (int i = 0; i < currencycount; i++)
            // {
            //     cyclecounter = 0;
            //     for (int j = 0; j < currencycount; j++)
            //     {
            //         if (low[j] == i)
            //             cyclecounter++;
            //     }
            //     if (cyclecounter > 1)
            //     {
            //         for (int j = 0; j < currencycount; j++)
            //         {
            //             if (low[j] == i)
            //             {
            //                 printcurrencyofvertexid(Traverse->CurrencyHead, j);
            //                 printf(" ");
            //             }
            //         }
            //         printf("\n");
            //     }
            // }
        }
        return;
    }
    else
    {
        printf("Bank does not exist");
        return;
    }
}