#include "DHT.h"

#define DHTPIN 14     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  

DHT dht(DHTPIN, DHTTYPE);

void initDHT22(){
  dht.begin();
}

void readDHT22(){
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  envHumi = h;
  envTemp = t;
  if(deb){
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C ");
  }
}
