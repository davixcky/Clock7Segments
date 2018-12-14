#ifndef RELOJ_DISPLAY_H
#define RELOJ_DISPLAY_H

#define PinA1 13
#define PinA2 9
#define PinA3 5
#define PinA4 14

#define PinB1 10
#define PinB2 6
#define PinB3 2
#define PinB4 17

#define PinC1 11
#define PinC2 7
#define PinC3 3
#define PinC4 16

#define PinD1 12
#define PinD2 8
#define PinD3 4
#define PinD4 15

#include "Display.h"

namespace Numeros {
    enum n_0 {
        valueA0 = 0,
        valueB0 = 0,
        valueC0 = 0,
        valueD0 = 0
    };

    enum n_1 {
        valueA1 = 1,
        valueB1 = 0,
        valueC1 = 0,
        valueD1 = 0
    };

    enum n_2 {
        valueA2 = 0,
        valueB2 = 1,
        valueC2 = 0,
        valueD2 = 0
    };

    enum n_3 {
        valueA3 = 1,
        valueB3 = 1,
        valueC3 = 0,
        valueD3 = 0
    };

    enum n_4 {
        valueA4 = 0,
        valueB4 = 0,
        valueC4 = 1,
        valueD4 = 0
    };

    enum n_5 {
        valueA5 = 1,
        valueB5 = 0,
        valueC5 = 1,
        valueD5 = 0
    };

    enum n_6 {
        valueA6 = 0,
        valueB6 = 1,
        valueC6 = 1,
        valueD6 = 0
    };

    enum n_7 {
        valueA7 = 1,
        valueB7 = 1,
        valueC7 = 1,
        valueD7 = 0
    };

    enum n_8 {
        valueA8 = 1,
        valueB8 = 0,
        valueC8 = 0,
        valueD8 = 0
    };

    enum n_9 {
        valueA9 = 1,
        valueB9 = 0,
        valueC9 = 0,
        valueD9 = 1
    };
}

class Display {
    public:
        void begin();
        void test();
        void draw(short number, short port);
        void changeHour(short number);
        void changeMinute(short number);
        void tild(); 
        
        
        short pinA[4] = {10, 6, 2, 17};
        short pinB[4] = {13, 9, 5, 14};
        short pinC[4] = {12, 8, 4, 15};
        short pinD[4] = {11, 7, 3, 16};
        

    private:
        void encender(short port, short numero, short A, short B, short C, short D);
};

#endif //RELOJ_DISPLAY_H
