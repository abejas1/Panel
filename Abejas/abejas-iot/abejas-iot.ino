
#include "HX711.h"
#include <DHT_U.h>

#include <Adafruit_Sensor.h>

#include "DHT.h"

const long A = 1000;     //Resistencia en oscuridad en KO
const int B = 15;        //Resistencia a la luz (10 Lux) en KO
const int Rc1 = 10;       //Resistencia calibracion en KO
const int LDRPin1 = A0;   //Pin del LDR

const long C = 1000;     //Resistencia en oscuridad en KO
const int D = 15;        //Resistencia a la luz (10 Lux) en KO
const int Rc2 = 10;       //Resistencia calibracion en KO
const int LDRPin2 = A1;   //Pin del LDR
 
int V1;
int ilum1;

int V2;
int ilum2;

#define DHT1PIN 10
#define DHT2PIN 11

#define DHT1TYPE DHT22
#define DHT2TYPE DHT22  
DHT dht1(DHT1PIN, DHT1TYPE);
DHT dht2(DHT2PIN, DHT2TYPE);

#define calibration_factor -7050.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT1  3
#define CLK1  2

#define DOUT2  5
#define CLK2  4

#define DOUT3  7
#define CLK3  6

#define DOUT4  9
#define CLK4  8

HX711 scale1(DOUT1, CLK1);
HX711 scale2(DOUT2, CLK2);
HX711 scale3(DOUT3, CLK3);
HX711 scale4(DOUT4, CLK4);


void setup() {
  Serial.begin(9600);
  
  Serial.println("Estado del panal: ");

  scale1.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale1.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  scale2.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale2.tare();
    scale3.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale3.tare();
    scale4.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale4.tare();
  dht1.begin();
  dht2.begin();  
}

void loop() {
  delay(1000);
   V1 = analogRead(LDRPin1);
   V2 = analogRead(LDRPin2);         
 
 //ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   ilum1 = ((long)V1*A*10)/((long)B*Rc1*(1024-V1));    //usar si LDR entre A0 y Vcc (como en el esquema anterior)
   ilum2 = ((long)V2*C*10)/((long)D*Rc2*(1024-V2));    //usar si LDR entre A0 y Vcc (como en el esquema anterior)
   

  
   Serial.print("Luz interna: ");
   Serial.println(ilum1);   
   Serial.print("Luz externa: ");
   Serial.println(ilum2);
    delay(2000);
  Serial.print("Peso: ");
  Serial.print(scale1.get_units()+(-1)*(scale2.get_units())+(-1)*(scale3.get_units())+scale4.get_units(), 1); //scale.get_units() returns a float
  Serial.print(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();
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

 


