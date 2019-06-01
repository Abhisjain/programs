#include<iostream>
using namespace std;

int memo[100];

int fibo(int n){
    if (n<=1) return n;
    if (memo[n]!=-1) return memo[n];
    int ans=fibo(n-1)+fibo(n-2);
    memo[n]=ans;
    return ans;
}
int main(){
    for (int i=0;i<100;i++) memo[i]=-1;
    cout<<fibo(45);
}

