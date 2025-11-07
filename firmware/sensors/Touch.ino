
#define TOUCH_PIN 16
int touchState = LOW;             // we start, assuming no motion detected
long pressedTime = 0;

void initTouch(){
  pinMode(TOUCH_PIN, INPUT);  
  pressedTime = millis();
}


void runTouch(){
  int val = digitalRead(TOUCH_PIN) ;
  if (val == HIGH){
    if (touchState == LOW) {
      Serial.println("Touch Pressed");
      touchState = HIGH;      
      pressedTime = millis();
    }
  }else{
     if (touchState == HIGH) {      
      Serial.println("Touch Release");
      touchState = LOW;
      //run touch function

      long cTime = millis();
      if((cTime-pressedTime)>5000){
        Serial.println("ESP restart");
        //restartDisplay();
        delay(3000);
        ESP.restart();
      }
    }
  }
}
