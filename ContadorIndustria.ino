#include <DHT11.h>
#include <Wire.h>
#include <FastIO.h>
#include <I2CIO.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_SR2W.h>
#include <LiquidCrystal_SR3W.h>

#define I2C_ADDR    0x27
int pinPulso = 8;                //Pulso (Pin que recibe la señal de la máquina)
int val = 0;                     
int conta = 0;                   //Contador de ciclos
int restart = 0;                 //Bandera de reinicio cronometro
int pinDHT=2;                    //Pin out del sensor al pin 2 de Arduino
long milisegundos = 0;
int decimas = 0;
int segundos = 0;
int minutos = 0;
DHT11 dht11(pinDHT);


LiquidCrystal_I2C             lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);
void setup()
   {
       Serial.begin(9600);
       pinMode(8,INPUT);
       digitalWrite(8, LOW);
       lcd.begin (20,4);    // Inicializar el display con 20 caraceres 4 lineas
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);
       
       lcd.home ();                   
       lcd.print("CICLOS: ");
       lcd.setCursor ( 0, 1 );        
       lcd.print("TEMPO/CICLO: ");
       lcd.setCursor ( 0, 2 );
       lcd.print("TEMPERATURA: ");
       lcd.setCursor ( 0, 3 );
       lcd.print("HUMEDAD: ");
       lcd.setCursor (19,2);
       lcd.print("C");
       lcd.setCursor (19,3);
       lcd.print("%");
       lcd.setCursor( 15, 0 );
       lcd.print(String(conta));
       
       
   }
void loop() 
   {
    milisegundos = millis();
  if(milisegundos % 100 == 0){ //entra si ha pasado una decima de segundo
    decimas++;
    if(decimas == 10){ //pasan 10 decimas, aumenta un segundo
      decimas = 0;
      segundos++;
    }
    if(segundos == 60){ //Pasan 60 seg, aumenta un minuto
      segundos = 0;
      minutos++;
    }  
  // flanco de subida
  if ( digitalRead(8) == HIGH ) 
  {
      // flanco de bajada
      if ( digitalRead(8) == LOW )
      {
         val =conta;
         conta++;               //Incrementa el contador
         if (val != conta){
          restart = 1;     
         }
         else{
          restart = 0;
         }
         Serial.println(conta); //Imprime el valor por consola
         lcd.setCursor( 15, 0 );
         lcd.print(String(conta));
         delay (100);           // Retardo
      }
  }
  if (restart == 1){
    segundos = 0;
    minutos = 0;
  }
        lcd.setCursor ( 13, 1 );
        lcd.print(String(minutos));
        lcd.setCursor ( 15, 1 );
        lcd.print(":");
        lcd.setCursor ( 16, 1 );
        lcd.print(String(segundos));
       int err;
       float temp, hum;
       if((err = dht11.read(hum, temp)) == 0)    // Si devuelve 0 es que ha leido bien
          {
             Serial.print("Temperatura: ");
             Serial.print(temp);
             Serial.print(" Humedad: ");
             Serial.print(hum);
             Serial.println();
             lcd.setCursor ( 13, 2 );
             lcd.print(String(temp));
             lcd.setCursor( 13, 3 );
             lcd.print(String(hum));

             
          }
       else
          {
             Serial.println();
             Serial.print("Error Num :");
             Serial.print(err);
             Serial.println();
             
                       }
  
       delay(1000);
    }}
