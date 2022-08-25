// Práctica encender un LED y cambiar su intensidad

const int LED = 9;
int VALOR;
void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
}
void loop()
{

    Serial.println("[+]Ingrese un valor de 0 a 255 ");
    while (Serial.available() == 0)
    {
    } // wait for data available
    VALOR = Serial.parseInt();
    if (VALOR > 0 && VALOR < 255)
    {
        Serial.println(VALOR);
        analogWrite(LED, VALOR);
        delay(5);
    }
    else
    {
        Serial.println("[-]Valor fuera de rango, vuelva a intentarlo");
    }
}