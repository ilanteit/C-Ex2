#include <stdio.h>
#include "myBank.h"
int main(){

char operator;
int flag=1;
int account_number;

//FILE *input=fopen("input","r");
//if(input==null){
//   printf("File not found kill urself");
//    exit(1);
//}
//else
//{
//    getchar()
    while (flag==1){
    printf("Please choose a transaction type: \n O-Open Account \n B-Balance Inquiry \n D-Deposit \n W-Withdrawal \n C-Close Account \n I-Interest \n P-Print \n E-Exit \n");
    scanf(" %c", &operator);
   

    
    switch(operator){

    case 'O': ;
    int temp;
    double amount;
    printf("Please enter ammount to deposit: ");
    if(scanf("%lf", &amount)!=1){
    printf("Failed to read the amount \n\n");
    }
    else if(amount<=0){
    printf("Invalid amount \n\n");
    }
    if(amount >0){
    temp=TransactionO(amount);
     if(temp!=0){
    {
        
    printf("New account number is: %d \n\n", temp);
    }
     }
    }
    break;
    
    case 'B':
    printf("Please enter account number: ");
   if((scanf("%d", &account_number)!=1)) {
   printf("Failed to read the account number \n\n");
   }
    else if(!(account_number>900 && account_number<951)){
        printf("Invalid account number \n \n");
    }
   
    
    else if(TransactionB(account_number)>0){
    printf("The balance of account number %d is: %lf\n\n", account_number ,TransactionB(account_number));
    }
    break;
    
    case 'D': ;
    double money;
    printf("Please enter account number: ");
    if((scanf("%d", &account_number)!=1)) {
   printf("Failed to read the account number \n\n");
   }
    
    
   else{
    money=TransactionD(account_number);
    if(money==0){
         printf("Cannot deposit a negative amount \n\n");

    }
    
    else if(money>0)  printf ("The new balance of account number %d is: %0.2lf \n\n", account_number ,money) ; 
   
   }

    break;
    
    case 'W': ;
    double moneyy;
    printf("Please enter account number: ");
    if((scanf("%d", &account_number)!=1) ){
    printf("Failed to read the account number \n\n");
    }
    else{
    moneyy=TransactionW(account_number);
    if(moneyy>0){
        printf("The new balance is: %lf \n\n", moneyy) ;
    }
    }
    
    break;
    
    case 'C':
    printf("Please enter account number:");
    if((scanf("%d", &account_number)!=1) )
    printf("Failed to read the account number \n\n");

    else TransactionC(account_number);
    break;
    
    case 'I': ;
    double interest_rate;
    printf("Please enter interest rate: ");
    if(scanf("%lf", &interest_rate)==1 ){
        if(interest_rate <=0){
        printf("Invalid interest rate \n\n");
        }
    TransactionI(interest_rate);
    }
    else printf("Failed to read the interest rate\n\n");
    
    break;
    
    case'P':
    TransactionP();
    break;
    
    case 'E':
    TransactionE();
    flag=0;
    break;
    
    default:
    printf("invalid transaction type \n \n");
    break;
    
    
    }
    }

    return 0;
    
} 
//}
