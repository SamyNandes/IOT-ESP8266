#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <stdio.h>
#include <string.h>

WiFiClient cliente; // --> Cria um objeto do tipo WiFiClient, com o nome "cliente". O objetivo desse objeto é fazer requisições e receber dados de um servidor.
WiFiServer server(80); // --> Cria um objeto do tipo WiFiServer, com o nome "server". O objetivo desse objeto é transformar nossa ESP em um servidor.

String texto;
int number = 0;

void setup() {
pinMode(D4, OUTPUT);
pinMode(D8, OUTPUT);
pinMode(D9, OUTPUT);
for(int i = 9; i<= 9; i++){
  digitalWrite(i, HIGH);
}
/* Taxa de transmissão entre o USB e a ESP */
Serial.begin(9600);


/* Credencias da rede */
const char nomeRede[] = "Robotica";
const char senhaRede[] = "12345678iot";

/* A ESP se conecta a rede WiFi, usando o método "begin" proveniente do objeto WiFi */
WiFi.begin(nomeRede, senhaRede);

/* Estrutura condição, para verificarmos se a ESP se conectou a rede wifi */
while(WiFi.status() != WL_CONNECTED) {
  Serial.print(".");
  delay(500);
}

Serial.println("Conectado a rede: " + (String)WiFi.SSID()); // --> Imprime o nome da rede, com o método "SSID" do objeto WiFI
Serial.println(WiFi.localIP()); // --> Pega o IP da Wemos e imprime

server.begin();

}

