#include <iostream>
#include <fstream>
using namespace std;
int numElem(char infor[]);
void binAIfo (char bin[], char* ptr, int numElem );
int tipo(char* ptr, int desde, int hasta);
void encrip(char* ptr, int desde, int hasta, int tipo);
void desencrip2(char* ptr, int desde, int hasta);
int main()
{
    char infBin[1000]={' '},inf[200];
    string nombinf=" ",nombin=" ";
    int format=0,numelem=0;
    ofstream archivoEscritura;
    ifstream archivoLectura;
    cout<<"********BIENVENIDO*********"<<endl;
    cout<<"********CERRADURA*********"<<endl;
    cout<<"Con gusto podemos encriptar por ti"<<endl;
    cout<<"Ingresa el nombre del archivo o la direcion del mismo:"<<endl;
    cin>>nombinf;
    try {

        archivoLectura.open(nombinf);
        if(!archivoLectura.is_open())
            throw '1';

        int i=0;
        while (archivoLectura.good())
           {
            char temp=archivoLectura.get();
           if( archivoLectura.good())
               infBin[i]=temp;
           i++;
        }
        archivoLectura.close();

    }  catch (char c) {

        if(c=='1')
            cout<<"Se produjo un error con el archivo de lectura"<<endl;
        else
            cout<<"Se produjo un error inesperado"<<endl;
    }
    cout<<"****EXPLICACION****"<<endl;
    cout<<"*Tienes a disposicion 2 formas de desencriptar"<<endl;
    cout<<"Debes de indicarnos la que usaste para encriptar"<<endl;
    cout<<"Por la seguridad de tu informacion no podemos darte a conocer las formas de desencriptar"<<endl;
    cout<<"*Para poder desencriptar debe darnos a conocer el numero entero llamado <<SEMILLA>> que utilizaste para encriptar"<<endl;
    cout<<"Este se encargara de ayudarnos a desencriptar por ti"<<endl;
    cout<<endl<<endl<<endl;
    cout<<"Formato 1"<<endl;
    cout<<"Escribe----->1"<<endl;
    cout<<"Formato 2"<<endl;
    cout<<"Escribe----->2"<<endl;
    cin>>format;
    switch (format) {

    case 1:{
        int semillaf1=0,modo=1,i=0,numbin=0;
        string nombin1=" ";
        cout<<"Ingresa tu semilla"<<endl;
        cout<<"¡Recuerdala!"<<endl;
        cin>>semillaf1;
        numbin=numElem(infBin);
        while (i<numbin) {
            encrip(infBin,i,i+semillaf1,modo);
            modo=tipo(infBin,i,i+semillaf1);
            i+=semillaf1;

        }

        cout<<"Ingresa el nombre del archivo donde deseas guardar tu informacion desencriptada"<<endl;
        cout<<"Puedes ingresar el nombre o la direcion del archivo.txt"<<endl;
        cout<<"Recuerda si no tienes archivo crearemos uno por ti. Dinos el nombre?"<<endl;
        cin>>nombin1;
        binAIfo(infBin,inf,numbin);
        try {
            //Inicia la escritura
            archivoEscritura.open(nombin1);
            if(!archivoEscritura.is_open())
                throw '1';
            archivoEscritura << inf;
            archivoEscritura.close();
        }catch (char c) {
            if(c=='1')
                cout<<"Se produjo un error con el archivo de escritura"<<endl;
        }
    }
    case 2:{
        int semillaf2=0,numbin;
        string nombin=" ";
        cout<<"Ingresa tu semilla"<<endl;
        cout<<"¡Recuerdala!"<<endl;
        cin>>semillaf2;
        numbin=numElem(infBin);
        int i=0;
        while (i<numbin) {
            desencrip2(infBin,i,i+semillaf2);
            i+=semillaf2;
        }
        binAIfo(infBin,inf,numbin);
        cout<<"Ingresa el nombre del archivo donde deseas guardar tu informacion encriptada"<<endl;
        cout<<"Puedes ingresar el nombre o la direcion del archivo.txt"<<endl;
        cout<<"Recuerda si no tienes archivo crearemos uno por ti. Dinos el nombre?"<<endl;
        cin>>nombin;
        try {
            //Inicia la escritura
            archivoEscritura.open(nombin);
            if(!archivoEscritura.is_open())
                throw '1';
            archivoEscritura << inf;
            archivoEscritura.close();
        }catch (char c) {
            if(c=='1')
                cout<<"Se produjo un error con el archivo de escritura"<<endl;
        }
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
void desencrip2(char* ptr, int desde, int hasta){
    char aux=*(ptr + desde);
    for(int i=desde; i<hasta-1; i++){
        *(ptr + i)=*(ptr + (i+1));
    }
    *(ptr + hasta-1)=aux;
}
