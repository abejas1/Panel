int rango = 10000; //Puede cambiarse, es el rango de los sonidos que coge
int volumen;

void setup() {                
  Serial.begin(9600);   
}

void loop() {
 
    volumen = analogRead(A0); //Se ha conectado el sensor a la placa por medio de la entrada A0
   
    Serial.println(volumen); //Sirve para, al abrir el Serial Monitor, ver cuando recoge y cuando no recoge sonido
    delay(1000); //Para que los sonidos los escriba en el Serial Monitor con un delay de 50 milisegundos  
      
}

