/* COMENTE SEU CODIGO! */

#include <stdio.h>
#include <windows.h>

#define QUANT_PARTIDOS 4

#define TRUE 1
#define FALSE 0

int vencedor(int *votos, int *idxVencedor, float *percentual);
void imprimirPartidos(char partidos[QUANT_PARTIDOS][10], int *numeros);
void imprimirNumeroDeVotos(int *votos, int votosInvalidos);
void printVencedor(int naoEmpate, float percentual, char* partido);
int votar(int *votos, int *numeros);

int main(){

   int opcao, naoEmpate;
   int votosInvalidos = 0;
   int idxVencedor;
   float percentual;
   
   int votos[QUANT_PARTIDOS] = {1,3,3,1};
   int numeros[QUANT_PARTIDOS] = {4, 2, 9, 5};
   char partidos[QUANT_PARTIDOS][10] = {"Partido A", "Partido B", "Partido C", "Partido D"};
   
   do{
   	  system("cls");
      printf("----- MENU -----\n");
      printf("1 - Votar \n");
      printf("2 - Numeros e Partidos \n");
      printf("3 - Votos Validos e Invalidos \n");
      printf("4 - Encerrar Votacao \n");
      printf("----- ---- -----\n");
      printf("Informe uma opcao: ");
      scanf("%d", &opcao);
      switch(opcao){
         case 1:
            printf("Votar \n");
            votosInvalidos += votar(votos, numeros);	//recebe se há votos inválidos
            break;
         case 2:
            printf("Numeros e Partidos \n");
            imprimirPartidos(partidos, numeros);
            system("pause");
            break;
         case 3:
            printf("Votos Validos e Invalidos \n");
			imprimirNumeroDeVotos(votos,votosInvalidos);
            system("pause");
            break;
         case 4:
            printf("Encerrar Votacao \n");
            naoEmpate = vencedor(votos, &idxVencedor, &percentual); //recebe se a empate ou nao
            break;
         default:
            printf("Opcao invalida!");
            system("pause");
      }
   }while(opcao != 4);
   
   printVencedor(naoEmpate, percentual, partidos[idxVencedor]); //printa o vencedor

   return 0;
}


void imprimirPartidos(char partidos[QUANT_PARTIDOS][10], int *numeros){			//Essa funcso imprime os partidos que existem
    int i;

    for(i=0; i<QUANT_PARTIDOS ;i++){
        printf(" %d - %s\n", numeros[i],partidos[i]);
    };
    
};

int votar(int *votos, int *numeros){					//Essa funcao realiza a votacao 
	int voto=0;
	int i=0;
	int votoInvalido = TRUE;
	
	printf("\nDigite o numero do partido: ");
	scanf("%d", &voto);
	for(i=0; i<QUANT_PARTIDOS ;i++){
		if ( voto == numeros[i] ){
			votos[i] ++;
			votoInvalido = FALSE;
		}	
	}
	
	return votoInvalido;								//Caso seja um voto invalido ela retornará true, e será somada a variavel de votos inválidos
}

void imprimirNumeroDeVotos(int *votos, int votosInvalidos){				//Essa funcao printa a quantidade de votos validos e inválidos
    int i;
    int votosValidos=0;
    
	for(i=0; i<QUANT_PARTIDOS ;i++){
    	votosValidos += votos[i];
    };
	
	printf("\nVotos Validos: %d\n",votosValidos);
	printf("Votos Invalidos: %d\n\n",votosInvalidos);
};

void printVencedor(int naoEmpate, float percentual, char* partido){		//Printa o ganhador ou se houve empate
	
	if(naoEmpate){
		printf("\n Nao houve empate!\n");
		printf("\n\tO ganhador eh: %s \n", partido);
		printf("\tCom: %f \n", percentual);
	}else {
		printf("\n Houve Empate!");		
	}
	
}

int vencedor(int *votos, int *idxVencedor, float *percentual){		//verifica qual é o vencedor, se há empates e a porcentagem do vencedor
	int i=0;
	int maior = 0;
	int empate = TRUE;
	int somadorDeVotos = 0;
	//int partidoEmpatado[QUANT_PARTIDOS] = 0;
	
	for(i=0; i<QUANT_PARTIDOS ;i++){
    	if (votos[i] > maior){
    		maior = votos[i];
    		empate = FALSE;
    		*idxVencedor = i;
    	}
    	else if (votos[i] == maior){
    		empate = TRUE;
    		*idxVencedor = i;
		}
		somadorDeVotos = somadorDeVotos + votos [i];
    }
    
    *percentual = maior*100.0/somadorDeVotos;
    return !empate;
}


