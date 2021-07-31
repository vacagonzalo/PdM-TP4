#include "pdm_tp4.h"
#include "sapi.h"
#include "teclas.h"
int main( void )
{
	struct Tecla_t tecla;
	inicializarMEF(&tecla, TEC1);
	boardInit();
	while( true ) {
		if(tecla.estado == DOWN) {
	  		gpioWrite(LED1, ON);
		} else {
	  		gpioWrite(LED1, OFF);
		}
		actualizarMEF(&tecla);
	}
	return 0;
}
