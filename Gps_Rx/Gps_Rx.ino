#include <AltSoftSerial.h>

AltSoftSerial LoRaSerial;

void setup() {
  Serial.begin(115200);
  LoRaSerial.begin(115200); // Set the LoRa baud rate to 9600

  Serial.println("LoRa Receiver");
}

void loop() {
  // Check for incoming data
  if (LoRaSerial.available() > 0) {
    String dataString = LoRaSerial.readStringUntil('\n');
    Serial.print("Received data: \n");
    Serial.println(dataString);

    // Parse the received data
    if (dataString.startsWith("+RCV=")) {
      // Remove the "+RCV=" part
      dataString = dataString.substring(5);

      // Split the data by commas
      int index1 = dataString.indexOf(',');
      int index2 = dataString.indexOf(',', index1 + 1);
      int index3 = dataString.indexOf(',', index2 + 1);
      int index4 = dataString.indexOf(',', index3 + 1);
      int index5 = dataString.indexOf(',', index4 + 1);

      String port = dataString.substring(0, index1);
      String length = dataString.substring(index1 + 1, index2);
      String latitude = dataString.substring(index2 + 1, index3);
      String longitude = dataString.substring(index3 + 1, index4);
      String rssi = dataString.substring(index4 + 1, index5);
      String snr = dataString.substring(index5 + 1);

      // Print parsed data
      Serial.print("Latitude: ");
      Serial.println(latitude);
      Serial.print("Longitude: ");
      Serial.println(longitude);
    }
  }

  
}

