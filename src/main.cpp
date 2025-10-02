#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led1(LED_PIN, LED_ACT);
void btnPush();
void btnHold();
void btnDoubleclick();
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    led1.off();
    button.attachClick(btnPush);
    button.attachLongPressStart(btnHold);
    button.attachDoubleClick(btnDoubleclick);
}

void loop()
{
    led1.loop();
    button.tick();
}

void btnPush()
{
    led1.flip();
}

void btnHold()
{
    led1.blink(200);
}

void btnDoubleclick()
{
    led1.blink(200);
}