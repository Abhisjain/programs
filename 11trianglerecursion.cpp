#include <bits/stdc++.h> 
using namespace std; 
void eleven (int n,int index)
{
	if (index=1)
	cout<<"1"<<endl;
    if(index>n)
    return;
    
	cout<<11*index<<endl;
	eleven(n,index+1);	
}
int main(){
eleven(5,1);	
}
