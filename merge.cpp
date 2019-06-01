#include<iostream>
using namespace std;

void Merge(int arr[], int sPos, int ePos){
    int mid=(sPos+ePos)/2;
    int temp[100];
    for (int i=sPos;i<=ePos;i++) temp[i]=arr[i];
    int i=sPos, j=mid+1, k=sPos;
    while (i<=mid && j<=ePos){
        if (temp[i]<temp[j]){
            arr[k]=temp[i];
            k++;i++;
        } else {
            arr[k]=temp[j];
            k++;j++;
        }
    }
    while (i<=mid){
        arr[k]=temp[i];
        k++;i++;
    }
    while (j<=ePos){
        arr[k]=temp[j];
        k++;j++;
    }
}

void MergeSort(int arr[], int sPos, int ePos){
    if (sPos>=ePos) return;
    int mid=(sPos+ePos)/2;
    MergeSort(arr,sPos,mid);
    MergeSort(arr,mid+1,ePos);
    Merge (arr, sPos,ePos);
}

int main(){
    int arr[]={6,1,7,3,9,10,4,5,2,8};
    int n=10;
    MergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<endl;
}

