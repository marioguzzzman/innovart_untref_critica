# Proyectos de Investigación 2018-2020 UNTREF:
# Tecnología, mediación cultural y robótica en espacios culturales: una perspectiva crítica

Instituto Laboratorio de Arte Electrónico e Inteligencia Artificial

Responsable​ ​del​ ​Proyecto: Miguel​ ​Grassi

Integrantes: Mario Alberto Guzmán Cerdio,
Agustín Ramos Anzorena,
Paula Valeria Guersenzvaig,
Juán Camilo León Sarmiento,
Laura Constanza Casamadrid Iglesias,
Mariana Lombard,
Luis Carlos Molina Pacalagua.

## Resumen:
El proyecto pretende analizar el vínculo contemporáneo entre público y espacios
expositivos (museos, galerías, centros culturales, etc) mediado por la tecnología. Se
plantea entonces un análisis de este vínculo a partir de un estudio de campo y
herramientas estadísticas que permitan potenciar los relatos curatoriales haciendo un uso
crítico e informado de recursos tecnológicos. El proyecto pretende hacer disponible la
investigación a diversos agentes de la cultura e implementar directamente sus resultados
dentro del marco del proyecto internacional INNOVART, ya aprobado y en curso.

## Componentes utilizados para un primer prototipo:

### ESP32Dev Board
https://github.com/espressif/arduino-esp32

ESP32Dev Board PINMAP
Pin Functions

![ESP32Dev Board PINMAP](https://github.com/espressif/arduino-esp32/raw/master/docs/esp32_pinmap.png)

#### Hint
Sometimes to program ESP32 via serial you must keep GPIO0 LOW during the programming process

---
#### Configuracion de Arduino IDE para cargar/programar el ESP32
* Board: ESP32 Dev Module
* Programmer: AVRISP mkII
* Port: MacOS => xxxxxx.SLAB_USBtoUART

---

### NeoPixel Ring - 16 x 5050 RGB LED with Integrated Drivers
https://www.adafruit.com/product/1463

#### Notes:
NeoPixel LEDs use 800 KHz protocol so specific timing is required. On NeoPixels, the PWM rate is ~400 Hz, which works well but is noticable if the LED is moving.

Please note you will need a NeoPixel library with RGBW support which is not always available. If you try to control these with a plain 'RGB' NeoPixel library, you'll get very weird results. Our Adafruit NeoPixel library does support RGBW but if you're using something else, just be aware that it might require some hacking.

Time: NeoPixels process data from the host microcontroller at a fixed data rate; more pixels = more time and lower animation frame rates.

NeoPixel LEDs use 800 KHz protocol so specific timing is required. On NeoPixels, the PWM rate is ~400 Hz, which works well but is noticable if the LED is moving.

Please note you will need a NeoPixel library with RGBW support which is not always available. If you try to control these with a plain 'RGB' NeoPixel library, you'll get very weird results. Our Adafruit NeoPixel library does support RGBW but if you're using something else, just be aware that it might require some hacking.

Time: NeoPixels process data from the host microcontroller at a fixed data rate; more pixels = more time and lower animation frame rates.

----------------------

### OLED I2C 128 x 64 (SH1106)
https://github.com/ThingPulse/esp8266-oled-ssd1306

#### => Setup para la pantallita que tenemos: 1.3' OLED (protocolo I2C (via Wire))

**Se utiliza I2C con Wire (no con brzo_i2c):**

#include `<`Wire.h`>`  
#include "SH1106Wire.h"

**// Include custom images (Este es un archivo aparte, en el mismo directorio, que describe una imagen a partir del seteo en HEX de cada pixel)**
#include "images.h"


**// Initialize the OLED display using Wire library  
// En ESP32 NodeMCU, los pines SDA y SCL son:  
// 21 -> SDA  
// 22 -> SCL**  
SH1106Wire display(0x3c, 21, 22);

void setup(){
   display.init();
}

#### Para usar diferentes tipografias:
Se deben definir en un Header File aparte.
1. Generar el fontFile aqui: http://oleddisplay.squix.ch/#/home.
Parametros: OLED 0.96", Library version: >=3.0.0
2. Crear un archivo "miFont.h" (misma carpeta), y copiar el codigo generado.
3. Dentro del archivo, reemplazer el tipo de dato en la declaracion. En vez de "char", usar "uint8_t".
4. En el codigo Principal de Arduino, ingresar el include: #include "miFont.h"
5. Durante el codigo, usarlo asi: display.setFont(nombreDeLaFont);



----------------------

## Libraries used:
- ESP32
   Adafruit_ESP8266
- Pixel LED
    Adafruit Circuit Playground
    NeoPixelBus_by_Makuna (Funciona con ESP32)
- OLED I2C
    ESP8266_and_ESP32_Oled_Driver_for_SSD1306_display-4.0.0
