#ifndef RELOJ_RELOJ_H
#define RELOJ_RELOJ_H

#include <Wire.h>
#include "RTClib.h"

class Reloj {
    public:
        void begin();
        void adjustHour(short hour);
        void adjustMinute(short minute);
        short getDigit1(short time);
        short getDigit2(short time, short digit1);

        short getDigit1Hour();
        short getDigit2Hour();

        short getDigit1Minute();
        short getDigit2Minute();

        short getHour();
        short getMinute();

    private:
        RTC_DS1307 rtc;
        short hourDigit1, hourDigit2;
        short minuteDigit1, minuteDigit2;

        DateTime getDate();
};


#endif //RELOJ_RELOJ_H