void loop() {
    cliente = server.accept();
  if(cliente){
    texto = cliente.readStringUntil('\n');
    Serial.println("Cliente conectado");
  }
cliente.print("<!DOCTYPE html>\r\n"
"<html lang=\"en\">\r\n"
"<head>\r\n"
"    <meta charset=\"UTF-8\">\r\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\r\n"
"    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">\r\n"
"<link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>\r\n"
"<link href=\"https://fonts.googleapis.com/css2?family=Poppins:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap\" rel=\"stylesheet\">\r\n"
"    <title>Change the color!</title>\r\n"
"    <style>\r\n"
"        .poppins-regular {\r\n"
"                font-family: \"Poppins\", serif;\r\n"
"                font-weight: 400;\r\n"
"                font-style: normal;\r\n"
"            }\r\n"
"        *{\r\n"
"            font-family: \"Poppins\", serif;\r\n"
"          padding: 0px;\r\n"
"          margin: 0px;\r\n"
"        }\r\n"
"        html{\r\n"
"            height: 100%;\r\n"
"        }\r\n"
"        body{\r\n"
"            height: 100%;\r\n"
"        }\r\n"
"        form{\r\n"
"            display: flex;\r\n"
"            flex-direction: column;\r\n"
"        }\r\n"
"        .box{\r\n"
"            width: 18rem;\r\n"
"            padding: 80px 0px;\r\n"
"            border-radius: 10px;\r\n"
"            box-shadow: rgba(0, 0, 0, 0.3) 0px 19px 38px, rgba(0, 0, 0, 0.22) 0px 15px 12px;\r\n"
"            background-color: #B0C4B1;\r\n"
"            justify-content: center;\r\n"
"            align-items: center;\r\n"
"            flex-direction: column;\r\n"
"            display: flex;\r\n"
"        }\r\n"
"        select{\r\n"
"            margin: 15px;\r\n"
"        }\r\n"
"        #nav{\r\n"
"            box-shadow: rgba(50, 50, 93, 0.25) 0px 13px 27px -5px, rgba(0, 0, 0, 0.3) 0px 8px 16px -8px;\r\n"
"            border-radius: 10px;\r\n"
"            background-color: #EDAFB8;\r\n"
"            text-align: center;\r\n"
"            font-size: 25px;\r\n"
"        }\r\n"
"        a, a:link, a:visited, a:active{\r\n"
"            color: black;\r\n"
"            text-decoration: none;\r\n"
"        }\r\n"
"        #container{\r\n"
"            background-color: #f7e1d7ad;\r\n"
"            width: 100%;\r\n"
"            height: 95%;\r\n"
"            display: flex;\r\n"
"            align-items: center;\r\n"
"            justify-content: center;\r\n"
"        }\r\n"
"        button{\r\n"
"            margin: 5px 0px;\r\n"
"        }\r\n"
"        #botoes{\r\n"
"            display: flex;\r\n"
"        }\r\n"
"    </style>\r\n"
"</head>\r\n"
"<body>\r\n"
"    <div id=\"nav\">\r\n"
"        <a href=\"https://sp.senai.br/unidade/guarulhos/\">SENAI HERMENGILDO CAMPOS DE ALMEIDA - 122 ❤️</a>\r\n"
"    </div>\r\n"
"    <div id=\"container\">\r\n"
"        <div class=\"box\">\r\n"
"            <form id=\"colorForm\" action=\"\" method=\"GET\">\r\n"
"                <h2>Selecione sua cor!</h2>\r\n"
"                <select name=\"cores\" id=\"cores\">\r\n"
"                    <option value=\"Vermelho\">🔴 Vermelho</option>\r\n"
"                    <option value=\"Verde\">🟢 Verde</option>\r\n"
"                    <option value=\"Azul\">🔵 Azul</option>\r\n"
"                    <option value=\"Ciano\">🔵 Ciano</option>\r\n"
"                    <option value=\"Amarelo\">🟡 Amarelo</option>\r\n"
"                    <option value=\"Magenta\">🟣 Magenta</option>\r\n"
"                </select>\r\n"
"<h2>Quantidade: </h2>\r\n"
"                <select name=\"numbers\" id=\"numeros\">\r\n"
"                    <option value=\"1\">Um</option>\r\n"
"                    <option value=\"2\">Dois</option>\r\n"
"                    <option value=\"3\">Três</option>\r\n"
"                    <option value=\"4\">Quatro</option>\r\n"
"                    <option value=\"5\">Cinco</option>\r\n"
"                    <option value=\"6\">Seis</option>\r\n"
"                    <option value=\"7\">Sete</option>\r\n"
"                    <option value=\"8\">Oito</option>\r\n"
"                    <option value=\"9\">Nove</option>\r\n"
"                    <option value=\"10\">Dez</option>\r\n"
"                </select>\r\n"
"                <button onclick=\"getColor()\">\r\n"
"                    Enviar dados!\r\n"
"                </button>\r\n"
"        </div>\r\n"
"    </div>\r\n"
"    \r\n"
"</body>\r\n"
"<script>\r\n"
"    var qntd = 0;\r\n"
"\r\n"
"    // Função que envia a cor e a quantidade para a URL\r\n"
"    function getColor() {\r\n"
"        var valor = document.getElementById(\"cores\").value; // Pega a cor selecionada\r\n"
"        var url = \"http://192.168.0.108/liga\" + valor + \"?qntd=\" + qntd + \"&cor=\" + valor; // URL com parâmetros\r\n"
"        document.getElementById(\"colorForm\").action = url; // Redireciona para a URL gerada\r\n"
"    }\r\n"
"\r\n"
"</script>\r\n"
"</html>\r\n"
);
  if(texto.indexOf("Vermelho") != -1 && texto.indexOf("numbers") != -1){
    const char* textoChar = texto.c_str();  // Converte 'texto' para 'const char*'

    // Encontrar a palavra "numbers" no texto
    char *ptr = strstr(textoChar, "numbers");

    char secondCharAfterWord = *(ptr + strlen("numbers") + 1);
    int numero = secondCharAfterWord - '0';
    Serial.print(numero);
    setColors(0, 1, 1, numero);
    Serial.println(texto);
    Serial.println("Vermelho");
  }
    if(texto.indexOf("Azul") != -1 && texto.indexOf("numbers") != -1){
      const char* textoChar = texto.c_str();  // Converte 'texto' para 'const char*'

    // Encontrar a palavra "numbers" no texto
    char *ptr = strstr(textoChar, "numbers");

    char secondCharAfterWord = *(ptr + strlen("numbers") + 1);
    int numero = secondCharAfterWord - '0';
    Serial.print(numero);
    setColors(1, 0, 1, numero);
    Serial.println(texto);
    Serial.println("Azul");
  }
  if(texto.indexOf("Verde") != -1 && texto.indexOf("numbers") != -1){
    const char* textoChar = texto.c_str();  // Converte 'texto' para 'const char*'

    // Encontrar a palavra "numbers" no texto
    char *ptr = strstr(textoChar, "numbers");

    char secondCharAfterWord = *(ptr + strlen("numbers") + 1);
    int numero = secondCharAfterWord - '0';
    Serial.print(numero);
    setColors(1, 1, 0, numero);
    Serial.println(texto);
    Serial.println("Verde");
  }
  if(texto.indexOf("Magenta") != -1 && texto.indexOf("numbers") != -1){
    const char* textoChar = texto.c_str();  // Converte 'texto' para 'const char*'

    // Encontrar a palavra "numbers" no texto
    char *ptr = strstr(textoChar, "numbers");

    char secondCharAfterWord = *(ptr + strlen("numbers") + 1);
    int numero = secondCharAfterWord - '0';
    Serial.print(numero);
    setColors(0, 0, 1, numero);
    Serial.println(texto);
    Serial.println("Magenta");
  }
  if(texto.indexOf("Ciano") != -1 && texto.indexOf("numbers") != -1){
    const char* textoChar = texto.c_str();  // Converte 'texto' para 'const char*'

    // Encontrar a palavra "numbers" no texto
    char *ptr = strstr(textoChar, "numbers");

    char secondCharAfterWord = *(ptr + strlen("numbers") + 1);
    int numero = secondCharAfterWord - '0';
    Serial.print(numero);
    setColors(1, 0, 0, numero);
    Serial.println(texto);
    Serial.println("Ciano");
  }
  if(texto.indexOf("Amarelo") != -1 && texto.indexOf("numbers") != -1){
    const char* textoChar = texto.c_str();  // Converte 'texto' para 'const char*'

    // Encontrar a palavra "numbers" no texto
    char *ptr = strstr(textoChar, "numbers");

    char secondCharAfterWord = *(ptr + strlen("numbers") + 1);
    int numero = secondCharAfterWord - '0';
    Serial.print(numero);
    setColors(0, 1, 0, numero);
    Serial.println(texto);
    Serial.println("Amarelo");
  }
  if(texto.indexOf("desligarTudo") != -1 ){
    const char* textoChar = texto.c_str();  // Converte 'texto' para 'const char*'

    // Encontrar a palavra "numbers" no texto
    char *ptr = strstr(textoChar, "numbers");

    char secondCharAfterWord = *(ptr + strlen("numbers") + 1);
    int numero = secondCharAfterWord - '0';
    Serial.print(numero);
    setColors(1, 1, 1, numero);
    Serial.println(texto);
    Serial.println("Desligar");
  }
}
