/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

/*
 Addition by Caleb Jones, Tryston Hoyes and Blayne Robinson
 RFID Reader Detector electronics project and code created for DESN37900 at Sheridan College © 2018 
 
 The analog input, which reads the electromagnetic waves of RFID readers and converts to voltage, triggers a vibrating motor.
 When the converted voltage is greater than 1 the vibrating motor will vibrate.
*/

const int buttonPin = A2;        // the number of the pushbutton pin
int buzzerPin = 10;             // Which pin the buzzer is attached to
int buttonState = 0;            // variable for reading the pushbutton status
float voltage = 0;


int delayTime = 500;            // Delay in milliseconds

// Notes and their frequencies
const int G = 1568;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(buzzerPin, OUTPUT);   // initialize the buzzer pin as an input
  pinMode(buttonPin, INPUT);    // initialize the pushbutton pin as an input
}

// the loop routine runs over and over again forever:
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  // read the input on analog pin 0:
  int sensorValue = analogRead(A5);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(analogRead(buttonPin));

  switch (buttonState) {
    case 0:
      vibration();
      break;
    case 1:
      buzzer();
      break;
    case 2:
      both(); 
      break;
  }

  if (analogRead(buttonPin) > 999) {
    switchCheck();
  }
}

  void switchCheck() {
    if (buttonState < 2 ) {
      buttonState += 1;
      delay(1000);
    } else {
      buttonState = 0;
      delay(1000);
    }
  }

  void vibration() {
    if (voltage > 1) {
      digitalWrite(9, 255);  //turn on vibrating motor on full by making voltage HIGH
      delay(500);
      } else {
      digitalWrite(9, 0);    // turn the vibrating motor off by making the voltage LOW
    }
  }

  void buzzer() {
    if (voltage > 1) {
      tone(buzzerPin, G);
      delay(delayTime);
      tone(buzzerPin, G);
      delay(delayTime);
      tone(buzzerPin, G);
      delay(delayTime);
      noTone(buzzerPin);
    } else {
      noTone(buzzerPin);
    }
  }

  void both() {
      if (voltage > 1) {
        digitalWrite(9, 255);  //turn on vibrating motor on full by making voltage HIGH
        tone(buzzerPin, G);
        delay(delayTime);
        tone(buzzerPin, G);
        delay(delayTime);
        tone(buzzerPin, G);
        delay(delayTime);
        noTone(buzzerPin);
        delay(500);
      } else {
        digitalWrite(9, 0);    // turn the vibrating motor off by making the voltage LOW
        noTone(buzzerPin);
      }
  }
