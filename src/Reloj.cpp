#include "Reloj.h"
#include <Wire.h>
#include <Arduino.h>

void Reloj::begin() {
    Serial.println("Inicializando reloj...");
    rtc.begin();

    hora = getDate().hour();
    minutos = getDate().minute();
}

DateTime Reloj::getDate() {
    return rtc.now();
}

void Reloj::adjustHour(short hour) {
    Serial.println("Ajustando hora");

    hora = hour;

    auto date = getDate();

    auto year = date.year();
    auto month = date.month();
    auto day = date.day();
    auto second =  date.second();
    rtc.adjust(DateTime(year, month, day, hour, date.minute(), second));
}

void Reloj::adjustMinute(short minute) {
    Serial.println("Ajustando minuto");

    minutos = minute;

    auto date = getDate();

    auto year = date.year();
    auto month = date.month();
    auto day = date.day();
    auto second =  date.second();
    rtc.adjust(DateTime(year, month, day, hora, minute, second));
}

short Reloj::getDigit1Hour() {
    hourDigit1 = getDate().hour();
    hourDigit1 = hourDigit1 / 10;
    return hourDigit1;
}

short Reloj::getDigit2Hour() {
    hourDigit2 = getDate().hour();
    if (hourDigit1 == 0) {
        return hourDigit2;
    }
    hourDigit2 = hourDigit2 - hourDigit1 * 10;
    return hourDigit2;
}

short Reloj::getDigit1Minute() {
    minuteDigit1 = getDate().minute();
    minuteDigit1 = minuteDigit1 / 10;
    return minuteDigit1;
}

short Reloj::getDigit2Minute() {
    minuteDigit2 = getDate().minute();
    if (minuteDigit1 == 0) {
        return minuteDigit2;
    }
    minuteDigit2 = minuteDigit2 - minuteDigit1 * 10;
    return minuteDigit2;
}

short Reloj::getHour() {
    return getDate().hour();
}

short Reloj::getMinute() {
    return getDate().minute();
}