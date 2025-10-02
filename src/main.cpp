#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led(LED_PIN, LED_ACT);

void btnPush();
void btnHold();
void btnDoubleclick();
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    led.off();
    button.attachClick(btnPush);
    button.attachLongPressStart(btnHold);
    button.attachDoubleClick(btnDoubleclick);
}

void loop()
{
    led.loop();
    button.tick();
}

void btnPush()
{
    led.flip();
}

void btnHold()
{
    led.blink(200);
}

void btnDoubleclick()
{
    led.blink(200);
}