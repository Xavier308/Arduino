/**
* Creé este codigo para controlar la polaridad de un electoiman.
* La polaridad cambia de norte a sur. 1 segundo norte, apaga 1 segundo, prende 1 segundo sur, apaga 1 segundo
* Se puede ver el efecto con una simple brújula, o utilizando un dispositivo digilal que indique polaridad.
* Este proyecto es parte de una prueba para un proyecto más complejo que involucra multiples electroimanes.
*
*
*
*/

#define ELECTROMAGNET_IN1 7
#define ELECTROMAGNET_IN2 8

void setup() {
  Serial.begin(9600);

  Serial.println("DRV8871 test");

  pinMode(ELECTROMAGNET_IN1, OUTPUT);
  pinMode(ELECTROMAGNET_IN2, OUTPUT);
}

void loop() {
  // Activar electroimán en una dirección (forward)
  digitalWrite(ELECTROMAGNET_IN1, HIGH);
  digitalWrite(ELECTROMAGNET_IN2, LOW);
  delay(1000); // Mantener encendido por 1 segundo

  // Desactivar electroimán
  digitalWrite(ELECTROMAGNET_IN1, LOW);
  digitalWrite(ELECTROMAGNET_IN2, LOW);
  delay(1000); // Mantener apagado por 1 segundo

  // Activar electroimán en la dirección opuesta (reverse)
  digitalWrite(ELECTROMAGNET_IN1, LOW);
  digitalWrite(ELECTROMAGNET_IN2, HIGH);
  delay(1000); // Mantener encendido por 1 segundo

  // Desactivar electroimán
  digitalWrite(ELECTROMAGNET_IN1, LOW);
  digitalWrite(ELECTROMAGNET_IN2, LOW);
  delay(1000); // Mantener apagado por 1 segundo
}
