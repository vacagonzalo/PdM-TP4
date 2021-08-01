#include "secuencias.h"
#include "led.h"

void actualizarPosicion(struct Secuencia_t *sec);

void activarSecuencia(struct Secuencia_t *psecuencia, gpioMap_t *leds, tick_t *tiempos, int8_t cuenta)
{
	psecuencia->leds = leds;
	psecuencia->tiempos = tiempos;
	psecuencia->len = cuenta;
	psecuencia->pos = 0;
	psecuencia->sentido = true;
	delayInit(&psecuencia->myDelay, psecuencia->tiempos[psecuencia->pos]);
	apagarLeds();
	encenderLed(psecuencia->leds[psecuencia->pos]);
}

void actualizarSecuencia(struct Secuencia_t *psecuencia)
{
	if (delayRead(&psecuencia->myDelay))
	{
		apagarLeds();
		actualizarPosicion(psecuencia);
		encenderLed(psecuencia->leds[psecuencia->pos]);
		delayWrite(&psecuencia->myDelay, psecuencia->tiempos[psecuencia->pos]);
	}
}

void invertirSecuencia(struct Secuencia_t *psecuencia)
{
	psecuencia->sentido = !psecuencia->sentido;
}

void ascendenteSecuencia(struct Secuencia_t *psecuencia)
{
	psecuencia->sentido = true;
}

void descendenteSecuencia(struct Secuencia_t *psecuencia)
{
	psecuencia->sentido = false;
}

void actualizarPosicion(struct Secuencia_t *sec)
{
	if(sec->sentido) {
		if(sec->pos < (sec->len - 1)) {
			++sec->pos;
		} else {
			sec->pos = 0;
		}
	} else {
		if(sec->pos > 0) {
			--sec->pos;
		} else {
			sec->pos = sec->len - 1;
		}
	}
}
