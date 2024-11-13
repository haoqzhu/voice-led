#define analog_input A0
#define digital_input A1

void setup() {                
  pinMode(analog_input, INPUT);
  pinMode(digital_input, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analog_value = analogRead(analog_input); 
  int digital_value = digitalRead(digital_input);

  Serial.print(analog_value);

  // Convert the analog value to voltage for display
  float voltage = analog_value * (5.0 / 1023.0);
    
  Serial.print("Analog voltage value: "); 
  Serial.println(voltage);
  
  Serial.println("----------------------------------------------------------------");

  delay(100);
}
 