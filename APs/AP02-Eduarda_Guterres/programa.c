//COMENTE SEU CODIGO!

#include <stdio.h>
#include "pontoEletronico.h"

int main(){
	PontoEletronico pEletronico;
	iniciaPontoEletronico(&pEletronico);
	
	registraPonto(&pEletronico, 7, 26); // Chegada ao trabalho
	registraPonto(&pEletronico, 16, 20); // Intervalo para almoco

	registraPonto(&pEletronico, 15, 59); // Volta do almoco
	registraPonto(&pEletronico, 17, 13); // Saida do trabalho

	imprimeTotalTrabalhadoDia(pEletronico); 
	return 0;
}
