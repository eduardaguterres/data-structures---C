// COMENTE SEU CÓDIGO

#include <stdio.h>
#include <string.h>
#include "fila_enc.h"
#include "pilha_enc.h"

int main(){
   PilhaEnc *pilha;
   pilha = criaPilha();

   PilhaEnc *pilha2;
   pilha2 = criaPilha();

   FilaEnc *fila;
   fila = criaFila();

    FilaEnc *fila2;
   fila2 = criaFila();

   Info info1 = {1, "Fulano de Tal", "fulano@email.com"};
   Info info2 = {2, "Beltrana de Tal", "beltrana@email.com"};
   Info info3 = {3, "Cicrano de Tal", "cicrano@email.com"};
   Info info4 = {4, "Ciclana de Tal", "ciclana@email.com"};
   Info info5 = {5, "Ciclano de Tal", "ciclano@email.com"};

   empilhaPilha(pilha, info1);
   empilhaPilha(pilha, info2);
   empilhaPilha(pilha, info3);
   empilhaPilha(pilha, info4);
   empilhaPilha(pilha, info5);

    empilhaPilha(pilha2, info1);
   empilhaPilha(pilha2, info2);
   empilhaPilha(pilha2, info3);
   empilhaPilha(pilha2, info4);
   empilhaPilha(pilha2, info5);

    Info infoAux;

    invertePilha(pilha);

    printf("Pilha Original:\n");
    while (!vaziaPilha(pilha2)){
      infoAux = desempilhaPilha(pilha2);
      printf("%d | %s (%s)\n", infoAux.matricula, infoAux.nome, infoAux.email);
   }
   printf("Pilha Invertida:\n");
   while (!vaziaPilha(pilha)){
      infoAux = desempilhaPilha(pilha);
      printf("%d | %s (%s)\n", infoAux.matricula, infoAux.nome, infoAux.email);
   }


   destroiPilha(pilha);
   destroiPilha(pilha2);

   enfileiraFila(fila, info1);
   enfileiraFila(fila, info2);
   enfileiraFila(fila, info3);
   enfileiraFila(fila, info4);
   enfileiraFila(fila, info5);

   enfileiraFila(fila2, info1);
   enfileiraFila(fila2, info2);
   enfileiraFila(fila2, info3);
   enfileiraFila(fila2, info4);
   enfileiraFila(fila2, info5);

    inverteFila(fila);
     printf("Fila Original:\n");
   while (!vaziaFila(fila2)){
      infoAux = desenfileiraFila(fila2);
      printf("%d | %s (%s)\n", infoAux.matricula, infoAux.nome, infoAux.email);
   }

    printf("Fila Invetida:\n");
   while (!vaziaFila(fila)){
      infoAux = desenfileiraFila(fila);
      printf("%d | %s (%s)\n", infoAux.matricula, infoAux.nome, infoAux.email);
   }

   destroiFila(fila);

   return 0;
}
