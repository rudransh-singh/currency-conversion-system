#include "UserInterface.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

PreExisitingTradebank[50][50];

AddTradeBank(char* BankName)
{ // we use this function to open a new bank in the sense to creat a head structure
    Tradebank* BankName = (Tradebank*)malloc(sizeof(Tradebank));
}//we have to figure out how to create a new trade bank with variable name given to us by user


AddCurrencyExchange()
{
    char TradeBankName[50], Currency1[50],Currency2[50];
    int exchangerate , commission;
    scanf("%s %s %s %d %d",TradeBankName,Currency1,Currency2,exchangerate,commission);
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

void UpdateCurrencyExchange(PtrToTradebank BankName, char* Currency1 , char* Curreny2, int ConversionRate);
