// Ejemplo prueba del ESP32-CAM - GRUPO 2 - 2022 - ELECTRONICA MICROCONTROLADA

#include "WifiCam.hpp" // Se incluyen las librerias a utilizar
#include <WiFi.h>

// Se define constante de tipo Char(caracter) [Reemplazar con los datos correspondientes a su red]
static const char *WIFI_SSID = "SSID del wifi";
static const char *WIFI_PASS = "Contraseña";

// Se define la resolucion inicial de la Camara

esp32cam::Resolution initialResolution;

// Declaramos un objeto de la libreria WebServer para poder acceder a sus funciones
// Y como parametro 80, que es el puerto estandar de todos los servicios WEB HTTP

WebServer server(80);

// funcion para configurar

void setup()
{ // Se inicia la comunicacion serial con un delay de 2000
    Serial.begin(115200);
    Serial.println();
    delay(2000);

    WiFi.persistent(false);
    WiFi.mode(WIFI_STA); // Modo de el wifi

    // configuro la conexio WiFi
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // Este if se explica de la siguiente forma:
    // "si la funcion WaitForConnectResult es distinto de WL_CONNECTED Entonces:"

    if (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("No se Pudo establecer la conexíon"); // Imprime un mensaje por pantalla
        delay(5000);
        ESP.restart(); // Se reinicia hasta conectar
    }
    Serial.println("WiFi conectado"); // Una vez conectado imprime por pantalla

    {
        using namespace esp32cam; // Esto es una forma de crear un bloque e incluir todas las funciones que esten dentro del mismo

        initialResolution = Resolution::find(1024, 768); // se declara la resolucíon inicial, que será de 1024x764px

        Config cfg; // Archivos cfg de Thinker
        cfg.setPins(pins::AiThinker);
        cfg.setResolution(initialResolution);
        cfg.setJpeg(80);

        bool ok = Camera.begin(cfg); // Esto es una condicion que valida el funcionamiento de la camara
        if (!ok) // si devuelve !ok entonces:
        {
            Serial.println("No fue posible iniciar la camara); // Imprime esto por pantalla
            delay(5000);
            ESP.restart();
        }
        Serial.println("Camara iniciada"); // de lo contrario, si es True, entonces imprime esto
    }

    Serial.println("Iniciando camara"); // Imprime un mensaje via HTPP
    Serial.print("http://");
    Serial.println(WiFi.localIP()); // toma la variable LocalIP para conocer la direccion para el envio de el mensaje

    addRequestHandlers(); // gestionará todas las solicitudes a ese URI
    server.begin(); // Indica al servidor que empiece a escuchar las conexiones entrantes.

}

//comprueba las peticiones provenientes de los clientes

void loop()
{
    server.handleClient();
}