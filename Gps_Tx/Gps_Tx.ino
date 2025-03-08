#include <AltSoftSerial.h>

AltSoftSerial LoRaSerial;

void setup() {
  Serial.begin(115200);
  LoRaSerial.begin(115200); // Set the LoRa baud rate to 9600

  Serial.println("LoRa Transmitter");
}

void loop() {
  // Assuming you have a GPS module connected to the Arduino
  // and you have read the latitude and longitude values
  float latitude = 13.7072;
  float longitude = 79.5945;

  // Construct the message string
  String message = String(latitude, 7) + "," + String(longitude, 7);

  // Construct the command to send the message
  String command = "AT+SEND=2," + String(message.length()) + "," + message;

  // Send the command to the LoRa module
  LoRaSerial.println(command);

  // Print to Serial Monitor for debugging
  Serial.println("Data sent: " + message);

  // Delay before sending the next message
  delay(1000);
}

