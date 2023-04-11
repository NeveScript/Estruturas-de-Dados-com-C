#include "Biblioteca.h"

/**
 * Empilha caracters '(', '{' e '['.
 * @param pilha A pilha onde os caracters da equação serão empilhados.
 * @param equacao A equacao com caracters que serão empilhados.
 */
void empilharCaracteresDaEquacao(Pilha *pilha, char equacao[50]);

/**
 *
 * @param caracterDeAbertura O caracter de abertura da equação.
 * @param caracterDeFechamento O caracter de fechamento da equação.
 * @return 'true' caso o caracter de abertura seja par do de fechamento, 'false' caso contrário.
 */
bool comparaCaracters(char caracterDeAbertura, char caracterDeFechamento);

int main(){

    Pilha pilha;
    inicializarPilha(&pilha);

    char equacao[50];

    printf("Digite uma equacao: ");
    scanf(" %49[^\n]", equacao);

    empilharCaracteresDaEquacao(&pilha, equacao);


    return 0;
}

void empilharCaracteresDaEquacao(Pilha *pilha, char equacao[50]){

    int contador = 0;


    while(equacao[contador] != '\0'){

        /**
         * Hierarquia dos caracters na equação: '(' > '{' > '['.
         */
        bool eUmCaracterDeAbertura   = equacao[contador] == '(' || equacao[contador] == '{' || equacao[contador] == '[';
        bool eUmCaracterDeFechamento = equacao[contador] == ')' || equacao[contador] == '}' || equacao[contador] == ']';

        //--+ Verifica se o caracter é um dos caracteres de abertura e empilha ele caso sim. +--//
        if(eUmCaracterDeAbertura)
            push(pilha, equacao[contador]);

        //--+ Verifica se o caracter é um dos caracteres de fechamento+--//
        if(eUmCaracterDeFechamento){

            //--+ Desempilha o caracter do topo da pilha e verifica se ele é seu par. +--//
            if(!comparaCaracters(pop(pilha), equacao[contador])){
                printf("Equacao mal-formada!");
                return;
            }
        }

        //--+ Incrementa o contador +--//
        contador++;
    }

    //--+ Caso ele execute esta linha, significa que a equação é bem-fomada +--//
    if(pilha->topo == 0)
        printf("Equacao bem-formada!");
    else
        printf("Equacao mal-formada");
}

bool comparaCaracters(char caracterDeAbertura, char caracterDeFechamento){

    switch(caracterDeAbertura){
        case '(':
            if(caracterDeFechamento == ')')
                return true;
            break;
        case '{':
            if(caracterDeFechamento == '}')
                return true;
            break;
        case '[':
            if(caracterDeFechamento == ']')
                return true;
            break;
    }

    return false;
}



