#include <bits/stdc++.h> 
using namespace std; 

int print (int n){
	
if (n<=0) return 0;
    int ans=print(n-1);
    return ans+n;
}


int main(){
	cout<<print(4);
}

