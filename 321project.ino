#define LEDR 11
#define LEDG 13
#define LEDB 12

int analog_input = A0;
int digital_input = A1;

void setup() {                
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(analog_input, INPUT);
  pinMode(digital_input, INPUT);
  Serial.begin(9600);
  Serial.println("KY-038 Noise detection");
}

int r = 0;
int g = 0;
int b = 0;

void loop() {
  // r = random(0, 255);
  // g = random(0, 255);
  // b = random(0, 255);
  // analogWrite(LEDR, r);
  // analogWrite(LEDG, g);
  // analogWrite(LEDB, b);
  // delay(1000);

  float analog_value;
  int digital_value;
    
  analog_value = analogRead(analog_input); 
  digital_value = digitalRead(digital_input);
    
  Serial.print("Analog voltage value: "); 
  Serial.print(analog_value, 4);
  Serial.print(" V, \t Threshold value: ");
  
  if (digital_value == 1) {
      Serial.println("reached");
  }
  else {
      Serial.println("not yet reached");
  }
  Serial.println("----------------------------------------------------------------");
  delay(1000);
}