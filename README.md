# Proyectos de Investigación 2018-2020 UNTREF: 
# Tecnología, mediación cultural y robótica en espacios culturales: una perspectiva crítica

Departamento / Instituto Laboratorio de Arte Electrónico e Inteligencia Artificial

Responsable​ ​del​ ​Proyecto: Director: Miguel​ ​Grassi

Integrantes: 

Mario Alberto Guzmán Cerdio,
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

### NeoPixel Ring - 16 x 5050 RGB LED with Integrated Drivers
https://www.adafruit.com/product/1463

#### Notes: 
NeoPixel LEDs use 800 KHz protocol so specific timing is required. On NeoPixels, the PWM rate is ~400 Hz, which works well but is noticable if the LED is moving.

Please note you will need a NeoPixel library with RGBW support which is not always available. If you try to control these with a plain 'RGB' NeoPixel library, you'll get very weird results. Our Adafruit NeoPixel library does support RGBW but if you're using something else, just be aware that it might require some hacking.

Time: NeoPixels process data from the host microcontroller at a fixed data rate; more pixels = more time and lower animation frame rates.

NeoPixel LEDs use 800 KHz protocol so specific timing is required. On NeoPixels, the PWM rate is ~400 Hz, which works well but is noticable if the LED is moving.

Please note you will need a NeoPixel library with RGBW support which is not always available. If you try to control these with a plain 'RGB' NeoPixel library, you'll get very weird results. Our Adafruit NeoPixel library does support RGBW but if you're using something else, just be aware that it might require some hacking.

Time: NeoPixels process data from the host microcontroller at a fixed data rate; more pixels = more time and lower animation frame rates.

### OLED I2C 128 x 64 (SH1106)
https://github.com/ThingPulse/esp8266-oled-ssd1306

----------------------

## Libraries used:
- ESP32
   Adafruit_ESP8266
- Pixel LED
    Adafruit Circuit Playground
    NeoPixelBus_by_Makuna (Funciona con ESP32)
- OLED I2C
    ESP8266_and_ESP32_Oled_Driver_for_SSD1306_display-4.0.0
    
 


