
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // Larghezza del display in pixel
#define SCREEN_HEIGHT 64 // Altezza del display in pixel

// Creazione dell'oggetto display collegato via I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  // Inizializza lo schermo all'indirizzo 0x3C trovato dal tuo scanner
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Errore: allocazione SSD1306 fallita"));
    for (;;)
      ; // Blocca il codice qui se lo schermo non viene trovato
  }

  // Pulisce la memoria video da eventuali loghi di default
  display.clearDisplay();

  // Imposta il colore bianco per i disegni (l'OLED spegne i pixel neri)
  display.setTextColor(SSD1306_WHITE);

  // --- DISEGNO DELLA FACCIA DI BMO ---

  // Occhio Sinistro: Rettangolo arrotondato pieno (x, y, larghezza, altezza,
  // raggio curva, colore)
  display.fillRoundRect(30, 20, 20, 25, 4, SSD1306_WHITE);

  // Occhio Destro
  display.fillRoundRect(78, 20, 20, 25, 4, SSD1306_WHITE);

  // Bocca: Linea orizzontale (x, y, larghezza, altezza, colore)
  display.fillRect(49, 52, 30, 3, SSD1306_WHITE);

  // Manda tutto il disegno dalla memoria dell'ESP32 allo schermo fisico
  display.display();
}

void loop() {
  // Per ora l'espressione è statica, il loop è vuoto
}