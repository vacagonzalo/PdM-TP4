#include "leds.h"

#define BLINK_TIME 500

void binkFSM(struct led_t *led);

void initLed(struct led_t * led, gpioMap_t pin)
{
    led->mode = SOLID;
    led->state = DARKNESS;
    led->pin = pin;
    gpioWrite(led->pin, OFF);
    delayInit(&led->delay, BLINK_TIME);
}

void updateLed(struct led_t *led)
{
    if(led->mode == BLINK) {
        blinkFSM(led);
    }
}

void turn_on(struct led_t *led)
{
    gpioWrite(led->pin, ON);
    led->state = LIGHT;
    led->mode = SOLID;
}

void turn_off(struct led_t *led)
{
    gpioWrite(led->pin, OFF);
    led->state = DARKNESS;
    led->mode = SOLID;
}

void turn_blink(struct led_t *led)
{
    led->mode = BLINK;
}

void blinkFSM(struct led_t *led)
{
    switch(led->state) {
        case DARKNESS:
            gpioWrite(led->pin, OFF);
            if(delayRead(&led->delay)) {
                led->state = LIGHT;
                delayWrite(&led->delay, BLINK_TIME);
            }
        break;
        case LIGHT:
            gpioWrite(led->pin, ON);
            if(delayRead(&led->delay)) {
                led->state = DARKNESS;
                delayWrite(&led->delay, BLINK_TIME);
            }
        break;
        default:
            turn_off(led); // panic! turn the led off
    }
}
