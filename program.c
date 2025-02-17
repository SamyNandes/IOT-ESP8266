#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

WiFiServer wemos(80); // -> Inicia o servidor na porta 80
WiFiClient cliente; // Aceita conexões do ESP
String texto;

void setup() {
  pinMode(D8, OUTPUT);
  Serial.begin(115200);
  WiFi.begin("Robotica", "12345678iot"); // -> Conexão do esp com a rede local
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.printf(".");
    delay(500);
  } // -> Condição para saber se o esp realizou conexão com a rede
  Serial.println("WiFi IP: ");
  Serial.println(WiFi.localIP()); // -> IP da ESP
  wemos.begin(); // --> Inicializando o servidor 
}

void loop() {
  cliente = wemos.available(); // --> Aceita a entrada de clientes
  
  if (cliente) { // Verifica se há um cliente conectado
    Serial.println("Cliente conectado!");
    if(cliente){
        texto = cliente.readStringUntil('\n'); 
    }
    // Lê TODO o cabeçalho HTTP da requisição

    Serial.println("Requisição recebida:");
    Serial.println(texto);

    // Responde ao cliente com cabeçalho HTTP correto
    cliente.println("HTTP/1.1 200 OK");
    cliente.println("Content-Type: text/html");
    cliente.println("Connection: close");
    cliente.println();
    
    // Resposta padrão antes de processar os comandos
    cliente.println("<!DOCTYPE html>\n"
            "<head>\n"
            "</head>\n"
            "<body style=\"background-color: add8e6\">\n"
            "<div style=\"text-align: center;\">\n"
            "<form action=\"http://192.168.0.109/desl\">\n"
            "  <button style=\"color: red;\">Desligar</button>\n"
            "</form>\n"
            "<form action=\"http://192.168.0.109/liga\">\n"
            "  <button style=\"color: green;\">Ligar</button>\n"
            "</form>\n"
            "<form action=\"http://192.168.0.111/Apagar\">\n"
            "  <button style=\"color: red;\">Desligar do victor</button>\n"
            "</form>\n"
            "<form action=\"http://192.168.0.111/acender\">\n"
            "  <button style=\"color: green;\">Ligar do victor</button>\n"
            "</form>\n"
            "</div>\n"
            "</body>\n"
            "<html>\n");

    if(texto.indexOf("desl") != -1) {
      digitalWrite(D8, LOW);
      cliente.println("<h2>LED Desligado</h2> <div style=\" background-color: red; width:200px ; height: 15px \"></div>");
    } 

    if(texto.indexOf("liga") != -1) {
      digitalWrite(D8, HIGH);
      cliente.println("<h2>LED Ligado</h2> <div style=\" background-color: green; width:200px ; height: 15px \"></div>");
    }

    cliente.println("</body></HTML>"); // Fecha o HTML corretamente
    cliente.stop(); // Fecha a conexão
    Serial.println("Cliente desconectado.");
  }
}