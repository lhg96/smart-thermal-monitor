
int inputPin = 17;              // choose the input pin (for PIR sensor)

int pir;                        //pir count

void initSR602(){
  pinMode(inputPin, INPUT);     // declare sensor as input
}

void readSR602(){
  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH    
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("PIR Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
      pir++;//counter
    }
  } else {    
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("PIR Motion Released!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
