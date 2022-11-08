#include <stdlib.h>
#include <stdio.h>
#include "libpilha.h"

/* 
 * Cria e retorna uma nova pilha com capacidade de nelem elementos. 
 * Retorna NULL em caso de erro de alocação 
*/
pilha_t* pilha_cria (int nelem)
{
    /*Aloca a memoria para a pilha*/
    pilha_t* pilha = malloc(sizeof(pilha_t));
    if(pilha == NULL)
        return NULL;

    /*Aloca a memoria para o vetor elems*/
    pilha->elems = malloc(sizeof(int)*nelem);    
    
    if(pilha->elems == NULL)
    {
        free(pilha);
        pilha = NULL;
	    return NULL;
	}
    
    pilha->topo = 0;
    pilha->nelem = nelem;

    return pilha;
};

 /* Insere elem na pilha (politica LIFO). Retorna o número de elementos na pilha 
 * em caso de sucesso e -1 em caso de pilha cheia 
*/
int push (pilha_t* pilha, int elem)
{
    /*Checa se a pilha esta cheia*/
    if(pilha->topo==pilha->nelem)
        return -1;
    
    pilha->elems[pilha->topo]=elem;
    pilha->topo++;
    return pilha->topo;
};

/* Retorna 1 se pilha vazia, 0 em caso contrario */ 
int pilha_vazia (pilha_t* pilha)
{
    if(pilha->topo==0)
        return 1;
    else
        return 0;
};

/* 
 * Remove (politica LIFO) e retorna um elemento da pilha. 
 * Em caso de pilha vazia retorna 0 
*/
int pop (pilha_t* pilha)
{
    if (pilha_vazia(pilha)==1)
        return 0;
    
    pilha->topo--;

    return pilha->elems[pilha->topo+1];
};

/* Similar ao Pop, mas retorna sem remover */
int pilha_topo (pilha_t* pilha)
{
    /*Checa se a pilhia esta vazia, caso contrario retorna o topo*/
    if (pilha_vazia(pilha)==1)
        return 0;
    
    return pilha->topo;
};  

/* Retorna o numero de elementos da pilha, que pode ser 0 */
int pilha_tamanho (pilha_t* pilha)
{

    return pilha->topo;
};

/* Desaloca memoria de pilha_t e retorna NULL */
pilha_t* pilha_destroi (pilha_t* pilha)
{
    /*libera a memoria alocada pelo vetor elems*/
    /*seta os elementos para nulo*/
    free(pilha->elems);
    pilha->elems=NULL;    
    free(pilha);
    
    return NULL;
};

/* 
 * Imprime a pilha, da base ate o topo, este por ultimo, sem espaco no final.
 * Quando a pilha estiver vazia, nao imprime nada, nem um \n.
*/
void pilha_imprime (pilha_t* pilha)
{
    if(pilha_tamanho(pilha)!=0)
    {
        int i;

        for (i=pilha->topo-1;i>=1;i--)
            printf("%d ",pilha->elems[i]);
        
        printf("%d \n",pilha->elems[i]);
    }
};

