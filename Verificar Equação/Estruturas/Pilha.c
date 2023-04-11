#include "../Biblioteca.h"

/**
 * Inicializa uma pilha.
 * @param pilha que será inicializada.
 */
void inicializarPilha(Pilha *pilha){
    pilha->topo = 0;
}

/**
 * Adiciona um caracter na pilha.
 * @param pilha onde o caracter da equacao será empilhado.
 * @param caracter a ser empilha.
 */
void push(Pilha *pilha, char caracter){

    //--+ Verifica se a pilha está chei, caso sim, sairá do procedimento. +--//
    if(stackOverflow(*pilha)){
        printf("Pilha cheia!\n");
        return;
    }

    //--+ Adiciona um caracter no topo da pilha +--//
    pilha->caracter[pilha->topo] = caracter;

    //--+ Incrementa um topo. A posição do caracter no topo sempre será "(pilha->topo - 1)" +--//
    pilha->topo++;

}

/**
 * Remove o topo da pilha.
 * @param pilha que terá o topo removido.
 * @return topo da pilha removido ou '0\n' se a pilhae stiver vazia.
 */
char pop(Pilha *pilha){

    //--+ Verifica se a pilha está vazia, caso sim, será retornado o caracter '\0'. +--//
    if(stackUnderflow(*pilha)){
        printf("Pilha vazia!\n");
        return '\0';
    }

    //--+ Coloca o caracter do topo da pilha em uma variável temporária. +--//
    char palavraRemovida = pilha->caracter[(pilha->topo - 1)];

    //--+ Decrementa o topo da pilha. +--//
    pilha->topo--;

    //--+ Retorna o caracter na variável temporária +--//
    return palavraRemovida;
}

/**
 * Verifica se a pilha está vazia.
 * @param pilha a ser verificada.
 * @return 'true' caso o tamanho do topo seja igual a 0, 'false' caso contrário.
 */
bool stackUnderflow(Pilha pilha){

    if( (pilha.topo) == 0)
        return true;

    return false;
}

/**
 * Verifica se a pilha está cheia.
 * @param pilha a ser verificada
 * @return 'true' caso o tamanho do topo da pilha menos 1 seja igual à constante de controle de tamanho da pilha.
 */
bool stackOverflow(Pilha pilha){

    if( (pilha.topo - 1) == TAMANHO_PILHA)
        return true;

    return false;
}
