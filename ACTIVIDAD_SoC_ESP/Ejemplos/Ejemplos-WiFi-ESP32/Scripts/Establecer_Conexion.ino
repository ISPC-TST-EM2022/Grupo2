#include <WiFi.h>

const char* ssid = "Wokwi-GUEST"; //constante de caracter con el nombre de la red a conectarse
const char* pass = ""; // constante de caracter con la contraseña de la red

void setup(){
  Serial.begin(115200); //Abre un Puerto serie y especifica la velocidad de transmisión
  WiFi.begin(ssid, pass); 
  while(WiFi.status() != WL_CONNECTED){ //un ciclo while donde si el estado de la red es diferente a conectado imprime un punto 
    delay(100);
    Serial.println(".");
  }
  Serial.println("[+] Conexion Establecida");
  Serial.println(WiFi.localIP()); //Imprime la ip local asignada
}

void loop(){

}