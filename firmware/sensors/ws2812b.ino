#include <Adafruit_NeoPixel.h>

#define PIN 26

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

//https://gist.github.com/ppelleti/3a29794b8bb2c306e73db50b9426de83
//http://www.esp32learning.com/code/esp32-and-ws2812b-rgb-led-example.php

void initNEO(){
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}



void runNEO(){ 
  int   lowTemp   = 30;
  int   highTemp  = 40; 
  float gap       = 255/(highTemp-lowTemp);
  
  int rr = objTemp-lowTemp;
  
  int r =0;
  int g =0;
  int b =0;  
  if(objTemp<=lowTemp){
    r=0; g=0; b=255;    
  }else if(objTemp>=highTemp){
    r = 255; g=0; b = 0;
  }else if(objTemp<=(lowTemp+(highTemp-lowTemp)/2)){ //절반이하
    r = rr*gap;
    g = r*2;
    b = 255-r;
  }else{
    r = rr*gap;
    g = 255-(r/2);
    b = 255-r;
  }  

  if(r<0)   r =0;
  if(r>255) r =255;
  if(g<0)   g =0;
  if(g>255) g =255;
  if(b<0)   b =0;
  if(b>255) b =255;

  
  pixels.clear(); // Set all pixel colors to 'off'

  //if(rcwlState==HIGH && pirState==HIGH){
    pixels.setPixelColor(0, pixels.Color(r,g,b)); 
    pixels.show();   // Send the updated pixel colors to the hardware.
  //}  
}
