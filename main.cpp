#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// 1. CREIAMO LA FUNZIONE DI DISEGNO
// Accetta un parametro (true = occhi aperti, false = occhi chiusi)
void disegnaFaccia(bool aperti) {
  // Pulisce il frame precedente (fondamentale per non sovrapporre i disegni)
  display.clearDisplay();

  // La bocca non cambia mai, la disegniamo sempre
  display.fillRect(49, 52, 30, 3, SSD1306_WHITE);

  // Decidiamo come disegnare gli occhi in base alla variabile 'aperti'
  if (aperti) {
    // Occhi aperti: Rettangoli alti
    display.fillRoundRect(30, 20, 20, 25, 4, SSD1306_WHITE);
    display.fillRoundRect(78, 20, 20, 25, 4, SSD1306_WHITE);
  } else {
    // Occhi chiusi: Linee sottili (abbassiamo la Y a 30 per simulare la
    // palpebra che scende)
    display.fillRoundRect(30, 30, 20, 4, 2, SSD1306_WHITE);
    display.fillRoundRect(78, 30, 20, 4, 2, SSD1306_WHITE);
  }

  // Spara i nuovi pixel allo schermo
  display.display();
}

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Errore: allocazione SSD1306 fallita"));
    for (;;)
      ;
  }

  // Disegna la faccia ad occhi aperti appena si accende la scheda
  disegnaFaccia(true);
}

void loop() {
  // 2. VARIABILI DI STATO STATICHE
  // 'static' fa in modo che il loro valore non venga distrutto alla fine di
  // ogni loop
  static unsigned long tempoUltimoEvento = 0;
  static bool occhiAperti = true;

  unsigned long tempoAttuale = millis();

  // 3. LA MACCHINA A STATI FINITI (Non-bloccante)
  if (occhiAperti) {
    // Se gli occhi sono aperti, vogliamo aspettare 3 secondi (3000 ms)
    if (tempoAttuale - tempoUltimoEvento >= 3000) {
      occhiAperti = false;              // Cambiamo stato
      disegnaFaccia(occhiAperti);       // Aggiorniamo lo schermo
      tempoUltimoEvento = tempoAttuale; // Resettiamo il cronometro
    }
  } else {
    // Se gli occhi sono chiusi (il battito di ciglia), aspettiamo solo una
    // frazione di secondo (150 ms)
    if (tempoAttuale - tempoUltimoEvento >= 150) {
      occhiAperti = true;               // Riapriamo gli occhi
      disegnaFaccia(occhiAperti);       // Aggiorniamo lo schermo
      tempoUltimoEvento = tempoAttuale; // Resettiamo il cronometro
    }
  }

  // Qui sotto il loop continua a girare a milioni di cicli al secondo senza mai
  // fermarsi. In futuro potrai aggiungere la lettura dei sensori o il controllo
  // dei motori qui.
}
