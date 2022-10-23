//CREADO POR grupo 2 Electronica Microcontrolada


#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);/// EL 9 ES EL TXD TRANSMITE Y EL 10 RECIBE (del sim)
char msg;
char call;

const int ledPin = 13;//LAMPARA
const int ledPin12 = 12;//MODULO RELE
const int movimiento = 4;//MODULO PIR 
const int ldr = 2;//MODULO LDR
int estado_sensor = 0; //VARIABLE PIR
int estado_luz = 0; //VARIABLE LDR

void setup()

{
    pinMode(ldr, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(ledPin12, OUTPUT);
    pinMode(movimiento, INPUT);

  mySerial.begin(115200);   // Configuración de la velocidad en baudios del módulo GSM.
  Serial.begin(9600);// Configuración de la velocidad en baudios de Serial Monitor (Arduino).
  Serial.println("LISTO PARA TRASMITIR");//AVISO EN EL SERIAL QUE ESTA TODO OK
}

void loop()
 // Leemos el valor del pin

{    estado_sensor = digitalRead(movimiento);
     estado_luz = digitalRead(ldr);

 
  if (estado_sensor == HIGH && estado_luz == HIGH) //SI EL SENSOR PIR ESTA EN ALTO Y EL SENSOR LDR ESTA EN ALTO,PROCESA EL CODIGO
  {
      digitalWrite(ledPin, HIGH);//ENCIENDE LED
      digitalWrite(ledPin12, HIGH);//ENCIENDE RELÉ
      delay(700);
     

  mySerial.println("AT+CMGF=1");    //Setea modulo GSM en modo texto

  delay(1000);  // Espera de 1 segundo.
  mySerial.println("AT+CMGS=\"+543513125960\"\r");// comando para enviar el mensaje al numero telefonico agendado.
  delay(1000);  // Espera de 1 segundo.
  mySerial.println("movimiento detectado, se encienden luces");// Texto a enviar por SMS
  Serial.println("print serial, movimiento detectado, se encienden luces");//Texto a imprimir en el serial  
  mySerial.println((char)26);// codigo ASCII 
  delay(5000);// Espera de 5 segundos.

  mySerial.println("AT+CMGF=1"); //Setea modulo GSM en modo texto
  delay(1000);  // Espera de 1 segundo.
  mySerial.println("AT+CMGS=\"+543513125960\"\r");
  delay(1000);  // Espera de 1 segundo.
  mySerial.println("Se apagan las luces");// Texto a enviar por SMS
  Serial.println("Se apagan las luces"); //Texto a imprimir en el serial  
  mySerial.println((char)26);// codigo ASCII
  delay(1000);  // Delay of 1000 milli seconds or 1 second

  digitalWrite(ledPin, LOW);//Apaga led 
          
  }
  else {
      digitalWrite(ledPin, LOW);//Mantiene apagado led 
      digitalWrite(ledPin12, LOW);//Mantiene apagado relé 
     
      
  }
  }
