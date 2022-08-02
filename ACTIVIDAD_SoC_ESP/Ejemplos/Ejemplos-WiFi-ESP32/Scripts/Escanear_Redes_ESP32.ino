#include <WiFi.h> //Incluimos la libreria WiFi

void setup(){
  Serial.begin(115200); // Abre un Puerto serie y especifica la velocidad de transmisión
  WiFi.mode(WIFI_STA);

}

void loop(){
  Serial.println("Escaneando Wifi..."); //Imprime en pantalla el mensaje
  int networks = WiFi.scanNetworks(); //Escanea las diferentes redes
  
  if(networks == 0){
    Serial.println("No se encontraron redes"); // Si la cantidad de redes es igual a 0 imprime <---

  }else{
    Serial.println(networks);
    Serial.println("Redes Encontradas!"); //Caso contrario imprime por pantalla <--
    for(int i = 0; i < networks; i++){ //contador
      Serial.println("Wifi : ");
      Serial.println(i+1);
      Serial.println(WiFi.SSID(i)); //imprime el SSID de la red encontrada
      Serial.println(WiFi.RSSI(i)); //imprime la señal de la red encontrada
      delay(10); // Un delay de 10 segundos
    }
  }
}
