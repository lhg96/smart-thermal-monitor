#include <ComponentObject.h>
#include <RangeSensor.h>
#include <SparkFun_VL53L1X.h>
#include <vl53l1x_class.h>
#include <vl53l1_error_codes.h>

#include "SparkFun_VL53L1X.h" //Click here to get the library: http://librarymanager/All#SparkFun_VL53L1X
SFEVL53L1X distanceSensor;


void initVL53(){
  if(deb) Serial.println("VL53L1X Qwiic Test");

  if (distanceSensor.begin() != 0) //Begin returns 0 on a good init
  {
    if(deb) Serial.println("Sensor failed to begin. Please check wiring. Freezing...");
    while (1)
      ;
  }
  if(deb) Serial.println("Sensor online!");
}

void readVL53(){  
  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  while (!distanceSensor.checkForDataReady())
  {
    delay(1);
  }
  distance = distanceSensor.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();

  if(deb) {
    Serial.print("Distance(mm): ");
    Serial.print(distance);
  
    float distanceInches = distance * 0.0393701;
    float distanceFeet = distanceInches / 12.0;
  
    Serial.print("\tDistance(ft): ");
    Serial.print(distanceFeet, 2);
  
    Serial.println();
  }
}
