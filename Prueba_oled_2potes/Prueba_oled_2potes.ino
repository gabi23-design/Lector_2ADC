#include <ssd1306.h>
#include <nano_gfx.h>

int pot1 = 0;  // entrada pote 1 a A0
int pot2 = 0;  // entrada pote 2 a A1

void setup() {
  ssd1306_128x64_i2c_init();              // inicio screen
  ssd1306_clearScreen();                  // limpio screen
  ssd1306_setFixedFont(ssd1306xled_font6x8);
  ssd1306_printFixed(0,  0, "Lectura de Pot.", STYLE_BOLD);
}

void loop() {
  
  pot1 = analogRead(A0);  
  pot2 = analogRead(A1);

  // convierto a string para mostrar
  char buffer1[20];
  char buffer2[20];
  sprintf(buffer1, "A0: %4d", pot1);
  sprintf(buffer2, "A1: %4d", pot2);

  // muestro en pantalla
  ssd1306_printFixed(0, 20, "                ", STYLE_NORMAL);  // limpio linea
  ssd1306_printFixed(0, 30, "                ", STYLE_NORMAL);

  ssd1306_printFixed(0, 20, buffer1, STYLE_NORMAL);
  ssd1306_printFixed(0, 30, buffer2, STYLE_NORMAL);

  delay(200); // Actualización cada 200 ms
}

