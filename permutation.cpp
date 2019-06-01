#include<iostream>
using namespace std;

void PrintPerm(char str[], int sPos){
    if (str[sPos]=='\0'){
        cout<<str<<endl;
        return;
    }
    for (int i=sPos;str[i]!='\0';i++){
        swap(str[sPos],str[i]);
        PrintPerm(str,sPos+1);
        swap(str[sPos],str[i]);
    }
}

void test(char str[], int sPos){
    for (int i=sPos;str[i]!='\0';i++){
        swap(str[sPos],str[i]);
        cout<<str<<endl;
        swap(str[sPos],str[i]);
    }
}

int main(){
    char str[]="abc";
    PrintPerm(str,0);
}

