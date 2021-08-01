#include "semaforo.h"
#include "macros.h"
#include "led.h"
#include "teclas.h"
#include "secuencias.h"

enum estados{normal, desconectado, alarma};

enum estados semaforoNormal(struct Secuencia_t *control, enum estadoMEF boton);
enum estados semaforoDesconectado(struct Secuencia_t *control, enum estadoMEF boton);
enum estados semaforoAlarma(struct Secuencia_t *control, enum estadoMEF boton);

int launch( void )
{
	enum estados estado;
	estado = normal;
	const gpioMap_t ledsNormal[] = {LED3, LED1, LED2};
	const tick_t tiemposNormal[] = {3000, 500, 1000};
	const int8_t countNormal = _countof(ledsNormal);
	struct Secuencia_t controlNormal;
	activarSecuencia(&controlNormal, &ledsNormal, &tiemposNormal, countNormal);

	const gpioMap_t ledsDesconectado[] = {LED1, OSCURIDAD};
	const tick_t tiemposDesconectado[] = {500, 500};
	const int8_t countDesconectado = _countof(ledsDesconectado);
	struct Secuencia_t controlDesconectado;
	activarSecuencia(&controlDesconectado, &ledsDesconectado, &tiemposDesconectado, countDesconectado);

	const gpioMap_t ledsAlarma[] = {LED2, OSCURIDAD};
	const tick_t tiemposAlarma[] = {500, 500};
	const int8_t countAlarma = _countof(ledsAlarma);
	struct Secuencia_t controlAlarma;
	activarSecuencia(&controlAlarma, &ledsAlarma, &tiemposAlarma, countAlarma);

	struct Tecla_t tecla;
	inicializarMEF(&tecla, TEC2);

	while( true ) {
	switch ( estado ){
		case normal:
			estado = semaforoNormal(&controlNormal, tecla.estado);
			break;
		case desconectado:
			estado = semaforoDesconectado(&controlDesconectado, tecla.estado);
			break;
		case alarma:
			estado = semaforoAlarma(&controlAlarma, tecla.estado);
			break;
		}
	actualizarMEF(&tecla);
	}
	return 0;
}

enum estados semaforoNormal(struct Secuencia_t *control, enum estadoMEF boton){
	enum estados estado = normal;
	if (boton == DOWN){
		estado = desconectado;
	}
	actualizarSecuencia(control);
	return estado;
}

enum estados semaforoDesconectado(struct Secuencia_t *control, enum estadoMEF boton){
	enum estados estado = desconectado;
	if (boton == DOWN){
		estado = alarma;
	}
	actualizarSecuencia(control);
	return estado;
}

enum estados semaforoAlarma(struct Secuencia_t *control, enum estadoMEF boton){
	enum estados estado = alarma;
	if (boton == DOWN){
		estado = normal;
	}
	actualizarSecuencia(control);
	return estado;
}
