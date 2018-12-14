#include "Pulsadores.h"

void Pulsadores::begin() {
  Serial.println("Inicializando pulsadores...");

  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
}

// Presiono el pulsador, entra en el menu, presionar largo y
// corto para los submenus

void Pulsadores::main() {
  auto buttonState = digitalRead(pulsadorDecremento);
    auto buttonState2 = digitalRead(pulsadorIncremento);

  //mandar mensaje a puerto serie en función del valor leido
  if ((buttonState == LOW) && (buttonState2 == LOW)) {
    Serial.println("Presionado");
    display.tild();
    digitalWrite(LED, 1);
    auto duracion = pulseIn(P1, LOW, 20000000);
    
    if (duracion == 0) {
        return;
    }
    else if (duracion > 2000000) {
      digitalWrite(LED, 1);
      //display.tild();
      changeHour();
      return;

    } else {
      digitalWrite(LED, 1);
      changeMinute();
    }
  }
}

void Pulsadores::main2() {
  auto buttonState = digitalRead(pulsadorDecremento);
  auto buttonState2 = digitalRead(pulsadorIncremento);

  //mandar mensaje a puerto serie en función del valor leido
  if ((buttonState == LOW) && (buttonState2 == LOW)) {
    Serial.println("Presionado");
    display.tild();
    digitalWrite(LED, 1);
    auto duracion = pulseIn(P2, LOW, 20000000);
    
    if (duracion == 0) {
        return;
    }
    else if (duracion > 2000000) {
      digitalWrite(LED, 1);
      //display.tild();
      changeMinute();
      return;

    } 
  }
}

bool Pulsadores::antirrebote(short pin) {
  short contador = 0;
  boolean estado;
  boolean estadoAnterior;
  

  do
  {
    estado = digitalRead(pin);
    if (estado != estadoAnterior)
    {
      contador = 0;
      estadoAnterior = estado;
    }
    else
    {
      contador = contador + 1;
    }
    delay(1);
  } while (contador < tiempoAntirrebote);

  return estado;
}

void Pulsadores::changeHour() {
  auto hour = reloj.getHour(); 
  Serial.println("Editando hora");
  display.draw(0, 1);
  display.draw(0, 2);
  
  while (true) {
    estadoPulsadorIncremento = digitalRead(pulsadorIncremento);
    if (estadoPulsadorIncremento != estadoPulsadorAnteriorIncremento) {
      if (antirrebote(pulsadorIncremento)) {
        hour++;
        if (hour > 23) {
          hour = 23;
        }
      }
    }

    estadoPulsadorAnteriorIncremento = estadoPulsadorIncremento;

    estadoPulsadorDecremento = digitalRead(pulsadorDecremento);

    if (estadoPulsadorDecremento != estadoPulsadorAnteriorDecremento) {
      if (antirrebote(pulsadorDecremento)) {
        hour--;
        if (hour < 0) {
          hour = 0;
        }
      }
    }

    estadoPulsadorAnteriorDecremento = estadoPulsadorDecremento;

    display.changeHour(hour);

    auto buttonState = digitalRead(pulsadorDecremento);
    auto buttonState2 = digitalRead(pulsadorIncremento);

    if ((buttonState == LOW) && (buttonState2 == LOW)){
        break;
    }

  }

  reloj.adjustHour(hour);


}

void Pulsadores::changeMinute() {
    auto minute = reloj.getMinute(); 
    Serial.println("Editando hora");
    
   
   display.draw(0, 3);
   display.draw(0, 4);

  while (true) {
    estadoPulsadorIncremento = digitalRead(pulsadorIncremento);
    if (estadoPulsadorIncremento != estadoPulsadorAnteriorIncremento) {
      if (antirrebote(pulsadorIncremento)) {
        minute++;
        if (minute > 59) {
          minute = 59;
        }
      }
    }

    estadoPulsadorAnteriorIncremento = estadoPulsadorIncremento;

    estadoPulsadorDecremento = digitalRead(pulsadorDecremento);

    if (estadoPulsadorDecremento != estadoPulsadorAnteriorDecremento) {
      if (antirrebote(pulsadorDecremento)) {
        minute--;
        if (minute < 0) {
          minute = 0;
        }
      }
    }

    estadoPulsadorAnteriorDecremento = estadoPulsadorDecremento;

    display.changeMinute(minute);

    auto buttonState = digitalRead(pulsadorDecremento);
    auto buttonState2 = digitalRead(pulsadorIncremento);

    if ((buttonState == LOW) && (buttonState2 == LOW)){
        break;
    }


  }

  reloj.adjustMinute(minute);
}
