#include <stdio.h>
#include <math.h>
#include "pontoEletronico.h"
#define  CONV_HORAS 60

void iniciaPontoEletronico(PontoEletronico *v){
    //zerando todos as variaveis
    v->horas = 0;
    v->minutosEntrada = 0;
    v->minutosSaida = 0;
    v->registro = 0;
    v->totalDeHoras = 0;
    v->totalDeMinutos = 0;
}

//registra o ponto
void registraPonto (PontoEletronico *v, int horas, int minutos){
    
    if (v->registro %2 == 0){ //verifica se o ponto é de entrada ou saída (o registro começa do zero, entao se é par: entrada, impar:saida)
        v->minutosEntrada = horas*CONV_HORAS + minutos; //converte horas para minutos e coloca no minutos de entrada, já q é um registro par
    } else{
        v->minutosSaida = horas*CONV_HORAS  + minutos; //converte horas para minutos e coloca no minutos de saída, já q é um registro impar
        v->totalDeHoras += (v->minutosSaida - v->minutosEntrada)/CONV_HORAS ; // realiza a subtracao dos minutos e converte de min para horas, dando o numero de horas 
        v->totalDeMinutos += ((v->minutosSaida - v->minutosEntrada)%CONV_HORAS ); //subtrai os minutos e verifica qual é o resto da dividao, para se ter os minutos

        if (v->totalDeMinutos >= 60) //para caso os casos que o resto do totalDeMinutos dá 60
        {
        	v->totalDeMinutos -= 60;
        	v->totalDeHoras++;
		}
    }
    v->registro++; //registra se é o ponto de entrada ou saida
}

//imprime o total de horas
void imprimeTotalTrabalhadoDia(PontoEletronico v){
    printf("\n\t%02d:%02d", v.totalDeHoras, v.totalDeMinutos);
}
