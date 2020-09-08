#include <SoftwareSerial.h> // Inclui Biblioteca
SoftwareSerial mySerial(10, 11);          // Simula RX e TX em outras portas

const int ordemServico = 2;
int buttonA = 4;
int buttonB = 5;
int buttonC = 6;
int buttonD = 7;
int ledPin = 13;

void setup() {
  Serial.begin(9600);                  // Taxa de transferência da Serial
  mySerial.begin(9600);                // Taxa de transferência do HC12
  pinMode(ledPin, OUTPUT);
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(buttonC, INPUT_PULLUP);
  pinMode(buttonD, INPUT_PULLUP);
}

void loop() {
  int actionA = digitalRead(buttonA);
  int actionB = digitalRead(buttonB);
  int actionC = digitalRead(buttonC);
  int actionD = digitalRead(buttonD);

  if (actionA == LOW) {
    mySerial.write(getCommand(2));
    digitalWrite(ledPin, HIGH);

  } else if (actionB == LOW) {
    mySerial.write(getCommand(3));
    digitalWrite(ledPin, HIGH);

  } else if (actionC == LOW) {
    mySerial.write(getCommand(4));
    digitalWrite(ledPin, HIGH);

  } else if (actionD == LOW) {
    mySerial.write(getCommand(5));
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);  
  }

  mySerial.flush();
  delay(100);
}

int getCommand(int action) {
  return action * ordemServico;
}
