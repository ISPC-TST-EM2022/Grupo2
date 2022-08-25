#include <iostream>
using namespace std;

int main (){
     float suma=0,num=-1,resultado;
     int contador =-1;

     while(num!=0){
         cout<<"[0]Para salir\n\n\n[+]Ingrese un numero: ";
         cin>>num;
         suma+=num;
         contador++;
     }
    resultado=suma/contador;
    cout<<"[+] La media arimetica es: "<<resultado<<endl;
     return 0;
 }
