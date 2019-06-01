



#include<iostream>
using namespace std;

void PrintPattern(int n){
    if (n==0) return;
    PrintPattern(n-1);
    for (int i=1;i<=n;i++) cout<<"*"; cout<<endl;
   // PrintPattern(n-1);
}


int main(){
    PrintPattern(4);
}





















































































