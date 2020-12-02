#include <stdio.h>
#include "myBank.h"
#define BANK_ACCOUNTS 50
#define OFFSET 901

double Accounts[2][BANK_ACCOUNTS];
int main(){
char c=' ';
int x=0;
int account=0;
int check=0;
int interest=0;
double amount=0;
int check2=0;
while(1){
printf("\nPlease choose a transaction type:\n");
printf(" O-Open Account\n");
printf(" B-Balance Inquiry\n");
printf(" D-Deposit\n");
printf(" W-Withdrawal\n");
printf(" C-Close Account\n");
printf(" I-Interest\n");
printf(" P-Print\n");
printf(" E-Exit\n");
x=scanf(" %c",&c);
switch(c){
case 'O':
printf("Please enter amount for deposit: ");
check=scanf(" %lf",&amount);
if(check!=EOF&&check==1){
if(amount>=0){
OpenBankAccount(amount);
}else{
printf("Invalid Amount\n");
}
break;
}else{
printf("Failed to read the amount\n");
break;
}
case 'B':
printf("Please enter account number: ");
check=scanf("%d",&account);
if(check!=EOF&&check==1){
if(account<951&&account>900){
CheckingBalance(account);
}else{
printf("Invalid account number\n");
break;
}
break;
}else{
printf("Failed to read the account number\n");
break;
}
case 'D':
printf("Please enter account number: ");
check=scanf("%d",&account);
if(check==EOF || check!=1){
printf("Failed to read the account number\n");
break;
}
if(account>950 || account<OFFSET){
printf("Invalid account number\n");
break;
}
if(Accounts[1][account-OFFSET]==0){
printf("This account is closed\n");
break;
}
printf("Please enter the amount to deposit: ");
check2=scanf("%lf",&amount);
if(check2==EOF || check2!=1){
printf("Failed to read the amount\n");
break;
}
if(amount>=0){
Deposit(account,amount);
break;
}else{
printf("Cannot deposit a negative amount\n");
break;
}
case 'W':
printf("Please enter account number: ");
check=scanf("%d",&account);
if(check==EOF || check!=1){
printf("Failed to read the account number\n");
break;
}
if(account>950 || account < 901){
printf("Invalid account number\n");
break;
}
if(Accounts[1][account-OFFSET]==0){
printf("This account is closed\n");
break;
}
printf("Please enter the amount to withdraw: ");
check2=scanf("%lf",&amount);
if(check2==EOF || check2!=1){
printf("Failed to read the amount\n");
break;
}
Withdraw(account,amount);
break;
case 'C':
printf("Please enter account number: ");
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
printf("Please enter interest rate: ");
check=scanf("%d",&interest);
if(check!=EOF&&check==1){
if(interest<0){
printf("Invalid interest rate\n");
break;
}
AddInterest(interest);
break;
}else{
printf("Failed to read the interest rate\n");
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
if(x==EOF || c=='E'){
break;
}
}
return 0;
}

