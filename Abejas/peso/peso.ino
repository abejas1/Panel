#include "HX711.h"
 
#define DOUT1  3
#define CLK1  2
#define DOUT2  5
#define CLK2  4
#define DOUT3  7
#define CLK3  6
#define DOUT4  9
#define CLK4  8


HX711 balanza1(DOUT1,CLK1);
HX711 balanza2(DOUT2,CLK2);
HX711 balanza3(DOUT3,CLK3);
HX711 balanza4(DOUT4,CLK4);

void setup() {
  Serial.begin(9600);
  Serial.print("Lectura del valor del ADC:  ");
  Serial.println(balanza1.read()+balanza2.read()+balanza3.read()+balanza4.read());

  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  balanza1.set_scale(); //La escala por defecto es 1
  balanza1.tare(20);	//El peso actual es considerado Tara.
  balanza2.set_scale();
  balanza2.tare(20);
  balanza3.set_scale();
  balanza3.tare(20);
  balanza4.set_scale();
  balanza4.tare(20);
  
  Serial.println("Coloque un peso conocido:");
  
}


void loop() {

  
  Serial.print("Valor de lectura:  ");
  Serial.println(balanza1.get_value(10)+balanza2.get_value(10)+balanza3.get_value(10)+balanza4.get_value(10),0);
  delay(100);
}
	
