// Digital potentiometer pins
const int udPin = 7;   // U/D (Up/Down)
const int incPin = 8;  // INC (Increment)
const int csPin = 9;   // CS (Chip Select)

// Analog pin for voltage reading
const int rwPin = A0;  // Analog pin to read from RW (Wiper)

// Time delay between INC pulses
const int incDelay = 10;
const int csDelay = 10;

// Function to initialize the potentiometer and Serial Monitor
void setup() {
  Serial.begin(9600);  // Set baud rate for serial communication

  // Set pin modes
  pinMode(udPin, OUTPUT);
  pinMode(incPin, OUTPUT);
  pinMode(csPin, OUTPUT);
  pinMode(rwPin, INPUT);

  digitalWrite(csPin, HIGH); // Start with chip deselected
  Serial.println("Setup complete.");
}

// Function to change resistance by a given number of steps
void changeResistance(bool increase, int steps) {
  digitalWrite(udPin, increase ? HIGH : LOW); // Set direction
  digitalWrite(csPin, LOW);  // Enable chip

  for (int i = 0; i < steps; i++) {
    digitalWrite(incPin, LOW);
    delay(incDelay);
    digitalWrite(incPin, HIGH);
    delay(incDelay);
  }

  digitalWrite(csPin, HIGH); // Save to memory
  Serial.print(increase ? "Increased" : "Decreased");
  Serial.print(" resistance by ");
  Serial.print(steps);
  Serial.println(" steps.");
}

// Function to read and display the voltage at the wiper
void readVoltage() {
  int analogValue = analogRead(rwPin);  // Read analog value from the wiper
  float voltage = analogValue * (5.0 / 1023.0);  // Convert to voltage assuming a 5V reference
  Serial.print("Wiper voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
}

// Example loop to periodically change resistance and read voltage
void loop() {
  changeResistance(true, 10);  // Increase resistance
  delay(1000);  // Wait for 1 second
  readVoltage();  // Read and display voltage
  delay(1000);  // Wait for 1 second

  changeResistance(false, 10);  // Decrease resistance
  delay(1000);  // Wait for 1 second
  readVoltage();  // Read and display voltage
  delay(1000);  // Wait for 1 second
}
