/** @file secuencias.h
 *  @brief Archivo con estructura de datos y prototipos para el
 *  módulo de secuencias de LEDs para la placa EDU-CIAA
 *
 *  @author Gonzalo N. Vaca <vacagonzalo@gmail.com>
 *  @author Luis I. Minchala <ismael.minchala@ucuenca.edu.ec>
 */

#ifndef _SECUENCIAS_H_
#define _SECUENCIAS_H_

#include "macros.h"

/** Estructura de secuencia de LEDs
 *
 */
struct Secuencia_t
{
	gpioMap_t *leds;
	int8_t pos;
	bool_t sentido;
	tick_t *tiempos;
	delay_t myDelay;
	int8_t len;
};

/** @brief Función que actualiza el estado de secuencia
 *
 *  @param psecuencia
 */
void activarSecuencia(struct Secuencia_t *psecuencia, gpioMap_t *leds, tick_t *tiempos, int8_t cuenta);

void actualizarSecuencia(struct Secuencia_t *psecuencia);

void invertirSecuencia(struct Secuencia_t *psecuencia);

void ascendenteSecuencia(struct Secuencia_t *psecuencia);

void descendenteSecuencia(struct Secuencia_t *psecuencia);


#endif /* _SECUENCIAS_H_ */
