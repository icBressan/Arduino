// Inclui a biblioteca LedControl para controle da matriz de LEDs
#include <LedControl.h>

// Define os pinos utilizados para comunicação com a matriz de LEDs
#define DIN 12 
#define CLK 11
#define CS 10

// Declaração de variáveis
int pot, pot2, col, ale, i;

// Cria um objeto LedControl chamado 'lc' com os pinos definidos acima
LedControl lc = LedControl(DIN, CLK, CS, 0);

void setup() 
{
  // Inicia a comunicação serial com uma taxa de transmissão de 9600 bits por segundo
  Serial.begin(9600);
  
  // Desativa o modo de desligamento da matriz de LEDs
  lc.shutdown(0, false);
  
  // Define a intensidade da luz dos LEDs
  lc.setIntensity(0, 8);
  
  // Limpa o display, desligando todos os LEDs
  lc.clearDisplay(0);
}

void loop() 
{
  // Lê o valor do primeiro potenciômetro conectado à entrada analógica 0
  pot = analogRead(0);
  
  // Mapeia o valor lido do potenciômetro para um valor entre 0 e 6, representando uma linha na matriz de LEDs
  pot = map(pot, 0, 1010, 0, 6);
  
  // Imprime o valor do potenciômetro lido no monitor serial
  Serial.println(pot);
  
  // Acende dois LEDs consecutivos na linha correspondente ao valor lido pelo primeiro potenciômetro
  lc.setRow(0, pot, 1);
  lc.setRow(0, pot + 1, 1);
  
  // Lê o valor do segundo potenciômetro conectado à entrada analógica 1
  pot2 = analogRead(1);
  
  // Mapeia o valor lido do potenciômetro para um valor entre 0 e 6, representando uma linha na matriz de LEDs
  pot2 = map(pot2, 0, 1010, 0, 6);
  
  // Imprime o valor do segundo potenciômetro lido no monitor serial
  Serial.println(pot2);
  
  // Acende dois LEDs consecutivos na linha correspondente ao valor lido pelo segundo potenciômetro, com um brilho diferente
  lc.setRow(0, pot2, 128);
  lc.setRow(0, pot2 + 1, 128);
  
  // Limpa o display, desligando todos os LEDs
  lc.clearDisplay(0);
}
