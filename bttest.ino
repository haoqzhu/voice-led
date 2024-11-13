#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); //Red on 2, Black on 3

void setup() {                
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.print("Ready to accept commands");
}

void loop() {
  if (Serial.available() > 0)
    BTSerial.write(Serial.read());
  if (BTSerial.available() > 0)
    Serial.write(BTSerial.read());

  delay(100);
}