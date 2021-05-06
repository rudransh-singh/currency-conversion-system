#include "graph.h"
#include "UserInterface.h"
#include "priorityqueue.h"
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
        printf("list is empty");
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
            printf("currency already exists"); //if the function returns -1 that means the currency wasn't there in the linked list
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
        printf("currency does not exist");
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
{ // we use this function to open a new bank in the sense to creat a head structure
    if (NoOfTradeBanks == 0)
    {
        ListofTradeBank = (PtrToTradebank)malloc(sizeof(Tradebank));

        strcpy(ListofTradeBank->NameOfTradeBank, BankName);
        ListofTradeBank->G = CreateGraph(1000);
        ListofTradeBank->CurrencyHead = (PtrToCurrencyNode)malloc(sizeof(currencynode));
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
        while (Traverse != NULL && BankExists)
        {
            if (strcmp(Traverse->NameOfTradeBank, BankName) == 0)
            {
                BankExists = false;
                break;
            }
            Traverse = Traverse->next;
        }

        if (BankExists)
        {
            Tradebank *NewBank = (Tradebank *)malloc(sizeof(Tradebank));

            strcpy(NewBank->NameOfTradeBank, BankName); //Storing bank name in the node created

            NewBank->G = CreateGraph(1000);
            NewBank->CurrencyHead = (PtrToCurrencyNode)malloc(sizeof(currencynode));
            NewBank->CurrencyHead->Vertexid = -1;
            NewBank->CurrencyHead->next = NULL;

            for (int i = 0; i < 1000; i++)
                NewBank->availablevertices[i] = 0; //initialises currency array to 0

            Tail->next = NewBank; // adding the node to end
            Tail = NewBank;       // updating the tail

            Tail->next = NULL;
            NoOfTradeBanks++;
        }
    }
} //we have to figure out how to create a new trade bank with variable name given to us by user

void AddCurrencyExchange(char *BankName, char *Currency1, char *Currency2, int ConversionRate)
{
    // char TradeBankName[50], Currency1[50],Currency2[50];
    // int exchangerate , comm;
    // scanf("%s %s %s %d %d",TradeBankName,Currency1,Currency2,&exchangerate,&commission);
    // for()check if the TradeBankName exist ya nahi;
    // nahi hua toh naya bana denge , else we ll just add the curr1 and 2 to the bank;
    // if it doesnot exist we ll AddTradeBank(TradeBankName);
    //AddCurrency(TradeBankName);
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
        }                                         //to check which of the two currency exists
        if (!Currency1Exists && !Currency2Exists) // both currency dont exists in the list
        {
            int id1 = 0, id2 = 0;
            PtrToTradebank Duplicate = Traverse;
            while (Traverse->availablevertices[id1] != 0)
                id1++;
            while (Duplicate->availablevertices[id2] != 0)
                id2++;

            Traverse->availablevertices[id1] = 1; // finds inde
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

void RemoveCurrencyExchange(char *BankName, char *source, char *dest)
{
    PtrToTradebank temp = Head;

    //check if Tradebank exists in linked list
    while (temp != NULL && strcmp(temp->NameOfTradeBank, BankName) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Bank does not exist! \n\n");
        return;
    }

    PtrToGraphList CurrGraph = temp->G;
    PtrToGraphNode *CurrGraphArray = CurrGraph->GraphVertexArray;

    PtrToGraphNode curr, prev;
    int source_idx, dest_idx;

    //check if source and dest currencies exist in the linked list of the Tradebank
    source_idx = searchforcurrency(source, temp->CurrencyHead);
    dest_idx = searchforcurrency(dest, temp->CurrencyHead);

    if (source_idx == -1)
    {
        printf("%s does not exist in this Tradebank! \n\n", source);
        return;
    }
    if (dest_idx == -1)
    {
        printf("%s does not exist in this Tradebank! \n\n", dest);
        return;
    }

    //check for edge between source_idx and dest_idx in adjacency list
    curr = CurrGraphArray[source_idx]->next;
    prev = CurrGraphArray[source_idx];

    while (curr != NULL && curr->VertexID != dest_idx)
    {
        curr = curr->next;
        prev = prev->next;
    }

    if (curr != NULL)
    {
        prev->next = curr->next;
        free(curr);
    }

    //check for edge between dest_idx and source_idx in adjacency list
    curr = CurrGraphArray[dest_idx]->next;
    prev = CurrGraphArray[dest_idx];

    while (curr != NULL && curr->VertexID != source_idx)
    {
        curr = curr->next;
        prev = prev->next;
    }

    if (curr != NULL)
    {
        prev->next = curr->next;
        free(curr);
    }

    return;
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
