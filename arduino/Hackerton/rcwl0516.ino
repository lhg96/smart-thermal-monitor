int Sensor = 27;   //Input Pin 34, 10,27


void initRCWL() {  
  pinMode (Sensor, INPUT);  //Define Pin as input  
  if(deb) Serial.println("Waiting for RCWL motion");
}
 
void readRCWL() {
     int val = digitalRead(Sensor); //Read Pin as input     
     if((val > 0) && (rcwlState==LOW)){        
        if(deb) Serial.println("RCWL Motion Detected");
        rcwlState = HIGH;
     } 
     if(val == 0){      
        if(rcwlState == HIGH){
          if(deb) Serial.println("RCWL Motion Released");
          rcwlState = LOW;
        }
     }       
}
