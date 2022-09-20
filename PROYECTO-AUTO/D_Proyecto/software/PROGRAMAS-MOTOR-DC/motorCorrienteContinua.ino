/* simulacion de motor se corriente continua LD298 Y eSP32 */
//Declaracion de variables
int  valor = 0;
int motorAvance = 10; // pin I010
int motorRetroseso = 11; // pin 





//configuracion
void setup()
{
<<<<<<< HEAD:PROYECTO-AUTO/D_Proyecto/motorCorrienteContinua.ino
    pinMode(0,OUTPUT);

=======
    pinMode (0,OUTPUT);
  }
>>>>>>> 97ecbb179c5f8303056732ed10a7736a01810e50:PROYECTO-AUTO/D_Proyecto/software/PROGRAMAS-MOTOR-DC/motorCorrienteContinua.ino
//Bucle principal del programa
void loop()
{
    //giro en sentido antihorario subiendo velocidad
    digitalWrite(0,HIGH);
    analogWrite(motorRetroseso,0);
    for (valor = 0; valor <= 255; valor+=5 )
    {
        analogWrite(motorAvance, valor);
        delay (100);
    }
//giro en sentido antihorario bajando velocidad
    digitalWrite(0,LOW);
    for (valor = 255; valor >=0; valor-=5)
    {
        analogWrite(motorAvance, valor);
        delay(100);
}
//giro en sentido horario subiendo velocidad
    digitalWrite(0,HIGH);
    analogWrite(motorAvance, 0);
    for (valor = 0; valor <= 255; valor+=5 )
    {
        analogWrite(motorRetroseso, valor);
        delay(100);
    }
//giro en sentido antihorario bajando velocidad
    digitalWrite(0, LOW);
    for (valor = 255; valor >=0; valor-=5 )
    {
        analogWrite(motorRetroseso, valor);
        delay(100);
    }
}
