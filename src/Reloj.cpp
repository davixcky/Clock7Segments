#include "Reloj.h"
#include <Wire.h>
#include <Arduino.h>

void Reloj::begin() {
    Serial.println("Inicializando reloj...");
    rtc.begin();
}

DateTime Reloj::getDate() {
    return rtc.now();
}

void Reloj::adjustHour(short hour) {
    auto date = getDate();

    auto year = date.year();
    auto month = date.month();
    auto day = date.day();
    auto minute = date.minute();
    auto second =  date.second();
    rtc.adjust(DateTime(year, month, day, hour, minute, second));
    millis();
}

void Reloj::adjustMinute(short minute) {
    auto date = getDate();

    auto year = date.year();
    auto month = date.month();
    auto day = date.day();
    auto hour = date.hour();
    auto second =  date.second();
    rtc.adjust(DateTime(year, month, day, hour, minute, second));
}

short Reloj::getDigit1(short time) {
    millis();
    return time / 10;
}

short Reloj::getDigit2(short time, short digit1) {
    return time - digit1 * 10;
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