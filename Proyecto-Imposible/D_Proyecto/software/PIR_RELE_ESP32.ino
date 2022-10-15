// PROGRAMACION DE SENSOR DE MOVIMIENTO PIR + RELE + LDR, PARA ACTIVAR LUZ - SEGUIMIENTO DE PERSONA //

int PIR = 14 ;          // PIN 14
int RELE = 25 ;         // PIN 25
int ESTADO = 0;         // Se establece en 0, ya que asumimos que el PIR no detecto Movimiento

void setup() {
  // Se coloca el codigo que corre una vez, en SETUP

  pinMode(PIR, INPUT);     // PIR como entrada en PIN 14
  pinMode(RELE, OUTPUT);   // RELE como salida en PIN 25
  delay(20000);            // Delay al inicio, para estabilizar PIR, al estar en el SETUP, se hace sólo la primera vez
  Serial.begin(9600);       // Se habilita el Serial a 9600
}

void loop() {
  // Se coloca código que corre repetidamente, en LOOP

  ESTADO = digitalRead(PIR);
  if (ESTADO == HIGH)  {     // PIR en ALTA
    digitalWrite(RELE, LOW);   // RELE en BAJA
    Serial.println("Deteccion de Movimiento");   // Cuando se activa PIR, devuelve mensaje en consola serial
    delay(4000);  // Se da un Delay de 4 segundos
     
    }                // Delay dado para espera de 4 seg del RELE - Se puede dejar mas tiempo, por ejemplo 30000 - 30 seg
  else {
    digitalWrite(RELE, HIGH);  // RELE en ALTA
    Serial.println("Fin de Movimiento");  // Cuando se pasiva PIR, devuelve mensaje en consola serial
    
  }  
}
