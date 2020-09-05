

int laserPin = 25;
void initLaser(){
  pinMode(laserPin, OUTPUT);
}

void runLaser(){
  if(rcwlState==HIGH && pirState==HIGH ){//&& distance < maxDistance
    digitalWrite(laserPin, HIGH); // Open the laser head
  }else{
    digitalWrite(laserPin, LOW); 
  }
}
