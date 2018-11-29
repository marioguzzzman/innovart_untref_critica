#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SH1106Wire.h"//, legacy include: `#include "SH1106.h"

// Include custom images // This is an external .h file (in the same folder) that describes an image in HEX.
#include "images.h"

#include "font.h"

// Initialize the OLED display using Wir6e library
// D3 -> SDA
// D5 -> SCL
//SSD1306Wire  display(0x3c, 21, 22);
SH1106Wire display(0x3c, 21, 22);

String menuOptions[2][4] = {{"A1", "A2", "A3", "A4"}, {"B1", "B2", "B3", "B4"}};
int atMenu = 0;

const uint8_t modeButtonPin = 32;


void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  pinMode(modeButtonPin, INPUT);

  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(Roboto_Condensed_14);

}

void loop() {
  // clear the display
  display.clear();

  if (digitalRead(modeButtonPin) == HIGH)selectMenu();
  drawOptions(atMenu);

  // write the buffer to the display
  display.display();

  delay(10);
}

void drawOptions(int menuIndex) {

  display.setFont(Roboto_Condensed_14);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 10, menuOptions[menuIndex][0]);
  display.drawString(0, 40, menuOptions[menuIndex][1]);
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(128, 10, menuOptions[menuIndex][2]);
  display.drawString(128, 40, menuOptions[menuIndex][3]);


}

void selectMenu() {
  atMenu = (atMenu + 1) % 2;
  Serial.println(atMenu);
  delay(250);
}

