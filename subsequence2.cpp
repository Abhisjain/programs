#include<iostream>
using namespace std;

void SubSeq (char str[],int sPos, char out[], int oPos){
    if (str[sPos]=='\0'){
        out[oPos]='\0';
        cout<<out<<endl;
        return;
    }
    ///lets consider the first char in the output
    out[oPos]=str[sPos];
    SubSeq(str,sPos+1,out,oPos+1);
    ///Dont take first char in the output
    SubSeq(str,sPos+1,out,oPos);
}

int main(){
    char str[]="abc";
    char out[100];
    SubSeq(str,0,out,0);

}

