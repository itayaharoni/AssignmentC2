#include <stdio.h>
#include "myBank.h"
#ifndef N
#define N 50
#define OFFSET 901
extern double Accounts[2][N];
void OpenBankAccount(double x){
int i=0;
for(i=0; i<N; ++i){
if(Accounts[1][i]==0){
Accounts[0][i]=x;
Accounts[1][i]=1;
break;
}
}
if(i!=N+1){
printf("New account number is: %d \n",(i+OFFSET));
}else{
printf("There is no available space for a new account.\n");
}
}
void CheckingBalance(int x){
if(Accounts[1][x-OFFSET]!=0){
printf("The balance of account number %d is: %.2lf\n",x,Accounts[0][x-OFFSET]);
}else{
printf("This account is closed\n");
}
}
void Deposit(int x,double y){
if(Accounts[1][x-OFFSET]!=0){
Accounts[0][x-OFFSET]+=y;
printf("The new balance is: %.2lf\n",Accounts[0][x-OFFSET]);
}else{
printf("This account is closed\n");
}
}
void Withdraw(int x, double y){
if(Accounts[1][x-OFFSET]!=0){
if(Accounts[0][x-OFFSET]-y>=0){
Accounts[0][x-OFFSET]-=y;
printf("The new balance is: %.2lf\n",Accounts[0][x-OFFSET]);
}else{
printf("Cannot withdraw more than the balance\n");
}
}else{
printf("This account is closed\n");
}
}
void CloseBankAccount(int x){
if(Accounts[1][x-OFFSET]!=0){
Accounts[1][x-OFFSET]=0;
printf("Closed account number %d\n",x);
}else{
printf("This account is already closed\n");
}
}
void AddInterest(int x){
for(int i=0; i<N; ++i){
if(Accounts[1][i]!=0){
Accounts[0][i]+=(Accounts[0][i]*x)/100;
}
}
}
void PrintingAccounts(){
for(int i=0; i<N; ++i){
if(Accounts[1][i]!=0){
printf("The balance of account number %d is: %.2lf\n",(i+OFFSET),Accounts[0][i]);
}
}
}
void ClosingAllAccounts(){
for(int i=0; i<N; ++i){
Accounts[1][i]=0;
}
}
#endif
