/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A5);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);

/*
 Addition by Caleb Jones, Tryston Hoyes and Blayne Robinson
 RFID Reader Detector electronics project and code created for DESN37900 at Sheridan College © 2018 
 
 The analog input, which reads the electromagnetic waves of RFID readers and converts to voltage, triggers an LED.
 When the converted voltage is greater than 1 the LED will light up.
*/
  if (voltage > 1) {
    digitalWrite(3, 255);  //turn light on full
  } else {
    digitalWrite(3, 0);     // turn light off
  }
}
