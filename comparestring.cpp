
//recursion assignmnet question no 11
#include<iostream>
using namespace std;

bool print(char arr1[],int n ,char arr2[],int i)
{ 
    //int j=0;
	if(i>n||i<0||n<0) 
	return 0; 
	
		
	//cout<<endl<<"element found at index no = "<<n<<" "<<",true"<<endl;
	//return ;
	    
		print(arr1,n-1,arr2,i-1);
		
	if(arr1[n]==arr2[i])	
	  return 1;
	  else 
	  return 0;
	  
	//	j=j+1; 
	//	if(j==n)
	//	cout<<"true";
	
	
   
}

int  main()
{
	int n,m;
	cout<<"enter the no of elements for string 1  u want?"<<" ";
	cin>>n;
	char arr1[n];
	
	for(int i=0;i<n;i++)
	cin>>arr1[i];
	
	cout<<"enter the no of elements for string 2  u want?"<<" ";
	cin>>m;
	char arr2[m];
	
	for(int i=0;i<m;i++)
	cin>>arr2[i];
	
	bool c=print(arr1,n,arr2,m);
	cout<<c;
}
