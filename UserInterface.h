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




void AddTradeBank(char* BankName);// Parth Anish

void AddCurrencyExchange(char* BankName,char* Currency1 , char* Currency2 , int ConversionRate); // Parth nd Anish

void DeleteTradeBank(char* BankName);//Rohan 

void DeleteCurrency(char* BankName,char* CurrencyName); // RP
 
// void UpdateCommission(char* BankName,char* Currency1 , char* Curreny2, int commission); // Vikram

void UpdateCurrencyExchange(char* BankName, char* Currency1, char* Currency2, int ConversionRate); // Vikram
void AddCurrencyToGlobalList(char* inputcurrency);
int LookupCurrencyVertex(char* inputcurrency);
void PrintAllCurrencies();
#endif