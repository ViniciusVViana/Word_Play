#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<locale.h>
#include"Aux_Word_Play.h"

void main(){

    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    srand(time(NULL));

    printf("Este e o Word Play, um jogo de palavras parecido com o silvio santos\n");
    printf("O jogo consiste em descobrir as palavras que estao ocultas.\n");
    printf("Para isso, voce deve digitar as letras que acha que estao na palavra.\n");
    printf("Caso voce acerte, a letra sera revelada. Voce pode errar ate 5 letras e 1 palavra\n\n");

    printf("Temos alguns temas para você escolher:\n");
    printf("1 - Frutas\n");
    printf("2 - cores\n");
    printf("3 - animais\n");
    printf("Qual tema deseja: ");
    scanf("%i", &tema);
    fflush(stdin);

        aleatorizar_palavras();

        cop();

        montagem();

        do{

        system("cls");

        printf("PALAVRAS ESCONDIDAS:\n\n");

        imprimir_wp();

        printf("\nDICAS: \n\n");

        imprimir_dicas();

        printf("\nAgora voce pode inserir letra por letra ou a palavra inteira.\n\n");

        ache();

        confere();

        }while(((erro_l <= 5) && (erro_p <= 1)) && (correto < 100));

        system("cls");

        if(correto == 100){

            printf("-------------============****============-------------\n");
            printf("Você conseguiu acertar todas as palavras!! PARABENS!!!\n");
            printf("-------------============****============-------------\n");

        }else if(correto != 100){

            printf("--------------=============*****=============--------------\n");
            printf("Você foi desclacificado por ultrapassar o limite de erros!!\n");
            printf("--------------=============*****=============--------------\n");

        };

};
