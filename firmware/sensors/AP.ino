#include "WiFi.h"

//d010 //테스트기
const String did      =  "d010";

const char* ssid      =  "hyuniptime";
const char* password  =  "01066391694";

const char* hostGet   = "api.thingspark.kr";
String urlGet    = "/channels/entrys";
String apiKey    = "apiKey=lIHsJvyroZydkQXI"; 
const int httpPort    = 80;

void initWiFi(){
  WiFi.begin(ssid, password);   
  int cnt = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");      
    cnt++;
    if(cnt>3) break;
  }
  Serial.println("Connected to the WiFi network");
}


boolean isSend=false;
void sendWiFiData(){  
  if(pirState==HIGH ){ //사람이 있을때만 데이터 보낼것
    
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    WiFiClient clientGet;     
    String envTempEntity  = "field1="  + String(envTemp);
    String objTempEntity  = "field2="  + String(objTemp);
    String distanceEntity = "field3=" + String(distance);
    
    String url = urlGet+"?"+apiKey+"&"+envTempEntity+"&"+objTempEntity+"&"+distanceEntity; 
    Serial.println(url);
    //Serial.print(">>> Connecting to host: ");
    //Serial.println(hostGet);
      
    if (!clientGet.connect(hostGet, httpPort)) {
      Serial.print("Connection failed: ");
      Serial.print(hostGet);
    } else {
      clientGet.println("GET " + url + " HTTP/1.1");
      clientGet.print("Host: ");
      clientGet.println(hostGet);
      clientGet.println("User-Agent: ESP8266/1.0");
      clientGet.println("Connection: close\r\n\r\n");
      unsigned long timeoutP = millis();
      while (clientGet.available() == 0) {
        if (millis() - timeoutP > 10000) {
          Serial.print(">>> Client Timeout: ");
          Serial.println(hostGet);
          clientGet.stop();
          return;
        }
      }
      //just checks the 1st line of the server response. Could be expanded if needed.
      while(clientGet.available()){
        String retLine = clientGet.readStringUntil('\r');
        Serial.println(retLine);
        break; 
      }
  
    } //end client connection if else
                          
    Serial.print(">>> Closing host: ");
    Serial.println(hostGet);            
    clientGet.stop();    
  }
  }
}
