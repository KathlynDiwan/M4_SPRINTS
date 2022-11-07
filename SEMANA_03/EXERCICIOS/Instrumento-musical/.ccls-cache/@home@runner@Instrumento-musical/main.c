#include <stdio.h>
int Ledslista[4] = {3,10,13,14};
int botaoSalvar = 35;
int save = LOW;
int botaoLimpar = 37;
int clean = LOW; 
int diretaLuz = 0;
int arrayLuzes[50] = {};
int posicaoInicial = 0;
int pinApito = 6;
int conversaoSensor(int value, int min, int max) {
  int converted = 0;
  int a = value - min;
  float b = max - min;
  converted = float((a / b)*15);
  return converted;
}
void setup() {
  Serial.begin(115200);
  for (int i = 0; i<4; i++){
  pinMode(Ledslista[i], OUTPUT);
  }
  pinMode(botaoSalvar, INPUT_PULLUP);
  pinMode(botaoLimpar, INPUT_PULLUP);
  pinMode(pinApito, OUTPUT);
}
void loop() {
  save = digitalRead(botaoLimpar);
  if (save == LOW){
    diretaLuz = conversaoSensor(analogRead(4),64,4063);
    Serial.println(diretaLuz);
    int acender[4]= {0,0,0,0};
    for (int i = 0; i<4; i++){
      acender[i] = (1&diretaLuz>>i);
      if (acender[i] == 1){
        digitalWrite(Ledslista[i],HIGH);
      }
    }
  tone(pinApito,100+(150*diretaLuz),3000);
  arrayLuzes[posicaoInicial] = diretaLuz;
  posicaoInicial += 1;
  delay(1000);
    for (int i = 0; i<4; i++){
      digitalWrite(Ledslista[i],LOW);
    }
  }
  clean = digitalRead(botaoLimpar);
  if (clean == LOW){
    int acender_2[4]= {0,0,0,0};
    for (int h = 0; h< posicaoInicial; h++){
      diretaLuz = arrayLuzes[h];
      Serial.println(diretaLuz);
      for (int i = 0; i<4; i++){
        acender_2[i] = (1&diretaLuz>>i);
        if (acender_2[i] == 1){
          digitalWrite(Ledslista[i],HIGH);
        }
      }
      tone(pinApito,(100+(150*arrayLuzes[h])),3000);
      arrayLuzes[h] = 0;
      delay(5000);
      for (int i = 0; i<4; i++){
        digitalWrite(Ledslista[i],LOW);
          }
    }
    posicaoInicial = 0;
  }
}