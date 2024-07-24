#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "yourWifiName";
const char* password = "yourWifiPassword";
const char* serverName = "http://YourLocalIpAddress/fetchLastInput.php";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    
    http.begin(serverName);
    int httpResponseCode = http.GET();
    
    if (httpResponseCode>0) {
      String payload = http.getString();
      Serial.println(payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  delay(5000);  // Wait for 5 seconds before the next request
}
