#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);

String rfidCard;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the RFID Reader...");
  SPI.begin();
  rfid.init();
  pinMode(8, OUTPUT);
}

void loop() {
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);
      Serial.println(rfidCard);
      if (rfidCard == "224 175 115 31") {
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(8, LOW);
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, HIGH);
        delay(3000);
        digitalWrite(7, LOW);
        delay(3000);
      }else if (rfidCard == "209 10 159 36"){
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(8, LOW);
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, HIGH);
        delay(3000);
        digitalWrite(7, LOW);
        delay(3000);
      } else {
        digitalWrite(6, HIGH);
        delay(3000);
        digitalWrite(6, LOW);
        delay(3000);
      }
    }
    rfid.halt();
  }
}
