#include <DHT_U.h>

#include <Adafruit_Sensor.h>

#include "DHT.h"

#define DHT1PIN 2
#define DHT2PIN 3

#define DHT1TYPE DHT22
#define DHT2TYPE DHT22  
DHT dht1(DHT1PIN, DHT1TYPE);
DHT dht2(DHT2PIN, DHT2TYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht1.begin();
  dht2.begin();
}

void loop() {
  delay(2000);

  float h1 = dht1.readHumidity();

  float t1 = dht1.readTemperature();

  float f1 = dht1.readTemperature(true);
  
  float h2 = dht2.readHumidity();

  float t2 = dht2.readTemperature();

  float f2 = dht2.readTemperature(true);


  if (isnan(h1) || isnan(t1) || isnan(f1)) {
    Serial.println("Failed to read from DHT1 sensor!");
    return;
  }

  if (isnan(h2) || isnan(t2) || isnan(f2)) {
    Serial.println("Failed to read from DHT2 sensor!");
    return;
  }



  float hif1 = dht1.computeHeatIndex(f1, h1);

  float hic1 = dht1.computeHeatIndex(t1, h1, false);

  Serial.print("Humidity1: ");
  Serial.print(h1);
  Serial.print(" %\t");
  Serial.print("Temperature1: ");
  Serial.print(t1);
  Serial.print(" *C ");
  Serial.print(f1);
  Serial.print(" *F\t");
  Serial.print("Heat index1: ");
  Serial.print(hic1);
  Serial.print(" *C ");
  Serial.print(hif1);
  Serial.println(" *F");

 float hif2 = dht2.computeHeatIndex(f2, h2);

  float hic2 = dht2.computeHeatIndex(t2, h2, false);

  Serial.print("Humidity2: ");
  Serial.print(h2);
  Serial.print(" %\t");
  Serial.print("Temperature2: ");
  Serial.print(t2);
  Serial.print(" *C ");
  Serial.print(f2);
  Serial.print(" *F\t");
  Serial.print("Heat index2: ");
  Serial.print(hic2);
  Serial.print(" *C ");
  Serial.print(hif2);
  Serial.println(" *F");

}
