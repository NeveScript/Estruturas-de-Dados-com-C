
#ifndef PILHA_PILHA_H
#define PILHA_PILHA_H

//--+ Bibliotecas +--//
#include <stdbool.h>

//--+ Tamanho máximo da Pilha +--//
#define TAMANHO_PILHA 50

//--+ Struct da Pilha +--//
typedef struct{
    char caracter[TAMANHO_PILHA];
    int topo;
}Pilha;

//--+ Assinatura das funções e procedimentos da Pilha +--//
void inicializarPilha(Pilha *pilha);
void push(Pilha *pilha, char caracter);
char pop(Pilha *pilha);
bool stackUnderflow(Pilha pilha);
bool stackOverflow(Pilha pilha);

#endif //PILHA_PILHA_H
