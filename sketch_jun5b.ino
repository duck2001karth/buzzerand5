#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Declaracion de leds
int pinLed1 = 4;
int pinLed2 = 3;
int pinLed3 = 2;
//Pin analógico de entrada para el LDR
int pinLDR = 0;
//Variable donde se almacena el valor del LDR
int valorLDR = 0;
//Variable Buzzer
int Buz = 5;
//Lcd
LiquidCrystal_I2C lcd(0x3F, 16,2);

void setup() {
  // put your setup code here, to run once:
  //Apagar los tres LEDS
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  //Configurar el Puerto
  Serial.begin(9600);
  //Configurar el Buzzer
  pinMode(Buz, OUTPUT);
  //-----------------------------------------------------------------------
  //-----------------------------------------------------------------------
  lcd.backlight();
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("Electronica");
  lcd.setCursor(0, 1);
  lcd.print("Patricio Capa");
  delay(2000);
  lcd.clear();
  //-----------------------------------------------------------------------
  //-----------------------------------------------------------------------
}

void loop() {
  // put your main code here, to run repeatedly:
  
      
  lcd.setCursor(0, 0);
  lcd.print("Patricio Capa");
  valorLDR = analogRead(pinLDR);
  Serial.println(valorLDR);
  //-----------------------------------------------------------------------
  //Etapa1
  //Cuando este con luz fuerte, debe sonar la bocina
  if (valorLDR >= 768) { //Si cumple la condicion de que el valor del LDR es mayor que 700
    digitalWrite(Buz, HIGH);
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    for(int i=0; i < 16; i++){
      lcd.setCursor(0, 0);
      lcd.print("ET1 Leds OFF");
      lcd.setCursor(0, 1);
      lcd.print("Buzzer ON");
      delay(400);
    }  
    // Detener el sonido del buzzer
      noTone(Buz);
  }
  //-----------------------------------------------------------------------
  //Etapa2
  //Cuando este con luz natural, no debe prender nada
  if(valorLDR < 767 && valorLDR >= 400) { //Si cumple la condicion de que el valor del LDR es menor que 400
    digitalWrite(pinLed1, LOW); //los Leds automaticamente 
    digitalWrite(pinLed2, LOW); //se mantiene apagado
    digitalWrite(pinLed3, LOW);
    for(int i=0; i < 16; i++){
      lcd.setCursor(0, 1);
      lcd.print("ET2 Leds OFF");
      delay(400);
      lcd.clear(); // 
    }
  } 
  //-----------------------------------------------------------------------
  //Etapa3
  //Cuando hay poca sombra, enciende un LED
  if(valorLDR < 400 && valorLDR >=300 ) { //Si cumple la condicion de que el valor del LDR es menor que 300
  digitalWrite(pinLed1, HIGH); //los 2 Leds automaticamente enciende 
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
    for(int i=0; i < 16; i++){
    lcd.setCursor(0, 1);
    lcd.print("ET3 1 Led ON");
    delay(400);
    lcd.clear(); // 
    }
  } 
  //-----------------------------------------------------------------------
  //Etapa4
  //Cuando este medio oscuro, enciende dos LEDs      
  if(valorLDR < 300 && valorLDR >= 150) { //Si cumple la condicion de que el valor del LDR es menor que 200
  digitalWrite(pinLed1, HIGH); //los 2 Leds automaticamente enciende 
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed3, LOW);
    for(int i=0; i < 16; i++){
    lcd.setCursor(0, 1);
    lcd.print("ET4 2 Leds ON");
    delay(400);
    lcd.clear(); // 
    }
  } 
  //-----------------------------------------------------------------------
  //Etapa5
  //Cuando este completa oscuridad, encienden los tres LEDs     
  if(valorLDR < 150 && valorLDR >=50) { //Si cumple la condicion de que el valor del LDR es menor que 150
  digitalWrite(pinLed1, HIGH); //los Leds automaticamente enciende 
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed3, HIGH);
    for(int i=0; i < 16; i++){
    lcd.setCursor(0, 1);
    lcd.print("ET5 3 Leds ON");
    delay(400);
    lcd.clear(); // 
    }
  } 
    //-----------------------------------------------------------------------
}
