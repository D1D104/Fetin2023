
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <string>
#include <cstring>

#define FIREBASE_HOST "https://rfid-tag-bdce9-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "a9IIxKeztAFdNFg64o88eqf29ZCJcMLMzuurkKrf"            
#define _SSID "Afonso_2.4"                                  
#define _PASSWORD "ar642703"    

FirebaseData firebaseData; 

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println("WiFi Connected");

  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);

while (!Serial) {
; 
}
}

String leitura= "";
bool aux=false;

void loop() { 

  while (Serial.available()) {
   leitura = (Serial.readString());
  aux=true;
  }

if( aux == true){
  Firebase.setString(firebaseData,"/Tag",leitura);
  aux=false;
  leitura="";
 }
delay(1000);
}






