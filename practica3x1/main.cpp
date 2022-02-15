#include <iostream>

using namespace std;
int numElem(char infor[]);
void infABin ( char infor[],char* ptr,int numElem);
void binAIfo (char bin[], char* ptr, int numElem );
int tipo(char* ptr, int desde, int hasta);
void encrip(char* ptr, int desde, int hasta, int tipo);
void encrip2(char* ptr, int desde, int hasta);
void desencrip2(char* ptr, int desde, int hasta);

int main()
{
    char infor[20]={' '}, bin[100]={' '},info[20]={' '};
    int numDelem=0;
    cin.getline(infor,20);
    numDelem=numElem(infor);
    infABin(infor,bin,numDelem);
    numDelem=numElem(bin);
    binAIfo(bin,info,numDelem);
    int x=0;
    for(int i=0; i<numDelem; i++){
        cout<<bin[i];
        x++;
        if(x==8){
            cout<<endl;
            x=0;

        }

    }
    cout<<endl;
    numDelem=numElem(info);
    for(int i=0; i<numDelem; i++){
        cout<<info[i];
    }
    cout<<endl;
    numDelem=tipo(bin,0,8);
    cout<<numDelem;
    cout<<endl;
    numDelem=numElem(bin);
    encrip2(bin,0,8);
    for(int i=0; i<numDelem; i++){
        cout<<bin[i];
        x++;
        if(x==8){
            cout<<endl;
            x=0;

        }
    }
    cout<<endl;
    desencrip2(bin,0,8);
    for(int i=0; i<numDelem; i++){
        cout<<bin[i];
        x++;
        if(x==8){
            cout<<endl;
            x=0;

        }
    }
    cout<<endl;
    encrip(bin,0,8,1);
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
void binAIfo (char bin[], char* ptr, int numElem ){
    int resul=0, resultado=0,ind=0,i=0;
    while (ind<numElem) {
        for(int i=ind; i<ind+8; i++){
            resultado=(resul*2)+(bin[i]-'0');
            resul=resultado;
        }
        ind+=8;
        *(ptr + i)= resultado;
        i++;
    }

}
int tipo(char* ptr, int desde, int hasta){
    int uno=0,cero=0,tipo=0;
    for(int i=desde; i<hasta; i++){
        if(*(ptr+i)=='1'){
            uno++;
        }
        else {
            cero++;
        }
    }
    if(cero==uno){
        tipo=1;
    }
    else if (cero>uno) {
        tipo=2;
    }
    else if(cero<uno){
        tipo=3;
    }
    return tipo;
}
void encrip2(char* ptr, int desde, int hasta){
    char aux=*(ptr + hasta);
    for(int i=hasta-1; i>=desde; i--){
        *(ptr + i)=*(ptr + (i-1));
    }
    *(ptr + desde)=aux;
}
void desencrip2(char* ptr, int desde, int hasta){
    char aux=*(ptr + desde);
    for(int i=desde; i<hasta-1; i++){
        *(ptr + i)=*(ptr + (i+1));
    }
    *(ptr + hasta-1)=aux;
}
void encrip(char* ptr, int desde, int hasta, int tipo){
    switch (tipo) {
    case 1:{
        for(int i=desde; i<hasta; i++){
            if(*(ptr + i)=='1'){
                *(ptr + i)='0';
            }
            else if(*(ptr + i)=='0') {
                *(ptr + i)='1';
            }
        }
        break;
    }
    case 2:{
        int i=0;
        while (desde<hasta) {
            i++;
            if(i==2){
                if(*(ptr + desde)=='1'){
                    *(ptr + desde)='0';
                    i=0;
                }
                else if(*(ptr + desde)=='0') {
                    *(ptr + desde)='1';
                    i=0;
                }
            }
            desde++;
        }
        break;
    }
    case 3:{
        int i=0;
        while (desde<hasta) {
            i++;
            if(i==3){
                if(*(ptr + desde)=='1'){
                    *(ptr + desde)='0';
                }
                else if(*(ptr + desde)=='0') {
                    *(ptr + desde)='1';
                }
                i=0;
            }
            desde++;
        }
        break;
    }
    }
}



