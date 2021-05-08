#ifndef __CurrencyUI
#define __CurrencyUI

// Takes the name of the bank and returns the array
// adds currencies to selected "TradeBankName" and stores the conversion between them
// if currency exchange already exists we update it else make new edge
/*
1. Add or delete a Trade bank. (String)
2. Add or delete a currency. (String)
3. Add or delete a currency conversion from a specied Trade Bank. (Conversion rate - Integer)
4. The best path of converting from currency A to B along with it's cost and the chosen Trade Bank.You can only choose a single Trade Bank for all the exchanges regarding this query.
*/
typedef struct DijkstraBankInfo DijkstraBankInfo;
struct DijkstraBankInfo
{
    int mincost;
    char TradeBankName[100];
};






PtrToCurrencyNode CreateEmptyCurrList(); //creates a dummy node and returns it's value
int searchforcurrency(char *inputcurrency, PtrToCurrencyNode C); //search for the input currency in the given currency linked list
void addcurrency(char *inputcurrency, int vertexid, PtrToCurrencyNode c); //add the input currency to the currency linked list
void deletecurrency(char *inputcurrency, PtrToCurrencyNode c); //deletes the node from the given currency list
void printcurrencylist(PtrToCurrencyNode C); //prints currency list on the screen
void DeleteCurrList(PtrToCurrencyNode C); //frees pointers in the currency list
void AddTradeBank(char *BankName); //adds a new Tradebank to the linked list
void AddCurrencyExchange(char *BankName, char *Currency1, char *Currency2, int ConversionRate); //adds an edge in the currency graph of a Tradebank
void RemoveCurrencyExchange(char* BankName, char* source, char* dest); //deletes an edge in the currency graph of a Tradebank
void RemoveTradeBank(char* BankName);
void PrintTradeBankList();
void PrintTradeBankList2();
void AddCurrencyExchange1(char *BankName, char *Currency1, char *Currency2, int ConversionRate);
void AddCurrencyToTradeBank(char *Bankname,char *inputcurrency);
void PrintTradeBankGraph(PtrToTradebank T);
void RemoveCurrencyFromTradeBank(char *BankName, char* inputcurrency);
void RemoveCurrencyExchange(char *BankName, char *Currency1, char *Currency2); //this function removes a currency exchange from the currency graph, if it exists 
DijkstraBankInfo DijkstraOnBankList(char* sourcecurrency, char* destcurrency);



// void AddTradeBank(char* BankName);// Parth Anish

// void AddCurrencyExchange(char* BankName,char* Currency1 , char* Currency2 , int ConversionRate); // Parth nd Anish

// void DeleteTradeBank(char* BankName);//Rohan 

// void DeleteCurrency(char* BankName,char* CurrencyName); // RP
 
// // void UpdateCommission(char* BankName,char* Currency1 , char* Curreny2, int commission); // Vikram
// void RemoveCurrencyExchange(char* BankName, char* source, char* dest);

// void UpdateCurrencyExchange(char* BankName, char* Currency1, char* Currency2, int ConversionRate); // Vikram
// void AddCurrencyToGlobalList(char* inputcurrency);
// int LookupCurrencyVertex(char* inputcurrency);
// void PrintAllCurrencies();
#endif