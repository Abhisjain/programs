#include<iostream>
using namespace std;
int coins[]={1,5,8};
int coincount=3;
int memo[1000];

int coinReq(int n){
    if (n==0) return 0;
    if (memo[n]!=-1) return memo[n];
    int minreq=INT_MAX;
    for (int i=0;i<coincount;i++){
        if (coins[i]<=n){
            int coinreq=1+coinReq(n-coins[i]);
            if (coinreq<minreq) minreq=coinreq;
        }
    }
    memo[n]=minreq;
    return minreq;
}

int main(){
    for (int i=0;i<1000;i++) memo[i]=-1;
    cout<<coinReq(800);
}

