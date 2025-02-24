
void setColors(byte red, byte blue, byte green, int valorParaPiscar){
    for(int i = 1; i <= valorParaPiscar; i++){
      delay(500);
      digitalWrite(D4, red); // Vermelho
      digitalWrite(D8, blue); // Verde 
      digitalWrite(D9, green); // Azul 
      delay(500);
      digitalWrite(D4, 1); // Vermelho
      digitalWrite(D8, 1); // Verde 
      digitalWrite(D9, 1); // Azul  
      delay(500);
      Serial.println("Valor no for: " + (String)i);
    }
    texto = "";
  }
  
  