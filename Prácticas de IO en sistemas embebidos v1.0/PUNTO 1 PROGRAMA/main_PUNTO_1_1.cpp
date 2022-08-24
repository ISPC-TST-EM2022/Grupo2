#include <Arduino.h>

int num1,num2, suma; // variables para almacenar los datos ingresados por el usuario y de la operacion suma 
void setup() 
{
  Serial.begin(9600);//inicializa la comunicacion serial
}

void loop() 
{ // Desarrollo del punto  1.    Pedir el ingreso de dos números por terminal y mostrar la suma por la pantalla.  
  Serial.print("Ingrese el primer numero: ");// imprimo un mensaje en la terminal 
  while (Serial.available()==0)  //Espera hasta que  ingrese un numero desde el terminal  
  {}
  
   num1=Serial.parseInt(); //leo el primer numero
   Serial.println(num1);   //imprimo el primer numero
   
  Serial.print("Ingrese el segundo numero: ");// imprimo un mensaje en la terminal 
  while (Serial.available()==0) //Espera hasta que  ingrese un numero desde el terminal
  {}
  
  num2=Serial.parseInt();  //leo el segundo numero
  Serial.println(num2);   //imprimo el segundo numero
  
  Serial.print("La suma es: ");// imprimo un mensaje en la terminal 
  suma = num1 + num2;          // realizo la operacion suma
  Serial.println(suma);        // imprimo un mensaje en la terminal con el resultado de la suma
  
  // Desarrollo del punto  2.    Preguntar Nombre, Apellido, Direccion y Celular en mensajes diferentes. Completar las respuestas.  
 
}

