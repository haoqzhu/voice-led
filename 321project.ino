#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); //Red on 2, Black on 3

#define LEDR 13
#define LEDG 12
#define LEDB 11
#define analog_input A0
#define digital_input A1

void setup() {                
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(analog_input, INPUT);
  pinMode(digital_input, INPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.print("Ready to accept commands");
}

int r = 0;
int g = 0;
int b = 0;

void loop() {

  if (Serial.available() > 0)
    BTSerial.write(Serial.read());
  if (BTSerial.available() > 0)
    Serial.write(BTSerial.read());

  int analog_value = analogRead(analog_input); 
  int digital_value = digitalRead(digital_input);

  Serial.print(analog_value);

  // Convert the analog value to voltage for display
  float voltage = analog_value * (5.0 / 1023.0);
    
  Serial.print("Analog voltage value: "); 
  Serial.println(voltage);
  
  Serial.println("----------------------------------------------------------------");

  // Change LED color based on sound level
  if (analog_value < 570) {
    // Low sound level - Off
    analogWrite(LEDR, 0);
    analogWrite(LEDG, 0);
    analogWrite(LEDB, 0);
  } else if (analog_value < 800) {
    // Medium sound level - Green
    analogWrite(LEDR, 0);
    analogWrite(LEDG, 255);
    analogWrite(LEDB, 0);
  } else {
    // High sound level - Red
    analogWrite(LEDR, 255);
    analogWrite(LEDG, 0);
    analogWrite(LEDB, 0);
  }

  delay(100);
}
