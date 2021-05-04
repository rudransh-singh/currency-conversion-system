#include "graph.h"
#include "UserInterface.h"
#include "priorityqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char CurrencyList[1000][100];//Global Currency List
int CurrencyListCounter=0;//will keep track of the number of currencies inserted to the graph 
PtrToTradebank ListofTradeBank; // Linked List to store the TradeBanks
PtrToTradebank Tail; // To keep track of last added bank
PtrToTradebank Head; // To keep track of first added bank
int NoOfTradeBanks = 0; // To keep track of number of banks added



void AddCurrencyToGlobalList(char* inputcurrency)
{
    strcat(CurrencyList[CurrencyListCounter],inputcurrency);
    CurrencyListCounter++;
}

int LookupCurrencyVertex(char* inputcurrency)//will convert the currency name to the corresponding vertex from the currencylist
{
    for(int i=0;i<CurrencyListCounter;i++)//going through the array to figure out the index where the given currency is stored
    {
        if(strcmp(CurrencyList[i],inputcurrency)==0)//if currency found then return the index(which will also be our vertex)
        return i;
    }
    return -1;//if not found then return -1
}

void PrintAllCurrencies()
{
    for(int i=0;i<CurrencyListCounter;i++)
    {
        printf("%s---->",CurrencyList[i]);
    }
    return;
}







void AddTradeBank(char* BankName){ // we use this function to open a new bank in the sense to creat a head structure
    if(NoOfTradeBanks == 0){
        ListofTradeBank = (PtrToTradebank)malloc(sizeof(Tradebank));
        
        strcpy(ListofTradeBank->NameOfTradeBank,BankName);

        Tail = ListofTradeBank;
        Head = ListofTradeBank;

        Tail->next = NULL;
        NoOfTradeBanks++;
    }
    else{

    PtrToTradebank Traverse = Head; // We check if the bank exists or not
    bool BankExists = true;
    while(Traverse != NULL && BankExists){
        if(strcmp(Traverse->NameOfTradeBank,BankName) == 0)BankExists = false;
        Traverse = Traverse->next;
    }

    if(BankExists){    
    Tradebank* NewBank = (Tradebank*)malloc(sizeof(Tradebank));
    
    strcpy(NewBank->NameOfTradeBank,BankName); //Storing bank name in the node created

    Tail->next = NewBank;// adding the node to end
    Tail = NewBank;     // updating the tail

    Tail->next = NULL;
    NoOfTradeBanks++;
    }
 }
}//we have to figure out how to create a new trade bank with variable name given to us by user


void AddCurrencyExchange(char* BankName,char* Currency1 , char* Currency2 , int ConversionRate){
    // char TradeBankName[50], Currency1[50],Currency2[50];
    // int exchangerate , comm;
    // scanf("%s %s %s %d %d",TradeBankName,Currency1,Currency2,&exchangerate,&commission);
    // for()check if the TradeBankName exist ya nahi;
    // nahi hua toh naya bana denge , else we ll just add the curr1 and 2 to the bank;
    // if it doesnot exist we ll AddTradeBank(TradeBankName);
    //AddCurrency(TradeBankName);

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

