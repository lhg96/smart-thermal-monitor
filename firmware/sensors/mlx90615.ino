#include <mlx90615.h>
MLX90615 mlx = MLX90615();


void initMLX(){
  Serial.println("Melexis MLX90615 infra-red temperature sensor test");
  mlx.begin();
  Serial.print("Sensor ID number = ");
  Serial.println(mlx.get_id(), HEX);
}

void readMLX(){
  objTemp = mlx.get_object_temp();
  calibration();
  if(deb){
    Serial.print("Ambient = ");
    Serial.print(mlx.get_ambient_temp()); 
    Serial.print(" *C\tObject = ");
    Serial.print(objTemp);
    Serial.println(" *C");
    Serial.println();
  }
}


void calibration(){
  //if(rcwlState==HIGH && pirState==HIGH ){//&& distance < maxDistance
  if(distance < maxDistance){
      objTemp = objTemp + distance*0.011; //600  => +9      
  }
}
