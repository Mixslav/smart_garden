// Seminarski rad Mislav Stipić 2020.
// SUSTAV ZA SADNJU I NADZOR U KONTROLIRANIM UVJETIMA (WIFI,html)


//#include <DNSServer.h>


#include "DHT.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "PageIndex.h" //--> Include the contents of the User Interface Web page, stored in the same folder as the .ino file



ESP8266WebServer server(80);  //--> Server on port 80

//*****************  WIFI IME I ŠIFRA ZA ESP KAO ACCESS POINT  ******************

const char* ssid = "NodeMCU_ESP8266";
const char* password = "pass";

//*******************************************************************************



//definicija senzora DHT11
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)



// Digitalni pin DHT sensor temperature i vlage zraka
#define DHTPIN D6

// pin za DS18B20 senzor temperature tla
const int DS18B20_pin = 12;

// pin za senzor vlažnosti tla
const int vlagaZemPin = A0;

// pin za elektroventil
const int ventil =  5;



// Setup za oneWire uređaj (za senzor temperature zemlje)
OneWire oneWire(DS18B20_pin);
// Referenca za senzor temperature
DallasTemperature sensors(&oneWire);

//pridjeljivanje pina dht11
DHT dht(DHTPIN, DHTTYPE);



void setup() {

  //setup frekvencije povezivanja, definiranje pinova i senzora
  Serial.begin(115200);
  delay(500);

  pinMode(ventil, OUTPUT);
  pinMode(vlagaZemPin, INPUT);
  dht.begin();
  sensors.begin();

  WiFi.softAP(ssid, password);  //--> Start Making ESP8266 NodeMCU as an access point

  IPAddress apip = WiFi.softAPIP(); //--> Get the IP server
  Serial.print("Spojite se na NodeMCU Access Point kao na ruter : ");
  Serial.println(ssid);
  Serial.print("Posjetite IP adresu: ");
  Serial.print(apip); //--> Prints the IP address of the server to be visited
  Serial.println(" u vašem brovseru nakon uspješne konekcije.");

  server.on("/", handleRoot); //--> Routine to handle at root location. This is to display web page.
  server.on("/readTemperature", DHT11Temperature);  //--> Routine to handle the call procedure handleDHT11Temperature
  server.on("/readHumidity", DHT11Humidity);  //--> Routine to handle the call procedure handleDHT11Humidity
  server.on("/readTemperatureGround", DS18B20TemperatureGround);
  server.on("/readHumidityGround", humidGround);

  server.begin(); //--> Start server
  Serial.println("HTTP server started");


}







void loop() {

  server.handleClient();  //Handle client requests

}



//--------This routine is executed when you open NodeMCU ESP8266 IP Address in browser
void handleRoot() {
  String s = MAIN_page; //--> Read HTML contents
  server.send(200, "text/html", s); //--> Send web page
}



//************* Temperatura i vlaga zemlje sa DS18B20 i senzorom vlage zermlje ************

void DS18B20TemperatureGround() {
  
  sensors.requestTemperatures();
  float temperatureGround = sensors.getTempCByIndex(0);  //--> Read temperature as Celsius (the default). If you want to read the temperature sensor in Fahrenheit, use this -> float t = dht.readTemperature (true);
  String Temp_Value = String(temperatureGround);
 
  server.send(200, "text/plane", Temp_Value); //--> Send Temperature value only to client ajax request
  
  if (isnan(temperatureGround)) { //--> Check if any reads failed and exit early (to try again).  
    Serial.println("Neuspješno čitanje podataka sa senzora temperature zemlje!");
  }
  else {
    Serial.print("DS18B20 || Temperatura zemlje : ");
    Serial.print(temperatureGround);
    Serial.print(" || ");
  }
}


void humidGround() {
  float humid_ground = analogRead(vlagaZemPin);  //--> Read temperature as Celsius (the default). If you want to read the temperature sensor in Fahrenheit, use this -> float t = dht.readTemperature (true);
  String Humid_Value = String(humid_ground);
 
  server.send(200, "text/plane", Humid_Value); //--> Send Temperature value only to client ajax request
  
  if (isnan(humid_ground)) { //--> Check if any reads failed and exit early (to try again).  
    Serial.println("Neuspješno čitanje podataka sa senzora vlage zemlje!");
  }
  else {
    Serial.print("Senzor vlage zemlje || Vlaga zemlje : ");
    Serial.print(humid_ground);
    Serial.print(" || ");
  }
}

//*****************************************************************************************


//**************************** Temperatura i vlaga zraka sa DHT11 **************************

void DHT11Temperature() {
  float temperatureAir = dht.readTemperature();  //--> Read temperature as Celsius (the default). If you want to read the temperature sensor in Fahrenheit, use this -> float t = dht.readTemperature (true);
  String Temperature_Value = String(temperatureAir);
 
  server.send(200, "text/plane", Temperature_Value); //--> Send Temperature value only to client ajax request
  
  if (isnan(temperatureAir)) { //--> Check if any reads failed and exit early (to try again).  
    Serial.println("Neuspješno čitanje podataka sa senzora DHT11 temperatura!");
  }
  else {
    Serial.print("DHT11 || Temperatura zraka : ");
    Serial.print(temperatureAir);
    Serial.print(" || ");
  }
}


void DHT11Humidity() {
  float humidAir = dht.readHumidity();
  String Humidity_Value = String(humidAir);
 
  server.send(200, "text/plane", Humidity_Value); //--> Send Humidity value only to client ajax request
  if (isnan(humidAir)) {
    Serial.println("Neuspješno čitanje podataka sa senzora DHT11 temperatura!");
  }
  else {
    Serial.print("DHT11 || Vlažnost zraka : ");
    Serial.print(humidAir);
    Serial.print(" || ");
  }
}

//*****************************************************************************************
