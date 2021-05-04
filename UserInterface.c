#include "UserInterface.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


PtrToTradebank ListofTradeBank; // Linked List to store the TradeBanks
PtrToTradebank Tail; // To keep track of last added bank
PtrToTradebank Head; // To keep track of first added bank
int NoOfTradeBanks = 0; // To keep track of number of banks added

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


void AddCurrencyExchange(char* BankName,char* Currency1 , char* Curreny2 , int ConversionRate , int commission){
    // char TradeBankName[50], Currency1[50],Currency2[50];
    // int exchangerate , comm;
    // scanf("%s %s %s %d %d",TradeBankName,Currency1,Currency2,&exchangerate,&commission);
    // for()check if the TradeBankName exist ya nahi;
    // nahi hua toh naya bana denge , else we ll just add the curr1 and 2 to the bank;
    // if it doesnot exist we ll AddTradeBank(TradeBankName);
    //AddCurrency(TradeBankName);

}

void UpdateCommission(PtrToTradebank BankName, char* Currency1, char* Currency2, int commission)
{
    PtrToGraphNode temp;

    //update commission for conversion from currency 1 to currency 2
    temp = BankName->CurrencyGraph->GraphList[currency1_id];

    while(temp != NULL && temp->VertexID != currency2_id) {
        temp = temp->next;
    }
    if (temp)
        temp->weight = commission;

    //update commission for conversion from currency 2 to currency 1
    temp = BankName->CurrencyGraph->GraphList[currency2_id];

    while(temp != NULL && temp->VertexID != currency1_id) {
        temp = temp->next;
    }
    if (temp)
        temp->weight = commission;

    return;
}

