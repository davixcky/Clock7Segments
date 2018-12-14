#include "Display.h"
#include "Arduino.h"

void Display::begin() {
   Serial.println("Inicializando displays...");
 
    for (short i = 0; i < 4; i++) {
        pinMode(pinA[i], OUTPUT);
        pinMode(pinB[i], OUTPUT);
        pinMode(pinC[i], OUTPUT);
        pinMode(pinD[i], OUTPUT);
    }
}

void Display::test() {
    /*digitalWrite(pinA[0], 1);
    digitalWrite(pinB[0], 0);
    digitalWrite(pinC[0], 0);
    digitalWrite(pinD[0], 1);*/
    draw(2, 1);
    draw(2, 2);
    draw(2, 3);
    draw(2, 4);

}

void Display::draw(short number, short port) { 
    short A, B, C, D = 0;
    switch (number) {
        case 0:
            A = B = C = D = 0;
            break;
        
        case 1:
            A = 1;
            B = C = D = 0;
            break;
        
        case 2:
            B = 1;
            A = C = D = 0;
            break;
        
        case 3:
            A = B = 1;
            C = D = 0;
            break;

        case 4: 
            C = 1;
            A = B = D = 0;
            break;

        case 5: 
            C = A = 1;
            B = D = 0;
            break;
        
        case 6:
            B = C = 1;
            A = D = 0;
            break;

        case 7:
            A = B = C = 1;
            D = 0;
            break;

        case 8: 
            D = 1;
            A = B = C = 0;
            break;
        
        case 9: 
            D = A = 1;
            B = C = 0;
            break;

    }


    encender(port, number, A, B, C, D);
}

void Display::changeHour(short number) {
    if (number == 0) {
        draw(0, 1);
        draw(0, 2);
        return;
    }

    if (number < 10) {   
        draw(0, 1);
        draw(number, 2);
        return;
    }

    auto dig1 = number / 10;
    auto dig2 = number - dig1 * 10;

    draw(dig1, 1);
    draw(dig2, 2);

}

void Display::changeMinute(short number) {
    if (number == 0) {
        draw(0, 3);
        draw(0, 4);
        return;
    }

    if (number < 10) {   
        draw(0, 3);
        draw(number, 4);
        return;
    }

    auto dig1 = number / 10;
    auto dig2 = number - dig1 * 10;

    draw(dig1, 3);
    draw(dig2, 4);
}

void Display::tild() {
    for (short i = 0; i < 4; i++) {
        encender(i+1, 0, 0, 0, 0, 0);
    }
}

//Numero = valor a mostrar     
//Port = pantalla a cambiar
//ej: pinA[0] pantalla a cambiar
//ej: 4 valor a mostrar

void Display::encender(short port, short numero, short A, short B, short C, short D) {
    digitalWrite(pinA[port-1], A);
    digitalWrite(pinB[port-1], B);
    digitalWrite(pinC[port-1], C);
    digitalWrite(pinD[port-1], D);
}


