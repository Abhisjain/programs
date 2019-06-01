
//recursion assignmnet question no 11
#include<iostream>
using namespace std;

int print(int arr[],int n ,int sum)
{ 
    //int j=0;
	if(n=0) 
	return sum;
	if (n<0) 
	return 0;
		
	//cout<<endl<<"element found at index no = "<<n<<" "<<",true"<<endl;
	//return ;
	    
    print(arr,n-1,sum);
		
	sum=sum+arr[n-1];
	  cout<<sum<<endl;
	  
	//	j=j+1; 
	//	if(j==n)
	//	cout<<"true";
	
	
   
}

int  main()
{
	int n,m;
	cout<<"enter the no of elements u want?"<<" ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	
	int c=print(arr,n,0);
	cout<<c;
}
