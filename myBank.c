#include <stdio.h>
#include "myBank.h"
#ifndef N
#define N 50
void OpenBankAccount(double x){
extern double Accounts[2][N];
int i=0;
for(i=0; i<50; ++i){
if(Accounts[0][i]==0){
Accounts[0][i]=x;
Accounts[1][i]=1;
break;
}
}
if(i!=51){
printf("New account number is: %d\n",(i+901));
}else{
printf("There is no available space for a new account.\n");
}
}
void CheckingBalance(int x){
extern double Accounts[2][N];
if(Accounts[1][x-901]!=0){
printf("The balace of account number %d is: %.2lf\n",x,Accounts[0][x-901]);
}else{
printf("This account is closed\n");
}
}
void Deposit(int x,double y){
extern double Accounts[2][50];
if(Accounts[1][x-901]!=0){
Accounts[0][x-901]+=y;
printf("The balace of account number %d is: %.2lf\n",x,Accounts[0][x-901]);
}else{
printf("This account is closed\n");
}
}
void Withdraw(int x, double y){
extern double Accounts[2][N];
if(Accounts[1][x-901]!=0){
if(Accounts[0][x-901]-y>=0){
Accounts[0][x-901]-=y;
printf("The new balance is: %.2lf\n",Accounts[0][x-901]);
}else{
printf("cannot withdraw more than the balance\n");
}
}else{
printf("This account is closed\n");
}
}
void CloseBankAccount(int x){
extern double Accounts[2][N];
if(Accounts[1][x-901]!=0){
Accounts[1][x-901]=0;
printf("Account number %d is closed\n",x);
}else{
printf("Account number %d is not open\n",x);
}
}
void AddInterest(double x){
extern double Accounts[2][N];
for(int i=0; i<50; ++i){
if(Accounts[1][i]!=0){
Accounts[0][i]=Accounts[0][i]+Accounts[0][i]*(x/100);
}
}
}
void PrintingAccounts(){
extern double Accounts[2][N];
for(int i=0; i<50; ++i){
if(Accounts[1][i]!=0){
printf("The balance of account %d is: %.2lf\n",(i+901),Accounts[0][i]);
}
}
}
void ClosingAllAccounts(){
extern double Accounts[2][N];
for(int i=0; i<50; ++i){
Accounts[1][i]=0;
}
}
#endif
