#include <Wire.h>    // I2C library
#include <SimpleTimer.h> // here is the SimpleTimer library

const boolean  deb PROGMEM = true ; //developer mode
SimpleTimer timer; 

float envTemp =0;
float envHumi =0;
float objTemp=0;
float distance=0;
int   rcwlState = LOW;  //Change detection flag
int   pirState = LOW;             // we start, assuming no motion detected

int   minDistance = 10;
int   maxDistance = 1000;

void setup() {
   Serial.begin(19200);   
   initMLX();
   initVL53();   
   initDHT22();   
   initSR602();
   initRCWL();
   initTouch();
   initNEO();
   initLaser();
   initWiFi();
   
   

   timer.setInterval(1000L, readMLX);  //MLX thermal sensor 
   timer.setInterval(1000L, readVL53); //VL53 distance sensor 
   timer.setInterval(3000L, readDHT22);
   
   timer.setInterval(1000L, readSR602);
   timer.setInterval(1000L, readRCWL);   
   timer.setInterval(100L,  runTouch);
   timer.setInterval(1000L, runNEO);
   timer.setInterval(1000L, runLaser);
   timer.setInterval(1000L, sendWiFiData);
}

void loop() {      
  timer.run(); 
}
