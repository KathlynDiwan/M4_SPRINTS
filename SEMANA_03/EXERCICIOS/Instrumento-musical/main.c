#include <stdio.h>
int ledslista[4] = {3,10,13,14};
int savebutton = 35;
int save = LOW;
int deletebutton = 37;
int clean = LOW; 
int light = 0;
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
  pinMode(ledslista[i], OUTPUT);
  }
  pinMode(savebutton, INPUT_PULLUP);
  pinMode(deletebutton, INPUT_PULLUP);
  pinMode(pinApito, OUTPUT);
}
void loop() {
  save = digitalRead(deletebutton);
  if (save == LOW){
   light = conversaoSensor(analogRead(4),64,4063);
    Serial.println(Light);
    int acender[4]= {0,0,0,0};
    for (int i = 0; i<4; i++){
      acender[i] = (1&light>>i);
      if (acender[i] == 1){
        digitalWrite(ledslista[i],HIGH);
      }
    }
  tone(pinApito,200+(250*light),3000);
  arrayLuzes[posicaoInicial] = light;
  posicaoInicial += 1;
  delay(1000);
    for (int i = 0; i<4; i++){
      digitalWrite(ledslista[i],LOW);
    }
  }
  clean = digitalRead(deletebutton);
  if (clean == LOW){
    int acender_2[4]= {0,0,0,0};
    for (int h = 0; h< posicaoInicial; h++){
      light = arrayLuzes[h];
      Serial.println(light);
      for (int i = 0; i<4; i++){
        acender_2[i] = (1&lightz>>i);
        if (acender_2[i] == 1){
          digitalWrite(edslista[i],HIGH);
        }
      }
      tone(pinApito,(100+(150*arrayLuzes[h])),3000);
      arrayLuzes[h] = 0;
      delay(4000);
      for (int i = 0; i<4; i++){
        digitalWrite(ledslista[i],LOW);
          }
    }
    posicaoInicial = 0;
  }
}