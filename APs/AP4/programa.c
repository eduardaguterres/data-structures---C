#include <stdio.h>
#include <string.h>
#include "lista_enc.h"

int main(){
   int retorno;
   int tamanho = 0;
   ListaEnc *lista;
   lista = criaLista();

   // Aqui seriam chamadas as funcoes de inicializacao de nodos
   Info info1 = {1, "Fulano de Tal", "fulano@email.com"};
   Info info2 = {2, "Beltrana de Tal", "beltrana@email.com"};
   Info info3 = {3, "Cicrano de Tal", "cicrano@email.com"};
   Info info4 = {4, "Ciclana de Tal", "ciclana@email.com"};
   Info info5 = {5, "Ciclano de Tal", "ciclano@email.com"};

   //retorno = insereInicioLista(lista, info1); // retorno = 1
   retorno = insereInicioLista(lista, info2); // retorno = 1
   //retorno = insereInicioLista(lista, info3); // retorno = 1
   retorno = insereInicioLista(lista, info4); // retorno = 1
   retorno = insereInicioLista(lista, info5); // retorno = 1

//   NodoLEnc *infoAux;
//   infoAux = buscaInfoLista(lista, 2); // infoAux = info2
//   retorno = removeInfoLista(lista, 2); // retorno = 1
//   retorno = removeInfoLista(lista, 50); // retorno = 0
//   retorno = removeInfoLista(lista, 1); // retorno = 1
//   infoAux = buscaInfoLista(lista, 2); // infoAux = NULL
   imprimeLista(lista);
   tamanho = tamanhoLista(lista);
   printf("%d", tamanho);
   //imprimeLista(lista);

   retorno = insereOrdenadoLista(lista, info1);
   imprimeLista(lista);
   destroiLista(lista);

   return 0;
}
