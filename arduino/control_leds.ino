const int LED_ROJO = 13;
const int LED_VERDE = 12;
char comando;

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  Serial.begin(9600);
  Serial.println("Arduino listo");
}

void loop() {
  if (Serial.available() > 0) {
    comando = Serial.read();
    switch(comando) {
      case 'R':
        digitalWrite(LED_ROJO, HIGH);
        digitalWrite(LED_VERDE, LOW);
        Serial.println("LED ROJO - De Pie");
        break;
      case 'V':
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_VERDE, HIGH);
        Serial.println("LED VERDE - Sentado");
        break;
      case 'A':
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_VERDE, LOW);
        Serial.println("LEDs apagados");
        break;
    }
  }
}
