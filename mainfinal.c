#include <stdio.h>
#include <stdlib.h>
//#include "UserInterface.c"
//#include "graph.c"
#include "graph.h"
#include "priorityqueue.h"
#include "UserInterface.h"
//#include "priorityqueue.c"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

void UserData()
{                                                //function to print all the available commands to user
    printf("1.Add Trade Bank\n");                //good
    printf("2.Remove Trade Bank\n");             //good
    printf("3.Add Currency Exchange\n");         //good          //****
    printf("4.Remove Currency Exchange\n");      //good      //****
    printf("5.Add Currency To TradeBank\n");     //good
    printf("6.Search For Cycle\n");              //remove
    printf("8.Delete Curency from Tradebank\n"); //good
    printf("11.Print Trade Bank List\n");        //good           //****
    printf("13.Dijkstra On Bank List\n"); //good            //****
    printf("14.Show UserData\n");         //good
    printf("15.Exit\n");                  //good
}

int main()
{

    PtrToCurrencyNode CurrNode;       // pointer to Empty Currency List Node
    CurrNode = CreateEmptyCurrList(); //Creates an Empty Currency List

    UserData(); //calls the function

    while (1)
    { //starts infinite loop

        printf("Enter The Respective Number Of The Required Operation:"); //asks for the operation to be performed
        char Operation[50];
        scanf("%s", Operation);

        if (strcmp(Operation, "1") == 0) //Operation 1 (ADD TRADE BANK) Starts Here
        {
            char TradeBank[50];
            printf("Enter Name Of The Trade Bank:");
            scanf("%s", TradeBank);

            AddTradeBank(TradeBank); //Adds Tradebank to the list
            printf("\nEnter 14 for Operations Data\n\n");
        }

        else if (strcmp(Operation, "2") == 0) //Operation 2 (REMOVE TRADE BANK) Starts Here
        {
            char TradeBank[50];
            printf("Enter Name Of The Trade Bank:");
            scanf("%s", TradeBank);

            RemoveTradeBank(TradeBank); //Removes TradeBank from the List
            printf("\nEnter 14 To View Operations Data\n\n");
        }

        else if (strcmp(Operation, "3") == 0) //Operation 3 (ADD CURRENCY EXCHANGE) Starts Here
        {
            char TradeBank[50];
            char Currency1[50];
            char Currency2[50];
            int ConversionRate, Commission;

            printf("Enter Name Of The Trade Bank:");
            scanf("%s", TradeBank);

            printf("Enter Currency1:");
            scanf("%s", Currency1);

            printf("Enter Currency2:");
            scanf("%s", Currency2);

            printf("Enter Conversion Rate:");
            scanf("%d", &ConversionRate);

            AddCurrencyExchange1(TradeBank, Currency1, Currency2, ConversionRate); // Adds Conversion Rate (Edge) between Currency1 Currency2 in the Graph

            printf("\nEnter 14 To View Operations Data\n\n");
        }

        else if (strcmp(Operation, "4") == 0) //Operation 4 (REMOVE CURRENCY EXCHANGE) Starts Here
        {
            char TradeBank[50];
            char Currency1[50];
            char Currency2[50];

            printf("Enter Name Of The Trade Bank:");
            scanf("%s", TradeBank);

            printf("Enter The Source:");
            scanf("%s", Currency1);

            printf("Enter The Destiantion:");
            scanf("%s", Currency2);

            RemoveCurrencyExchange(TradeBank, Currency1, Currency2); // Removes Conversion Rate (Edge) between Currency1 Currency2 in the Graph

            printf("\nEnter 14 To View Operations Data\n\n");
        }

        else if (strcmp(Operation, "5") == 0) //Operation 5 (ADDS CURRENCY TO TRADEBANK) Starts Here
        {
            char TradeBank[50];
            char InputCurrency[50];

            printf("Enter Name Of The Trade Bank:");
            scanf("%s", TradeBank);

            printf("Enter Currency:");
            scanf("%s", InputCurrency);

            AddCurrencyToTradeBank(TradeBank, InputCurrency); // Adds currency as a disjoint vertex to the selected tradebank

            printf("\nEnter 14 To View Operations Data\n\n");
        }

        else if (strcmp(Operation, "6") == 0) //Operation 6 (SEARCH FOR CYCLE) Starts Here
        {
            char BankName[50];

            printf("Enter BankName:");
            scanf("%s", BankName);
            CycleCheckinTradeBank(BankName); //Runs Tarjan's Algorithm on The Graph of TradeBank and checks for cycle
            printf("\nEnter 14 To View Operations Data\n\n");
        }

        else if (strcmp(Operation, "8") == 0) //Operation 8 (DELETE CURRENCY FROM TRADEBANK) Starts Here
        {
            char Currency[50];
            char BankName[100];
            printf("Enter TradeBank Name:");
            scanf("%s", BankName);
            printf("Enter The Currency:");
            scanf("%s", Currency);
            RemoveCurrencyFromTradeBank(BankName, Currency); //Searches for the currency in the TradeBank selected and
                                                             //deletes the vertex and all edges connected to it if it exists
            printf("\nEnter 14 To View Operations Data\n\n");
        }
        
        
        
        // else if(strcmp(Operation,"9")==0){
        //     printcurrencylist(CurrNode);
            
        //     printf("\nEnter 14 for Operations Data\n\n");
        // }
        
        
        
        // else if(strcmp(Operation,"10")==0){
        //     DeleteCurrList(CurrNode);
            
        //     printf("\nEnter 14 for Operations Data\n\n");
        // }
        
        else if (strcmp(Operation, "10") == 0)
        {
            PrintTradeBankList();

            printf("\nEnter 14 for Operations Data\n\n");
        }
        
        
        
        else if(strcmp(Operation,"11")==0){
            PrintTradeBankList2();
            
        }
        else if (strcmp(Operation, "11") == 0) //Operation 11 (PRINT TRADE BANK) Starts Here
        {
            PrintTradeBankList2(); //Prints all the available Trade Banks and the list of Currencies supported by them respectively

            printf("\nEnter 14 for Operations Data\n\n");
        }

        else if (strcmp(Operation, "13") == 0) //Operation 13 (DIJKISTRA ON 2 CURRENCIES) Starts Here
        {
            char sourcecurrency[50];
            char destcurrency[50];

            printf("Enter Source Currency:");
            scanf("%s", sourcecurrency);

            printf("Enter DEstination Currency:");
            scanf("%s", destcurrency);

            // user inputs 2 currencies. We run dijkistra on all Banks and print the best conversion possible with the name of respective Trade Bank 

            printf("The shortest conversion rate between the two currencies is %d from Bank= %s \n", DijkstraOnBankList(sourcecurrency, destcurrency).mincost, DijkstraOnBankList(sourcecurrency, destcurrency).TradeBankName);

            printf("\nEnter 14 for Operations Data\n\n");
        }

        else if (strcmp(Operation, "14") == 0) //Operation 14 (SHOW USERDATA) Starts Here
        {
            UserData(); //Prints all the available commands
        }

        else if (strcmp(Operation, "15") == 0) //Operation 15 (EXIT) Starts Here
        {
            break; //exits the infinite loop
        }

        else    //If Invalid input entered we flag it  
        {
            printf("\nEnter A Valid Input\n");
            printf("\n");
            UserData();
            printf("\nEnter A Valid Input\n");
        }
    }

    return 0;
}
