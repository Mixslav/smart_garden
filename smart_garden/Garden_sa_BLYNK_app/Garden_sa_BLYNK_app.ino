// Seminarski rad Mislav Stipić 2020.
// SUSTAV ZA SADNJU I NADZOR U KONTROLIRANIM UVJETIMA (WIFI, BLYNK app)

#define BLYNK_PRINT Serial    // Zakomentiraj da poništiš printeve i uštediš prostora (nebitno za projekt)


// biblioteke za senzore, esp8266 i protokole

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>


SimpleTimer timer;        //  tajmer nužan za rad funkcija


// Dobit ćeš Auth Token u Blynk aplikaciji koja se nalazi na google trgovini.

char auth[] = "E0YY6E17kauYpCzRknXE4glSWMhA58V-";    //Ovdje unesi Auth Token kako bi povezali esp sa aplikacijom



char ssid[] = "Mi_Telefon";     // WIFI ime         // Ovdje unesi naziv i šifru interneta na koji se spaja esp
char pass[] = "12345687";   // WIFI šifra



#define DHTPIN 2            // Digital pin GPIO4 (D2) za DHT11

// Odkomentiraj senzor koji se koristi (u našem slučaju to je DHT11)

#define DHTTYPE DHT11       // DHT 11
//#define DHTTYPE DHT22     // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21     // DHT 21, AM2301


DHT dht(DHTPIN, DHTTYPE);   // pridjeli pin i tip senzora objektu dht


// pin za DS18B20 senzor temperature tla
const int DS18B20_pin = 12;               // Digital pin GPIO12 (D6)

// pin za senzor vlažnosti tla
const int vlagaZemPin = A0;               // Analog pin A0 


// pin za kontrolu ventila
WidgetLED ventil(V2);                     // Digital pin GPIO5 (D1)


OneWire oneWire(DS18B20_pin);             // Setup za oneWire uređaj (za senzor temperature zemlje)

DallasTemperature sensori(&oneWire);      // Referenca za senzor temperature


// funkcija za slanje informacija sa svih senzora na aplikaciju

void posaljiSenzor(){
  sensori.setResolution(12);                       // kalibracija rezolucije senzora DS18B20
  sensori.requestTemperatures();                   // zahtjev za čitanje podataka sa senzora DS18B20 (nužno za rad senzora)
  
  float vlagaZ = dht.readHumidity();                                       // čitaj vlažnost zraka sa DHT11 senzora
  float tempZ = dht.readTemperature();                                     // čitaj temperaturu zraka sa DHT11 senzora (za podatke u Fahrenheitima piši: dht.readTemperature(true))
  float tempZem = sensori.getTempCByIndex(0);                              // čitaj temperaturu zemlje u celzijusima  
  float vlagaZem = ( 100 - ( (analogRead(vlagaZemPin)/1023.00) * 100 ) );  // čitaj vlažnost tla sa senzora za vlagu zla 

  Blynk.virtualWrite(V5, vlagaZ);       // V5 je adresa grafa na aplikaciji na koji dolaze podaci senzora vlage zraka
  Blynk.virtualWrite(V6, tempZ);        // V6 je adresa grafa na aplikaciji na koji dolaze podaci senzora temperature zraka
  Blynk.virtualWrite(V7, vlagaZem);     // V7 je adresa grafa na aplikaciji na koji dolaze podaci senzora vlage zemlje zraka
  Blynk.virtualWrite(V8, tempZem);      // V8 je adresa grafa na aplikaciji na koji dolaze podaci senzora temperature zemlje zraka


// odkomentiraj ovo za debagiranje i upali serijski monitor (nepotrebno za rad aplikacije)
  
/*  if (isnan(v) || isnan(t) || isnan(vze) || isnan(tze)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
 */ 

 
  // Slanje podataka na aplikaciju:
  // nemoj slati više od 10 vrijednosti po sekundi jer mikrokontroler ne može podnijeti toliku količinu podataka
  

}



// funkcija za paljenje i gašenje ventila

void Ventil(){
  if (ventil.getValue()) {
    ventil.off();
    // Serial.println("Ventil na adresi V2: izgašen");  //printaj na serijski monitor (nepotrebno za aplikaciju)
  } 
  else {
    ventil.on();
   // Serial.println("Ventil na adresi V2: upaljen");  //printaj na serijski monitor (nepotrebno za aplikaciju)
  }
}



// setup funkcija za postavljanje potrebnih parametara, aktivaciju biblioteka i ostvarivanje povezivanja
// ova funkcija je nužna za rad programa i sve što se izvršava na njoj izvrši se jedan put

void setup()
{
  Serial.begin(9600);               // frekvencija na kojoj se povezuje esp sa računalom (9600 bita po sekundi)
  Blynk.begin(auth, ssid, pass);    // započmi spajanje esp sa internetom

  dht.begin();                      // pokreni objekt dht
  sensori.begin();                  // pokreni objekt senzori
  
  delay(100);                       // vremenski razmak u kojem esp ništa ne radi (nužno za stabilan rad)

  
// postavi funkcije i potrebna vremena tajmerima "timer" za diskretni rad 
  timer.setInterval(1000L, posaljiSenzor);   //  1000L = 1 sekunda
  timer.setInterval(100L, Ventil);           //  100L = 0,1 sekunda  (vrijeme pozivanja funkcije Ventil() mora bit malo manja da bi stabilnije radila mobilna aplikacija)
}



void loop()
{
  Blynk.run();  // pokreni Blynk 
  timer.run(); // pokreni tajmer1




// odkomentiraj ovo za debagiranje i upali serijski monitor (nepotrebno za rad aplikacije)
  
/*
  Serial.print("temp zraka:");
  Serial.print(tempZ);
  Serial.print("vlaga zraka :");
  Serial.print(vlagaZ);
  Serial.print("vlaga zemlje:");
  Serial.print(vlagaZem);
  Serial.print("temp zemlje:");
  Serial.print(tempZem);
  Serial.println();
  */
}
