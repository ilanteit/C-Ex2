// #ifndef _MYBANK_H_
// #define _MYBANK_H_
double bank[2][50]; //The first row is for account id and the second row is to know if the account is open or closed. 


int TransactionO(double amount);

double TransactionB(int account_number);

double TransactionD(int account_number);

double TransactionW(int account_number);

void TransactionC(int account_number);

void TransactionI(double interest_rate);

void TransactionP();

void TransactionE();
