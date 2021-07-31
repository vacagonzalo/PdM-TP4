#include "teclas.h"

#define TIME_GUARD 20

void buttonPressed(struct Tecla_t *tecla);

void buttonReleased(struct Tecla_t *tecla);

void inicializarMEF(struct Tecla_t *tecla, gpioMap_t pin)
{
	delayInit(&tecla->delay, TIME_GUARD);
	tecla->estado = UP;
	tecla->tecla = pin;
}

void actualizarMEF(struct Tecla_t *tecla)
{
	switch(tecla->estado)
	{
	case UP:
		if(!gpioRead(tecla->tecla)) {
			tecla->estado = FALLING;
		}
		break;
	case FALLING:
		buttonPressed(tecla);
		break;
	case DOWN:
		if(gpioRead(tecla->tecla)) {
			tecla->estado = RISING;
		}
		break;
	case RISING:
		buttonReleased(tecla);
		break;
	default:
		gpioWrite(LEDR,ON);
    }
}

void buttonPressed(struct Tecla_t *tecla)
{
	if(delayRead(&tecla->delay)) {
		if(!gpioRead(tecla->tecla)) {
			tecla->estado = DOWN;
		} else {
			tecla->estado = UP;
		}
		delayWrite(&tecla->delay, TIME_GUARD);
	}
}

void buttonReleased(struct Tecla_t *tecla)
{
	if(delayRead(&tecla->delay)) {
		if(!gpioRead(tecla->tecla)) {
			tecla->estado = DOWN;
		} else {
			tecla->estado = UP;
		}
		delayWrite(&tecla->delay, TIME_GUARD);
	}
}



















