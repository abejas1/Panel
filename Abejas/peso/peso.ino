
#include "HX711.h"

HX711 balanza1(A1, A0);
HX711 balanza2(A3, A2);

void setup() {
  Serial.begin(9600);
  Serial.print("Lectura del valor del ADC:  ");
  Serial.println(balanza1.read()+balanza2.read());

  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  balanza1.set_scale(); //La escala por defecto es 1
  balanza1.tare(20);	//El peso actual es considerado Tara.
  balanza2.set_scale();
  balanza2.tare(20);
  Serial.println("Coloque un peso conocido:");
  
}


void loop() {

  
  Serial.print("Valor de lectura:  ");
  Serial.println(balanza1.get_value(10)+balanza2.get_value(10),0);
  delay(100);
}
	
