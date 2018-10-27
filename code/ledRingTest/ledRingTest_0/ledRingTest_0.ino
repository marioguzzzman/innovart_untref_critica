#include <NeoPixelBus.h>;

const uint16_t pixelCount = 16; // make sure to set this to the number of pixels in your strip
const uint8_t pixelPin = 2;  // make sure to set this to the correct pin, ignored for Esp8266

NeoPixelBus<NeoGrbwFeature, Neo800KbpsMethod> leds(pixelCount, pixelPin);
//RgbwColor colores[pixelCount];
HsbColor colores[pixelCount];


int counter = 0;
float counterNorm = 0; // El rango de HsbColor es 0 -> 1;

const uint8_t modeButtonPin = 32;
uint8_t atMode = 0;

void setup() {

  Serial.begin(9600);

  pinMode(modeButtonPin, INPUT);

  for (uint8_t i = 0; i < pixelCount; i++ ) {
    colores[i] = HsbColor( (1.0 / pixelCount) * i, 1 , 1);
    Serial.println(colores[i].H);
    //colores[i] = RgbwColor( 0, 20 , 0, 0 );
  }

  leds.Begin();
  leds.Show();
}

void loop() {

  if (digitalRead(modeButtonPin) == HIGH)selectMode();


  runMode(atMode);

  delay(10);

}

void arcoIrisRotando() {

  counter = (counter + 1) % 256;
  counterNorm = counter / 256.0;

  //RgbwColor fade(counter,0,0,0);

  for (uint8_t i = 0; i < pixelCount; i++ ) {
    leds.SetPixelColor(i, HsbColor(colores[i].H + counterNorm, colores[i].S, colores[i].B));
  }

  leds.Show();

}

void off() {

  for (uint8_t i = 0; i < pixelCount; i++ ) {
    leds.SetPixelColor(i, HsbColor(0, 0, 0));
  }

  leds.Show();

  //delay(1000);

}

void arcoIrisControl() {

  int potControl = analogRead(36); // ADCgroup_1, 12-bit (0 -> 4095) /// (ADCgroup2) cannot be use when using wiFi.

  int offset = potControl % 4096;
  float offsetNorm = offset / 4096.0;

    Serial.println("-|| CONTROL");
    Serial.print("RAW: ");
    Serial.println(potControl);
    Serial.print("OFFSET INT: ");
    Serial.println(offset);
    Serial.print("OFFSET NORM: ");
    Serial.println(offsetNorm);


  for (uint8_t i = 0; i < pixelCount; i++ ) {
    leds.SetPixelColor(i, HsbColor(colores[i].H + offsetNorm, colores[i].S, colores[i].B));
  }

  leds.Show();


}

void runMode(int m) {

  switch (m) {
    case 0:
      arcoIrisRotando();
      break;
    case 1:
      off();
      break;
    case 2:
      arcoIrisControl();
      break;
    default:
      break;
  }
}

void selectMode() {
  atMode = (atMode + 1) % 3;
  delay(200);
}

