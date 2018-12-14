#ifndef RELOJ_PULSADORES_H
#define RELOJ_PULSADORES_H

#define P1 18  //SUBIR
#define P2 19  //BAJAR

#define LED 13
#define LED2 9

#define PRESIONADO LOW

#include <Arduino.h>
#include "Display.h"
#include "Reloj.h"

class Pulsadores {
    public:
        void begin();
        void main();
        void main2();
        void changeHour();   
        void changeMinute(); 
    
    private:
        Display display;
        Reloj reloj;
        
        bool edit = true;

        bool antirrebote(short pin);

        //short cuenta = 0;
        short estadoPulsadorIncremento;
        short estadoPulsadorAnteriorIncremento;
        short estadoPulsadorDecremento;
        short estadoPulsadorAnteriorDecremento;

        const short pulsadorIncremento = 18; // Pin digital para el pulsador de incremento
        const short pulsadorDecremento = 19; // Pin digital para el pulsador de decremento
        const short tiempoAntirrebote = 10; // Variable para almacenar el tiempo antirrebote
};

#endif //RELOJ_PULSADORES_H
