/**
 * PWM Generator Control via SoftwareSerial and CD74HC4067 Multiplexer
 * 
 * This Arduino sketch demonstrates controlling a PWM generator using commands sent through SoftwareSerial.
 * It uses a CD74HC4067 multiplexer to select between multiple PWM generators, allowing the single Arduino
 * to control various devices. The sketch initializes by setting a default frequency and duty cycle, then
 * cycles through a range of frequencies and duty cycles to demonstrate PWM control.
 *
 * Setup:
 * - Pins 2, 3, 4, 5 control the multiplexer for channel selection.
 * - Pins 10 and 11 are used for SoftwareSerial communication with the PWM generator.
 * - The 'selectChannel' function is used to switch the active channel on the multiplexer.
 * - 'setFrequency' and 'setDutyCycle' functions send formatted commands to set the PWM generator's frequency and duty.
 *
 * Usage:
 * - Adjust 'setFrequency' and 'setDutyCycle' within the loop for different test scenarios.
 * - Monitor outputs via the Serial Monitor to confirm commands are sent correctly.
 *
 * Note:
 * This script is tailored for a PWM generator that accepts specific serial commands to set frequency and duty cycle,
 * as per the device's communication protocol (e.g., "F1.00" for 1.00 kHz and "D050" for 50% duty).
 */


#include <SoftwareSerial.h>

// Define the multiplexer control pins
const int s0 = 2;
const int s1 = 3;
const int s2 = 4;
const int s3 = 5;

// Define the software serial pins
const int rxPin = 10;
const int txPin = 11;

// Create the SoftwareSerial object
SoftwareSerial mySerial(rxPin, txPin);

// Define an array of the control pins
int controlPins[] = {s0, s1, s2, s3};

// Function to select the channel on the multiplexer
void selectChannel(int channel) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(controlPins[i], (channel >> i) & 1);
  }
}

void setup() {
  // Set the control pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(controlPins[i], OUTPUT);
  }

  // Set up the SoftwareSerial communication
  Serial.begin(9600);
  mySerial.begin(9600);

  delay(1000);  // Wait for module to initialize

  // Select the first channel (C0)
  selectChannel(0);

  // Set initial frequency and duty cycle
  setFrequency("1.00"); // Set frequency to 1.00 kHz
  delay(1000);
  setDutyCycle(50); // Set duty cycle to 50%
}

void loop() {
  // This loop can be used to further test and debug the frequency and duty cycle setting
  for (float freq = 1.00; freq <= 10.0; freq += 1.00) {
    setFrequency(String(freq, 2)); // Set frequency from 1.00 kHz to 10.0 kHz
    delay(5000);  // Wait for 5 seconds before changing frequency

    for (int duty = 10; duty <= 90; duty += 10) {
      setDutyCycle(duty);  // Ensure 3-digit format
      delay(5000);  // Wait for 5 seconds before changing duty cycle
    }
  }
}

void setFrequency(String frequency) {
  // Format the command for frequency
  String command = "F" + frequency;
  mySerial.println(command);
  Serial.println("Frequency set to: " + command);
}

void setDutyCycle(int duty) {
  // Ensure the duty cycle is formatted to three digits
  String dutyStr = String(duty);
  if (duty < 10) {
    dutyStr = "00" + dutyStr;
  } else if (duty < 100) {
    dutyStr = "0" + dutyStr;
  }
  // Format the command for duty cycle
  String command = "D" + dutyStr;
  mySerial.println(command);
  Serial.println("Duty cycle set to: " + command);
}
