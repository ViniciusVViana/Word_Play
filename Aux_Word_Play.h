char wp_matriz[5][20], aux_wp_matriz[5][20], dicas[5][20], resp[20], aux_resp[20];
int l = 0, c = 0, cont = 0, aux_cont = 0, tema = 0, op, aux_erro_l = 0, aux_erro_p = 0,acerto = 0, aux_acerto = 0, erro_l= 0 , erro_p = 0, tamanho_resp;
int aux_l[5], correto = 0, l;

//Daqui até o final da matriz dicas_animas, é o nosso "banco de dados", aonde estão todas as nossas palavras a serem achadas e suas respectivas dicas.
char frutas[10][20] = {

    "maca****************",
    "banana**************",
    "manga***************",
    "melancia************",
    "abacate*************",
    "abacaxi*************",
    "acai****************",
    "amora***************",
    "cereja**************",
    "morango*************",

};

char dicas_frutas[10][20] = {

    "Fruta do amor*******",
    "Monkey**************",
    "Faz mal com leite***",
    "Sabor Trident*******",
    "Bom pro cabelo******",
    "*emote diabo********",
    "Uma delicia gelado**",
    "Da pra acha na rua**",
    "A ****** do bolo****",
    "Sabor bala**********",

};

char cores[10][20] = {

    "vermelho************",
    "azul****************",
    "amarelo*************",
    "preto***************",
    "branco**************",
    "verde***************",
    "marrom**************",
    "laranja*************",
    "rosa****************",
    "roxo****************",

};

char dicas_cores[10][20] = {

    "Cor do amor*********",
    "Cor do mar**********",
    "Cor do sol**********",
    "Yin*****************",
    "Yang****************",
    "Cor da grama********",
    "Cor de fezes********",
    "Fruta com esse nome*",
    "Cor do porco********",
    "Quando mahuca*******",

};

char animais[10][20] = {

    "coelho**************",
    "rato****************",
    "cachorro************",
    "gato****************",
    "peru****************",
    "galinha*************",
    "vaca****************",
    "macaco**************",
    "cavalo**************",
    "pombo***************",

};

char dicas_animais[10][20] = {

    "Orelhas compridas***",
    "Gosta de queijo*****",
    "Late pra caramba****",
    "Mia e é fofinho*****",
    "GLU GLU GLU*********",
    "Muié do galo********",
    "Da leite************",
    "Gosta de banana*****",
    "Trota***************",
    "PRU PRU*************",

};
//Aqui termina nosso "banco de dados".

void iniciar_matriz(){ //Essa função preenche com * as matrizes wp_matriz que é a matriz principal do jogo e que aparece pro usuario e tambeém preenche a matriz aux_wp_matriz que é aonde nós guardamos as palavras que estamos procurando.

    for(l = 0; l < 5; l++){

        for(c = 0; c < 20; c++){

            wp_matriz[l][c] = '*';
            aux_wp_matriz[l][c] = '*';

        };

    };

};

void aleatorizar_palavras(){ //Essa função guarda em um vetor de 5 posições, 5 números aleatorios, para futuramente ser usada como indice da matriz aux_wp_matriz e receber palavras aleatorias.

    for(cont = 0; cont < 5; cont++){

        aux_l[cont] = rand() % 10;

        for(aux_cont = 0; aux_cont < 5; aux_cont++){

            if((aux_l[cont] == aux_l[aux_cont]) && (cont != aux_cont)){

                aux_l[cont] = rand() % 10;

            };

        };

    };

};

void cop(){ //Essa função com base nos números aleatorios do vetor mencionado anteriormente preenche a matriz aux_wp_matriz com as palavras aleatorias e nossa matriz de dicas com suas respectivas dicas.

    for(cont = 0; cont < 5; cont++){

        for(aux_cont = 0; aux_cont < 20; aux_cont++){

            if(tema == 1){

                aux_wp_matriz[cont][aux_cont] = frutas[aux_l[cont]][aux_cont];
                dicas[cont][aux_cont] = dicas_frutas[aux_l[cont]][aux_cont];

            }else if(tema == 2){

                aux_wp_matriz[cont][aux_cont] = cores[aux_l[cont]][aux_cont];
                dicas[cont][aux_cont] = dicas_cores[aux_l[cont]][aux_cont];

            }else if(tema == 3){

                aux_wp_matriz[cont][aux_cont] = animais[aux_l[cont]][aux_cont];
                dicas[cont][aux_cont] = dicas_animais[aux_l[cont]][aux_cont];

            };

        };

    };

};

