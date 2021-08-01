#ifndef PROGRAMS_PDM_TP4_INC_TECLAS_H_
#define PROGRAMS_PDM_TP4_INC_TECLAS_H_

#include "sapi.h"

enum estadoMEF {UP, DOWN, FALLING, RISING};

struct Tecla_t {
	gpioMap_t tecla;
	delay_t delay;
	enum estadoMEF estado;
};

void inicializarMEF(struct Tecla_t *tecla, gpioMap_t pin);
void actualizarMEF(struct Tecla_t *tecla);

#endif 
