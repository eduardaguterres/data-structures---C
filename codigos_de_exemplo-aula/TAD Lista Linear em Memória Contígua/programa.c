#include "lista_cont.h"
#include <stdio.h>
#include <string.h>

int main(){

   int retorno;
   ListaCont lista;
   criaLista(&lista);
   
   NodoLCont nodoAux;
   // Aqui seriam chamadas as funcoes de inicializacao de nodos
   NodoLCont nodo1 = {1, "Fulano de Tal", "fulano@email.com"};
   NodoLCont nodo2 = {2, "Beltrana de Tal", "beltrana@email.com"};
   NodoLCont nodo3 = {3, "Cicrano de Tal", "cicrano@email.com"};
   NodoLCont nodo4 = {4, "Ciclana de Tal", "ciclana@email.com"};
   NodoLCont nodo5 = {5, "Ciclano de Tal", "ciclano@email.com"};
  
   retorno = insereLista(&lista, nodo1, 0); // retorno = 1
   retorno = insereLista(&lista, nodo2, 1); // retorno = 1
   retorno = insereLista(&lista, nodo3, -1); // retorno = 0
   retorno = insereLista(&lista, nodo4, 5); // retorno = 0 
   //retorno = insereLista(&lista, nodo4, 0); // retorno = 1   
   retorno = insereLista(&lista, nodo5, 2); // retorno = 1
   
   nodoAux = buscaLista(lista, 2); // nodoAux = nodo5   
   nodoAux = buscaInfoLista(lista, 5); // nodoAux = nodo5
   
   //imprimeLista(lista);

   //retorno = tamanhoLista(lista); // retorno = 4
      
   retorno = removeLista(&lista, 0); // retorno = 1
   //retorno = removeLista(&lista, 4); // retorno = 0
   
   imprimeLista(lista);
   destroiLista(&lista);

   //retorno = insereLista(&lista, nodo4, 0); // retorno = 1*/
   //imprimeLista(lista);
      
   return 0;
}

