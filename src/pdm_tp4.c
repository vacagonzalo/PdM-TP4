#include "pdm_tp4.h"
#include "sapi.h"
#include "teclas.h"
#include "leds.h"
int main( void )
{
	struct Tecla_t tecla;
	inicializarMEF(&tecla, TEC1);

    struct led_t led;
    initLed(&led, LED2);

    struct led_t blinker;
    initLed(&blinker, LED3);
    turn_blink(&blinker);
	boardInit();
	while( true ) {
		if(tecla.estado == DOWN) {
	  		gpioWrite(LED1, ON);
            turn_on(&led);
		} else {
	  		gpioWrite(LED1, OFF);
            turn_off(&led);
		}
		actualizarMEF(&tecla);
        updateLed(&led);
        updateLed(&blinker);
	}
	return 0;
}
