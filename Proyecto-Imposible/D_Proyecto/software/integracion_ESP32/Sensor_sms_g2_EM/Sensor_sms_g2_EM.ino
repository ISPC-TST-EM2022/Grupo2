//CREADO POR grupo 2 Electronica Microcontrolada

// INCLUYO LIBRERIAS
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);/// EL 9 ES EL TXD TRANSMITE Y EL 10 RECIBE (del sim)
// DEFINO VARIABLES A USAR EN EL PROGRAMA
char msg;
char call;

const int ledPin = 13;
const int ledPin12 = 12;
const int movimiento = 4; 
const int ldr = 2;
int estado_sensor = 0;

void setup()

{// DEFINO QUE PINES VOY A USAR COMO ENTRADA Y CUALES COMO SALIDA
    pinMode(ldr, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(ledPin12, OUTPUT);
    pinMode(movimiento, INPUT);
// COMUNICACION SERIAL
  mySerial.begin(115200);   // Configuración de la velocidad en baudios del módulo GSM Setting the baud rate of GSM Module
  Serial.begin(9600);// Configuración de la velocidad en baudios de Serial Monitor (Arduino) Setting the baud rate of Serial Monitor (Arduino)
  Serial.println("LISTO PARA TRASMITIR");
}

void loop()
 // Leemos el valor del pin


{    estado_sensor = digitalRead(movimiento);

 
  if (estado_sensor == HIGH) {
      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin12, HIGH);
      digitalWrite(movimiento, HIGH);
      delay(700);
     

  mySerial.println("AT+CMGF=1");    //CONFIGURO PARA COMUNICACION CON SIM800L

  delay(1000);  //DELAY DE 1 SEGUNDO
  mySerial.println("AT+CMGS=\"+543513125960\"\r");
  delay(1000);  // 
  mySerial.println("movimiento detectado, se encienden luces");// CONFIGURO QUE SE ENVIE MENSAJE
  Serial.println("print serial, movimiento detectado, se encienden luces");  
  mySerial.println((char)26);// ASCII CODIGO CON  CTRL+Z
  delay(5000);// delay de 10 segundos

  mySerial.println("AT+CMGF=1");    //CONFIGURO GSM Module EN MODO TEXTO
  delay(1000);  // 
  mySerial.println("AT+CMGS=\"+543513125960\"\r");
  delay(1000);  // 
  mySerial.println("Se apagan las luces");// CONFIGURO QUE SE ENVIE MENSAJE 
  Serial.println("Se apagan las luces");  
  mySerial.println((char)26);// ASCII CODIGO DE  CTRL+Z
  delay(1000);  // 

      digitalWrite(ledPin, LOW);
      digitalWrite(movimiento, LOW);
  

      
  }
  else {
      digitalWrite(ledPin, LOW);
      digitalWrite(movimiento, LOW);
      digitalWrite(ledPin12, LOW);
     
      
  }
  }
