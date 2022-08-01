#include "pilha_enc.h"
#include <stdio.h>
#include <stdlib.h>

// Funcao que cria uma pilha
PilhaEnc* criaPilha(){
   PilhaEnc *pilha = (PilhaEnc*)malloc(sizeof(PilhaEnc));
   pilha->topo = NULL;
   return pilha;
}

// Funcao que destroi uma pilha
void destroiPilha(PilhaEnc *pilha){
   NodoLEnc *aux = pilha->topo;
   while(aux != NULL){
       NodoLEnc *tmp = aux->prox;
       free(aux); // Cuidar ordem do free
       aux = tmp;
   }
   free(pilha);
}

// Funcao que insere um elemento na pilha
void empilhaPilha(PilhaEnc *pilha, Info info){
   NodoLEnc *novo = (NodoLEnc*)malloc(sizeof(NodoLEnc));
   novo->info = info;
   novo->prox = pilha->topo;
   pilha->topo = novo;
}

// Funcao que remove um elemento da pilha
Info desempilhaPilha(PilhaEnc* pilha){
   NodoLEnc *aux = pilha->topo;
   /* Aqui assumimos que desempilha eh
   chamada apenas se a pilha nao eh vazia */
   Info info = aux->info;
   pilha->topo = aux->prox;
   free(aux);
   return info;
}

// Funcao que determina se uma pilha eh vazia
int vaziaPilha(PilhaEnc *pilha){
   return (pilha->topo == NULL);
}


void invertePilha(PilhaEnc *pilha){
    PilhaEnc *pilhaAux_1;
    pilhaAux_1 = criaPilha();

    PilhaEnc *pilhaAux_2;
    pilhaAux_2 = criaPilha();

    Info infoAux;

    while(!vaziaPilha(pilha)){
        infoAux = desempilhaPilha(pilha);
        empilhaPilha(pilhaAux_1, infoAux);
    }


    while(!vaziaPilha(pilhaAux_1)){
        infoAux = desempilhaPilha(pilhaAux_1);
        empilhaPilha(pilhaAux_2, infoAux);
    }


    while(!vaziaPilha(pilhaAux_2)){
        infoAux = desempilhaPilha(pilhaAux_2);
        empilhaPilha(pilha, infoAux);
    }
    destroiPilha(pilhaAux_1);
    destroiPilha(pilhaAux_2);


}
