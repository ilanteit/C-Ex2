#include "myBank.h"
#include <stdio.h>
int numofAccount=0;
int id=900;


int TransactionO(double amount){
if(numofAccount<50 && amount >0){
    bank[0][numofAccount]=id+1;
    bank[1][numofAccount]=amount;
    id++;
    numofAccount++;
    return id;

}
    else {
         printf("The bank is full \n\n");
 return 0;
    }

}


double TransactionB(int account_number){

    double money;
 
        if(bank[0][account_number - 901]==account_number){
            
                money= bank[1][account_number - 901];
                return money;
            }
            else { printf("This account is closed \n\n");
            return 0;
            }
        }
   
double TransactionD(int account_number){
  
  if(!(account_number>900 && account_number<951)){
        printf("Invalid account number \n \n");
        return -1;
    } 
    double money=0;
    
    if(bank[0][account_number - 901]==account_number){
        printf("Please enter amount to deposit: ");
       if(scanf("%lf", &money)==1){
           if(money<=0){
               return 0;
           }
    bank[1][account_number - 901]+=money;
    return bank[1][account_number - 901];
       }
       else { printf("Failed to read the amount \n\n");
       return -2;
       }
    }
    
            else 
            {
                 printf("This account is closed \n\n");
            return -1;
            }
        }
      
    
  
double TransactionW(int account_number){
   
double money;
if(!(account_number>900 && account_number<951)){
        printf("Invalid account number \n \n");
        return -1;
    } 
if(bank[0][account_number - 901]==account_number){
      printf("Please enter amount to withdraw: ");
     if(scanf("%lf", &money)==1){
         if(money<=0){
          printf("Cannot withdraw negative amount \n\n");
          return 0;
         }
          if(money>bank[1][account_number - 901]){
                printf("Cannot withdraw more than the balance \n");
                return 0;
          }
                  bank[1][account_number - 901]-=money;
                  return bank[1][account_number - 901];
     }
      else {
          printf("Failed to read the amount \n\n");
      return -1;
      }

}
   printf("This account is closed \n\n");
  return 0;
}             
         
void TransactionC(int account_number){
    if(!(account_number>900 && account_number<951)){
        printf("Invalid account number \n \n");
        
    } 
    
    else if(bank[0][account_number - 901]==account_number){
        bank[0][account_number - 901]=0;
        bank[1][account_number - 901]=0;
        printf(" Closed account number %d \n\n", account_number);
        numofAccount--;
        id--;
    }
    else if(account_number>900 && account_number<951){
       printf("This account is already closed \n\n"); 
    }
}
void TransactionI(double interest_rate){
    double balance;
    
        for(int i=0;i<numofAccount;i++){
            balance=bank[1][i];
            bank[1][i]=balance*(interest_rate/100)+balance;
        

    }
}
void TransactionP(){
    for(int i=0;i<numofAccount;i++){
  
        printf("The balance of account number %d is: %0.2lf\n\n", i+901, bank[1][i]);
    }
}
   
void TransactionE(){
    for(int i=0;i<numofAccount;i++){
         bank[0][i]=0;
         bank[1][i]=0;
         id--;
         numofAccount--;
    }
}

