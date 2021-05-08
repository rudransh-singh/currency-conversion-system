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

void UserData(){
    printf("1.Add Trade Bank\n");//good
    printf("2.Remove Trade Bank\n"); //good
    printf("3.Add Currency Exchange\n");    //good          //****
    printf("4.Remove Currency Exchange\n");     //good      //****
    printf("5.Add Currency To TradeBank\n");//good 
    printf("6.Search For Cycle\n");//remove
    printf("8.Delete Curency from Tradebank\n");//good
    printf("11.Print Trade Bank List\n");  //good           //****
    // printf("12.Print Trade Bank Graph\n"); //remove           //****
    printf("13.Dijkstra On Bank List\n"); //good            //****
    printf("14.Show UserData\n");//good
    printf("15.Exit\n");//good
}



int main(){
    
    PtrToCurrencyNode CurrNode;
    CurrNode = CreateEmptyCurrList();
    
    
    UserData(); 
    
    while(1){
        printf("Enter The Respective Number Of The Required Operation:");
        char Operation[50];scanf("%s",Operation);
        
        
        if(strcmp(Operation,"1")==0){
            char TradeBank[50];
            printf("Enter Name Of The Trade Bank:");
            scanf("%s",TradeBank);
            
            AddTradeBank(TradeBank);
            printf("\nEnter 14 for Operations Data\n\n");
        }
        
        
        
        
        else if(strcmp(Operation,"2")==0){
            char TradeBank[50];
            printf("Enter Name Of The Trade Bank:");
            scanf("%s",TradeBank);
            
            RemoveTradeBank(TradeBank);
            printf("\nEnter 14 To View Operations Data\n\n");
    
        }
        
        
        else if(strcmp(Operation,"3")==0){
            char TradeBank[50];
            char Currency1[50];
            char Currency2[50];
            int ConversionRate,Commission;
            
            printf("Enter Name Of The Trade Bank:");
            scanf("%s",TradeBank);
            
            printf("Enter Currency1:");
            scanf("%s",Currency1);
            
            printf("Enter Currency2:");
            scanf("%s",Currency2);
            
            printf("Enter Conversion Rate:");
            scanf("%d",&ConversionRate);
             
            
            AddCurrencyExchange1(TradeBank,Currency1,Currency2,ConversionRate);
            
            printf("\nEnter 14 To View Operations Data\n\n");
        }
        
        
        
        
        else if(strcmp(Operation,"4")==0){
            char TradeBank[50];
            char Currency1[50];
            char Currency2[50];
            
            printf("Enter Name Of The Trade Bank:");
            scanf("%s",TradeBank);
            
            printf("Enter The Source:");
            scanf("%s",Currency1);
            
            printf("Enter The Destiantion:");
            scanf("%s",Currency2);
            
            RemoveCurrencyExchange(TradeBank,Currency1,Currency2);
            
            printf("\nEnter 14 To View Operations Data\n\n");
        }
        
        
        
        else if(strcmp(Operation,"5")==0){
            char TradeBank[50];
            char InputCurrency[50];
            
            printf("Enter Name Of The Trade Bank:");
            scanf("%s",TradeBank);
            
            printf("Enter Currency:");
            scanf("%s",InputCurrency);
       
            
            AddCurrencyToTradeBank(TradeBank,InputCurrency);
            
            
            printf("\nEnter 14 To View Operations Data\n\n");
            
        }
        
        
        
        else if(strcmp(Operation,"6")==0){
            char BankName[50];
            
            printf("Enter BankName:");
            scanf("%s",BankName);
            CycleCheckinTradeBank(BankName); 
            printf("\nEnter 14 To View Operations Data\n\n");
        }
        
        
        
        // else if(strcmp(Operation,"7")==0){
        //     char Currency[50];
        //     int VertexId;
            
        //     printf("Enter Currency:");
        //     scanf("%s",Currency);
            
        //     printf("Enter VertexId:");
        //     scanf("%d",&VertexId);
            
        //     addcurrency(Currency,VertexId,CurrNode);
            
        //     printf("\nEnter 14 To View Operations Data\n\n");
            
        // }
        
        
        else if(strcmp(Operation,"8")==0){
            char Currency[50];
            char BankName[100];
            printf("Enter TradeBank Name:");
            scanf("%s",BankName);
            printf("Enter The Currency:");
            scanf("%s",Currency);
            RemoveCurrencyFromTradeBank(BankName,Currency);
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
        
        
        
        else if(strcmp(Operation,"11")==0){
            PrintTradeBankList2();
            
            printf("\nEnter 14 for Operations Data\n\n");
        }
        
        
        
        // else if(strcmp(Operation,"12")==0){
        //     //PrintTradeBankGraph();
            
        //     printf("\nEnter 14 for Operations Data\n\n");
        // }
        
        
        
        else if(strcmp(Operation,"13")==0){
            char sourcecurrency[50];
            char destcurrency[50];
            
            printf("Enter Source Currency:");
            scanf("%s",sourcecurrency);
            
            printf("Enter DEstination Currency:");
            scanf("%s",destcurrency);
            
            printf("The shortest conversion rate between the two currencies is %d from Bank= %s \n",DijkstraOnBankList(sourcecurrency,destcurrency).mincost, DijkstraOnBankList(sourcecurrency,destcurrency).TradeBankName);
            
            printf("\nEnter 14 for Operations Data\n\n");
        }
        
        
        else if(strcmp(Operation,"14")==0){
            UserData();
        }
        
        
        else if(strcmp(Operation,"15")==0){
            break;
        }
        
        else{
            printf("\nEnter A Valid Input\n");
            printf("\n");
            UserData();
            printf("\nEnter A Valid Input\n");

        }
        
    }    
    
    return 0;

}