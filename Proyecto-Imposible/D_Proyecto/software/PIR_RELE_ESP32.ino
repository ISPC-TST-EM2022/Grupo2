// PROGRAMACION DE SENSOR DE MOVIMIENTO PIR + RELE + LDR, PARA ACTIVAR LUZ - SEGUIMIENTO DE PERSONA //

int PIR = 14 ;          // PIN 14
int RELE = 25 ;         // PIN 25
int ESTADO = 0;         // Se establece en 0, ya que asumimos que el PIR no detecto Movimiento

void setup() {
  // put your setup code here, to run once:

  pinMode(PIR, INPUT);     // PIR como entrada en PIN 14
  pinMode(RELE, OUTPUT);   // RELE como salida en PIN 25
  delay(20000);            // Delay al inicio, para estabilizar PIR, al estar en el SETUP, se hace sólo la primera vez
}

void loop() {
  // put your main code here, to run repeatedly:

  ESTADO = digitalRead(PIR);
  if (ESTADO == HIGH)  {     // PIR en ALTA
    digitalWrite(RELE, LOW);   // RELE en BAJA
    delay(4000); 
    }                // Delay dado para espera de 4 seg del RELE - Se puede dejar mas tiempo, por ejemplo 30000 - 30 seg
  else {
    digitalWrite(RELE, HIGH);
  }  
}
