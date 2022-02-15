#include <iostream>

using namespace std;
int numElem(char infor[]);
void infABin ( char infor[],char* ptr,int numElem);

int main()
{
    char infor[20]={' '}, bin[100]={' '};
    int numDelem=0;
    cin.getline(infor,20);
    numDelem=numElem(infor);
    infABin(infor,bin,numDelem);
    numDelem=numElem(bin);
    int x=0;
    for(int i=0; i<numDelem; i++){
        cout<<bin[i];
        x++;
        if(x==8){
            cout<<endl;
            x=0;
        }
    }


    return 0;
}
int numElem(char infor[]){
    int i=0;
    while (infor[i]!='\0') {
        i++;
    }
    return i;
}
void infABin ( char infor[],char* ptr,int numElem){
    char carac=' ';
    int ind=0;
    for(int i=0; i<numElem; i++){
        carac=infor[i];
        ind+=8;
        for(int j=ind-1; j>=ind-8; j-- ){
            if(carac%2=='\0'){
                *(ptr + j)='0';
            }
            else {
                *(ptr + j)='1';
            }
            carac/=2;
        }
    }
}
