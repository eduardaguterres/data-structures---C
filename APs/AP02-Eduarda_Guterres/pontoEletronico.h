#ifndef PONTO_ELETRONICO
#define pEletronico_H

// struct do ponto eletronico
typedef struct{
    int horas;
    int minutosEntrada;
    int minutosSaida;
    int totalDeHoras;
    int totalDeMinutos;
    int registro; //registra se eh o ponto de saida ou entrada 
} PontoEletronico;

// Funcao que inicia e zera o vetor
void iniciaPontoEletronico(PontoEletronico *v);

// Registra o ponto, recebe o vetor ponto eletronico, as horas e minutos informadas pelo usuario
void registraPonto (PontoEletronico *v, int horas, int minutos);

//Imprime a quantidade de horas trabalhadas pelo usuario
void imprimeTotalTrabalhadoDia(PontoEletronico v);

#endif // PONTO_ELETRONICO
