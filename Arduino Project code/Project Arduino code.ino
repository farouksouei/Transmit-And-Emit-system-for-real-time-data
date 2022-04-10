#include "dht.h"
#include <SoftwareSerial.h>
#define dht_apin A0 // Analog Pin sensor is connected to
#define trigPin 8
#define echoPin 9
SoftwareSerial BTserial(10, 11); // RX | TX
 
dht DHT;

// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  delay(500);//Wait for system to boot up
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  Serial.begin(9600); // Starts the serial communication
  BTserial.begin(9600);
  delay(1000);//Wait before accessing the sensor
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration/2) / 29.1;  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  DHT.read11(dht_apin);
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature); 
  Serial.println("C  ");
  //delay(3000);// Must wait at least 3 seconds before accessing DHT11
  BTserial.print(DHT.humidity);
  BTserial.print(",");
  BTserial.print(DHT.temperature);
  BTserial.print(",");
  BTserial.print(distance);
  BTserial.print(","); 
}
