#include <SPI.h>
#include <LoRa.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define LORA_SS 53
#define LORA_RST 9
#define LORA_DIO0 22

// Choose two Arduino pins to use for software serial
int RXPin = 19;
int TXPin = 18;   

// Create a TinyGPS++ object
TinyGPSPlus gps;

SoftwareSerial gpsSerial(RXPin, TXPin);

void setup() {
LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);  
Serial.begin(57600); // connect serial
Serial.println("The GPS Received Signal:");
Serial1.begin(9600); // connect gps sensor
  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setTxPower(1);
  
  
}

void loop() {
  
  while(Serial1.available()){
    if (gps.encode(Serial1.read())) // so if GPS work only ,If not then I wont spam The Eror things
    LoRa.beginPacket();
    LoRa.print("This HSSRB SAT");
    LoRa.print("Lat: ");
    LoRa.print(gps.location.lat(), 6);
    LoRa.print("c");
    LoRa.print("Long: ");
    LoRa.print(gps.location.lng(), 6);
    LoRa.print("c");
    LoRa.print(gps.speed.kmph());
    LoRa.print("Speed Km/H");
    LoRa.print("c");
    LoRa.print(gps.altitude.meters());
    LoRa.print("Altitude M");
    LoRa.print(gps.time.minute()); // Raw time in HHMMSSCC format (u32)
    LoRa.print(gps.date.value());
    Serial.println("Sent via LoRa");
    Serial.println("This HSSRB SAT");
    Serial.println("Lat: ");
    Serial.println(gps.location.lat(), 6);
    Serial.println("c");
    Serial.println("Long: ");
    Serial.println(gps.location.lng(), 6);
    Serial.println("c");
    Serial.println(gps.speed.kmph());
    Serial.println("Speed Km/H");
    Serial.println("c");
    Serial.println(gps.altitude.meters());
    Serial.println("Altitude M");
    Serial.println(gps.time.minute()); // Raw time in HHMMSSCC format (u32)
    Serial.println(gps.date.value());
    Serial.println(gps.satellites.value());
    Serial.println("Sent via LoRa");
    
    
    
    
    
    
    
    
    
    
    
    LoRa.endPacket();
    delay(2000);

  }

}
