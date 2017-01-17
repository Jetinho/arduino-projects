/*
  Light metronome :
  You define your tempo and time signature (beats per bar only) and your Arduino board will turn into a metronome.
  The green LED lights up on the first beat of each bar, and the red one on every other beats.
  You can also set up the light pulse duration with the pulseDelay variable.
  
  modified 17 Jan 2016
  by Julien Jet
  Based on Arduino Blink example (Examples - 01. Basics - Blink)
  
*/

int greenLedPin = 13;
int redLedPin = 12;
int tempo = 100; // (bpm - beats per minute)
int bpb = 4; // beats per bar
int timeDelay = 60000 / tempo;
int pulseDelay = timeDelay * 4 / 10;
int offDelay = timeDelay - pulseDelay;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins greenLedPin and redLedPin as outputs.
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // First pulse
  digitalWrite(greenLedPin, HIGH);    // turn the green LED on
  // digitalWrite(redLedPin, LOW);    // turn the red LED off
  delay(pulseDelay);                  // Define the pulse time
  digitalWrite(greenLedPin, LOW);     // turn the green LED off
  delay(offDelay);                    // Define the off time

  // Secondary pulses  
  for (int i = 0 ; i < (bpb - 1) ; i++){
    digitalWrite(redLedPin, HIGH);      // turn the red LED on
    delay(pulseDelay);                  // Define the pulse time
    digitalWrite(redLedPin, LOW);       // turn the red LED off
    delay(offDelay);                    // Define the off time
  }
}
