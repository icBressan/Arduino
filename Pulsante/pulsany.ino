#include <LedControl.h> // biblioteca para controle da matriz de leds
#define DIN 8 
#define CLK 10 
#define CS 9

LedControl lc=LedControl(DIN,CLK,CS,0); 

void setup() 
{
  // Configura a matriz de LEDs para não estar em modo de desligamento
    lc.shutdown(0, false);
  // Define a intensidade da luz dos LEDs
    lc.setIntensity(0, 8);
  // Limpa o display, desligando todos os LEDs
    lc.clearDisplay(0); 
}

void loop() 
{
   lc.setRow (0,0,255);// Primeira linha com todos os LEDs acesos
  lc.setRow(0,7,255); // Última linha com todos os LEDs acesos
   lc.setRow (0,1,129);
   lc.setRow (0,2,129);
   lc.setRow (0,3,129);
   lc.setRow (0,4,129);
   lc.setRow (0,5,129);
   lc.setRow (0,6,129);
    delay (100);
   lc.clearDisplay(0);

// Move para cima 
   lc.setRow (0,1,126);
   lc.setRow (0,2,66);
   lc.setRow (0,3,66);
   lc.setRow (0,4,66);
   lc.setRow (0,5,66);
   lc.setRow (0,6,126);
    delay(100);
   lc.clearDisplay(0);
 
// Repete o processo até que a forma desapareça completamente da matriz de LEDs
   lc.setRow (0,2,60);
   lc.setRow (0,3,36);
   lc.setRow (0,4,36);
   lc.setRow (0,5,60);
    delay(100);
   lc.clearDisplay(0);

   lc.setRow (0,3,24);
   lc.setRow (0,4,24);
    delay(100);
   lc.clearDisplay(0);

   lc.setRow (0,2,60);
   lc.setRow (0,3,36);
   lc.setRow (0,4,36);
   lc.setRow (0,5,60);
    delay(100);
   lc.clearDisplay(0);

   lc.setRow (0,1,126);
   lc.setRow (0,2,66);
   lc.setRow (0,3,66);
   lc.setRow (0,4,66);
   lc.setRow (0,5,66);
   lc.setRow (0,6,126);
    delay(100);
  lc.clearDisplay(0); 
 }
