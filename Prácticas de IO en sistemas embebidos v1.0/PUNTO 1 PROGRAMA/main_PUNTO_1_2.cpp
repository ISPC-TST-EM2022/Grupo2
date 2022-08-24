#include <Arduino.h>
String NOMBRE ;
String APELLIDO ;
String DIRECCION;
String TELEFONO;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  Serial.println("¿CUAL ES SU MOBRE? ");
  while (Serial.available() == 0) {}  
  NOMBRE=Serial.readString();
  NOMBRE.trim();
  Serial.println(NOMBRE);
  Serial.println("¿CUAL ES SU APELLIDO?");
  while (Serial.available() == 0) {}
  APELLIDO=Serial.readString();
  APELLIDO.trim();
  Serial.println(APELLIDO);
  Serial.println("¿CUAL ES SU DIRECCION?");
  while (Serial.available() == 0) {}
  DIRECCION=Serial.readString();
  DIRECCION.trim();
  Serial.println(DIRECCION);
  Serial.println("¿CUAL ES SU TELEFONO?");
  while (Serial.available() == 0) {}
  TELEFONO=Serial.readString();
  TELEFONO.trim();
  Serial.println(TELEFONO);

  }