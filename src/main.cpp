#include <Arduino.h>
#include "Display.h"
#include "Reloj.h"
#include "Pulsadores.h"

Pulsadores pulsador;
Display display;
Reloj reloj;


void setup() {

  Serial.begin(9600);  
  delay(100);

  Serial.println("Inicializando...");
  display.begin();
  pulsador.begin();
  reloj.begin();
  delay(1000);
}


void loop() {
  //display.test();
  //reloj.adjustHour(4);
  //reloj.adjustMinute(30);
  pulsador.main();
  delay(100);
  //pulsador.main2();
  //delay(100);

    
  auto h1 = reloj.getDigit1Hour();
  auto h2 = reloj.getDigit2Hour();
  auto m1 = reloj.getDigit1Minute();
  auto m2 = reloj.getDigit2Minute();

  pulsador.main();
  delay(100);
  //pulsador.main2();
  //delay(100);


  pulsador.main();
  delay(100);
  //pulsador.main2();
  //delay(100);

  display.draw(h1, 1);
  display.draw(h2, 2);
  display.draw(m1, 3);
  display.draw(m2, 4);

  pulsador.main();
  delay(100);
  //pulsador.main2();
  //delay(100);

  //pulsador.changeHour2();
}
