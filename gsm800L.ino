#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1); // Use hardware serial (TX, RX) on default pins (GPIO1 and GPIO3)
  Serial.println("Setup complete");
}
/*
void loop() {
  // Send an AT command to check the SIM800L status
  Serial1.println("AT");

  // Wait for the response
  delay(1000);

  // Print the response to the Serial Monitor
  while (Serial1.available()) {
    char c = Serial1.read();
    Serial.write(c);
  }*/
void loop() {
  // Send an AT command to check the SIM card status
  Serial.println("Sending AT+CPIN? command...");
  Serial1.println("AT+CPIN?");

  // Wait for the response
  delay(1000);

  // Print the response to the Serial Monitor
  Serial.println("Response from SIM800L:");
  while (Serial1.available()) {
    char c = Serial1.read();
    Serial.write(c);
  }

  // Wait for a moment before sending the next command
  delay(5000);
}