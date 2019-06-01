#include <bits/stdc++.h> 
using namespace std; 

class Vectors{
	
	private:
		int * arr;
		int TotalSize;
		int index;
	public:
			Vectors(int s=4){
				TotalSize=s;
				arr=new int [TotalSize];
				index=0;
			}
	void push(int d){
		if(index==TotalSize){//increase the arraysize
		TotalSize*=2;
		int *oldarr=arr;
		arr=new int [TotalSize];
		for(int i=0;i<index;i++)
		arr[i]=oldarr[i];
		delete [] oldarr;
		}
	arr[index]=d;
	index++;}
	void print(){
		for (int i=0;i<index;i++)
	   cout<<arr[i]<<" ";
	   cout<<endl;
	   }
	int Top(){
		if(index==0)return -1;
		return arr[index-1];
		
	}
	void pop(){
		if(index==0)return;
		index--;
		
	}
	bool isEmpty(){
		if(index==0)return true;
		else
		return false;
		//return(index==0);
	}
		int ValueatIndex(int ind){
			return arr[ind];
			
		}
		int Size(){
			return index;
		}
		int operator[](int ind){
			return arr[ind];
		}
	

};

int main(){
	
	Vectors v;
	v.push(1);
	v.push(2);
	v.push(3);
	v.push(3);
	v.push(2);	
	v.push(3);
	v.print();
	cout<<v.Top()<<endl;
	v.pop();
	v[2]=44;
	for(int i=0;i<v.Size();i++)cout<<v[i]<<" ";
	
	cout<<endl;
	
}
