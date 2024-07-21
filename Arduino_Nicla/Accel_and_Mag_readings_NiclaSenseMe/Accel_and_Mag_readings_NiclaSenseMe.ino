// A super simple code to see Nicla SenseMe microcontroller in action
#include "Arduino_BHY2.h"

// Initialize sensors
SensorXYZ accel(SENSOR_ID_ACC);
SensorXYZ magnetometer(SENSOR_ID_MAG);

void setup() {
  Serial.begin(115200);
  
  // Initialize the BHY2 library
  if (!BHY2.begin()) {
    Serial.println("Failed to initialize BHY2 library!");
    while (1);
  }

  // Initialize sensors
  accel.begin();
  magnetometer.begin();
}

void loop() {
  // Update function should be continuously polled
  BHY2.update();

  // Print accelerometer values
  Serial.print("Accelerometer - X: ");
  Serial.print(accel.x());
  Serial.print(" Y: ");
  Serial.print(accel.y());
  Serial.print(" Z: ");
  Serial.println(accel.z());

  // Print magnetometer values
  Serial.print("Magnetometer - X: ");
  Serial.print(magnetometer.x());
  Serial.print(" Y: ");
  Serial.print(magnetometer.y());
  Serial.print(" Z: ");
  Serial.println(magnetometer.z());

  // Wait for a short period before reading again
  delay(500);
}
