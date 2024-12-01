#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);
char val; //value to receieve data from the serial port
int LEDR = 13;
int LEDG = 12;
int LEDB = 11;
#define analog_input A0

void setup() {
  pinMode(LEDR, OUTPUT); // set LED pins as outputs
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(analog_input, INPUT);
  Serial.begin(9600);
  BT.begin(9600); //begin serial communications at 9600 bits per second (baud)
}

void loop() {
  int analog_value = analogRead(analog_input); 

  if(BT.available()) { // check if there is data to read
    val = BT.read(); // read the data into our value variable
    BT.print("Reading new data: ");
    BT.println(val);
  }

  if (val == '1') { // if 1 (high) is received
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
  } else { // 1 not received
    digitalWrite(LEDR, LOW); // Turn on the red light and off the green light
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
  }
  
  delay(100);
}