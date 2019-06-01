#include <bits/stdc++.h> 
using namespace std; 
 int countHi(string str) {
    int count =0;
	  return countHi(str,count);
}

 int countHi(string str, int count) {
    if(str.length()==0)
        return count;
    else {
        if(string.endsWith("hi"))
            count++;

        return countHi(string.substring(0, string.length()-1) , count);
    }
}

int main()
{
string arr;
int count
cin>>arr;
	count=countHi(arr);
	cout<<count;
	return 0;
	
}
