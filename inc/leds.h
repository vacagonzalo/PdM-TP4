#ifndef PROGRAMS_PDM_TP4_INC_LEDS_H_
#define PROGRAMS_PDM_TP4_INC_LEDS_H_
#include "sapi.h"

enum ledMode_t { BLINK, SOLID };

enum ledState_t { DARKNESS, LIGHT };

struct led_t {
    enum ledMode_t mode;
    enum ledState_t state;
    gpioMap_t pin;
    delay_t delay;
};

void initLed(struct led_t *led, gpioMap_t pin);
void updateLed(struct led_t *led);

void turn_on(struct led_t *led);
void turn_off(struct led_t *led);
void turn_blink(struct led_t *led);

#endif
