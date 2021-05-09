#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "priorityqueue.h"
#include "UserInterface.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>

int main()
{

    PtrToCurrencyNode CurrNode;
    CurrNode = CreateEmptyCurrList();

    while (1)
    {
        char Operation[50];
        scanf("%s", Operation);

        if (strcmp(Operation, "1") == 0)
        {
            char TradeBank[50];
            scanf("%s", TradeBank);

            AddTradeBank(TradeBank);
        }

        else if (strcmp(Operation, "2") == 0)
        {
            char TradeBank[50];
            scanf("%s", TradeBank);

            RemoveTradeBank(TradeBank);
        }

        else if (strcmp(Operation, "3") == 0)
        {
            char TradeBank[50];
            char Currency1[50];
            char Currency2[50];
            int ConversionRate, Commission;

            scanf("%s", TradeBank);

            scanf("%s", Currency1);

            scanf("%s", Currency2);

            scanf("%d", &ConversionRate);

            AddCurrencyExchange1(TradeBank, Currency1, Currency2, ConversionRate);
        }

        else if (strcmp(Operation, "4") == 0)
        {
            char TradeBank[50];
            char Currency1[50];
            char Currency2[50];

            scanf("%s", TradeBank);

            scanf("%s", Currency1);

            scanf("%s", Currency2);

            RemoveCurrencyExchange(TradeBank, Currency1, Currency2);
        }

        else if (strcmp(Operation, "5") == 0)
        {
            char TradeBank[50];
            char InputCurrency[50];

            scanf("%s", TradeBank);

            scanf("%s", InputCurrency);

            AddCurrencyToTradeBank(TradeBank, InputCurrency);
        }

        else if (strcmp(Operation, "6") == 0)
        {
            char Currency[50];
            char BankName[100];
            scanf("%s", BankName);
            scanf("%s", Currency);
            RemoveCurrencyFromTradeBank(BankName, Currency);
        }

        else if (strcmp(Operation, "7") == 0)
        {
            char BankName[50];

            scanf("%s", BankName);
            CycleCheckinTradeBank(BankName);
        }

        else if (strcmp(Operation, "8") == 0)
        {
            PrintTradeBankList2();
        }

        else if (strcmp(Operation, "9") == 0)
        {
            char sourcecurrency[50];
            char destcurrency[50];

            scanf("%s", sourcecurrency);

            scanf("%s", destcurrency);
            printf("The shortest conversion rate between the two currencies is %d from Bank= %s \n", DijkstraOnBankList(sourcecurrency, destcurrency).mincost, DijkstraOnBankList(sourcecurrency, destcurrency).TradeBankName);
            
        }

        else if (strcmp(Operation, "10") == 0)
        {
            break;
        }
    }

    return 0;
}
