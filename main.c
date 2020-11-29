#include <stdio.h>
#include "myBank.h"
#define BANK_ACCOUNTS 50

double Accounts[2][BANK_ACCOUNTS];
int main(){
char c=' ';
int x=0;
int account=0;
int check=0;
double amount=0;
int check2=0;
while(1){
printf("Please choose a transaction type:\n");
printf("O-Open Account\n");
printf("B-Balance Inquiry\n");
printf("D-Deposit\n");
printf("W-Withdrawal\n");
printf("C-Close Account\n");
printf("I-Interest\n");
printf("P-Print\n");
printf("E-Exit\n");
x=scanf(" %c",&c);
switch(c){
case 'O':
printf("Please enter amount for deposit: \n");
check=scanf("%lf",&amount);
if(check!=EOF&&check==1){
if(amount>=0){
OpenBankAccount(amount);
}else{
printf("Deposit amount cannot be negative\n");
}
break;
}else{
printf("Failed to read the amount\n");
break;
}
case 'B':
printf("Please enter account number: \n");
check=scanf("%d",&account);
if(check!=EOF&&check==1){
if(account<951&&account>900){
CheckingBalance(account);
}else{
printf("Bank accounts values must be between 901 to 950\n");
break;
}
break;
}else{
printf("Failed to read the account number\n");
break;
}
case 'D':
printf("Please enter account number: \n");
check=scanf("%d",&account);
if(check==EOF || check!=1){
printf("Failed to read account number\n");
break;
}
if(account>950 || account<901){
printf("Bank accounts values must be between 901 to 950\n");
break;
}
printf("Please enter amount for deposit: \n");
check2=scanf("%lf",&amount);
if(check2==EOF || check2!=1){
printf("Failed to read deposit amount\n");
break;
}
if(amount>=0){
Deposit(account,amount);
break;
}else{
printf("Deposit amount cannot be negative\n");
break;
}
case 'W':
printf("Please enter account number: \n");
check=scanf("%d",&account);
if(check==EOF || check!=1){
printf("Failed to read account number\n");
break;
}
if(account>950 || account < 901){
printf("Bank accounts values must be between 901 to 950\n");
break;
}
printf("Please enter amount for withdrawal: \n");
check2=scanf("%lf",&amount);
if(check2==EOF || check2!=1){
printf("Failed to read withdrawal amount\n");
break;
}
if(amount>=0){
Withdraw(account,amount);
}else{
printf("Withdrawal amount cannot be negative");
}
break;
case 'C':
printf("Please enter account number: \n");
check=scanf("%d",&account);
if(check!=EOF&&check==1){
if(account<951 && account>900){
CloseBankAccount(account);
}else{
printf("Bank accounts values must be between 901 to 950\n");
}
break;
}else{
printf("Failed to read the account number\n");
break;
}
case 'I':
printf("Please enter amount for interest: \n");
check=scanf("%lf",&amount);
if(check!=EOF&&check==1){
AddInterest(amount);
break;
}else{
printf("Failed to read the amount of interest\n");
break;
}
case 'P':
PrintingAccounts();
break;
case 'E':
ClosingAllAccounts();
break;
default: 
printf("Invalid transaction type\n");
break;
}
if(x==EOF || c=='E') break;
}
return 0;
}