void imprimir_wp(){ //Essa função imprimi a matriz que o usuario vizualiza.

    for(cont = 0; cont < 5; cont++){

        printf("%i - |", cont + 1);

        for(aux_cont = 0; aux_cont < 20; aux_cont++){

            printf(" %c |", wp_matriz[cont][aux_cont]);

        };

        printf("\n");

    };

};

void montagem(){ // Essa função preencher a matriz wp_matriz que é a que o usuario ira vizualizar, preencher com base na matriz aux_wp_matriz, aonde nela tem letras a matriz wp_matriz é preenchida com espaços e aonde nao tem letra é preenchida com *.

    for(cont = 0; cont < 5; cont++){

        for(aux_cont = 0; aux_cont < 20; aux_cont++){

            if(aux_wp_matriz[cont][aux_cont] !=  '*'){

                wp_matriz[cont][aux_cont] = ' ';

            }else if(aux_wp_matriz[cont][aux_cont] == '*'){

                wp_matriz[cont][aux_cont] = '*';

            };

        };

    };

};

void imprimir_dicas(){ //Essa função imprimi a matriz que tem as dicas relacionadas as palavras.

    for(cont = 0; cont < 5; cont++){

        printf("%i - |", cont + 1);

        for(aux_cont = 0; aux_cont < 20; aux_cont++){

            printf("%c", dicas[cont][aux_cont]);

        };

        printf("|\n");

    };

};

void ache(){ //Essa matriz é aonde o usuario digita a palavra ou letra que ele acha que contem nas palavras, também é utilizada para verificar se o usuario errou o limite de letras ou palavras.

    aux_acerto = 0;

    printf("Quer chutar uma letra ou uma palavra: \n");
    printf("1 = letra\n2 = palavra <- esta opção nao esta funcionando, porfavor nao tente prof\n");
    scanf("%i", &op);
    fflush(stdin);

    if(op == 1){

        printf("Qual letra voce quer tentar: ");
        scanf("%c", &resp);
        fflush(stdin);

        for(cont = 0; cont < 5; cont++){

            for(aux_cont = 0; aux_cont < 20; aux_cont++){

                if(aux_wp_matriz[cont][aux_cont] == resp[0]){

                    wp_matriz[cont][aux_cont] = resp[0];

                    aux_acerto++;

                };

            };

        };

        if(aux_acerto > 0){

        erro_l = 0;

        };
        if(aux_acerto == 0){

        aux_erro_l = aux_erro_l + 1;
        erro_l = aux_erro_l;

        };

    }else if(op == 2){ //CÓDIGO NAO FINALOZADO, NAO CONSEGUI DESENVOLVER UM CODIGO PARA A CONFERENCIA DE PALAVRAS, TENTEI UTTILIZAR DIVERSAS FUNCAO DA BIBLIOTECA STRING, E AINDA ASSIM NAO CONSIGUI.

        acerto = 0;

        printf("Qual a palavra: ");
        gets(resp);
        fflush(stdin);

        for(cont = 0; cont < (20 - strlen(resp)); cont++){

            aux_resp[cont] = '*';

        }

        strcat(resp, aux_resp);

        for(cont = 0; cont < 5; cont++){

            for(aux_cont = 0; aux_cont < 20; aux_cont++){

                if(resp[aux_cont] == aux_wp_matriz[cont][aux_cont]){

                    acerto = acerto + 1;

                };

            };

            if(acerto == 20){

                l = cont;

            };

        };

        if(acerto == 20){

            for(aux_cont = 0; aux_cont < 20; aux_cont++){

                wp_matriz[l][aux_cont] = aux_wp_matriz[l][aux_cont];

            };

        };

    };

};

void confere(){ //Essa função compara as matrizes aux_wp_matriz e wp_matriz para definir se o usuario acertou todas as palavras.

    correto = 0;

    for(cont = 0; cont < 5; cont++){

        for(aux_cont = 0; aux_cont < 20; aux_cont++){

            if(wp_matriz[cont][aux_cont] == aux_wp_matriz[cont][aux_cont]){

                correto = correto + 1;

            };

        };

    };

};
