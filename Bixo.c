/*======================================================================================================================================
=====================================================JOGO DO BIXU v1.0.0===============================================================
======================================================================================================================================*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Onde a gambiarra começa
int main() {
setlocale(LC_ALL, "Portuguese");

/*============================================================ Variáveis =============================================================*/
//Variaveis que armazenam os resultados
    int fx11;
    int fx12;
    int fx21;
    int fx22;
    int fx31; 
    int fx32; 
    int fx41;
    int fx42;
    int fx51;
    int fx52;

//Variaveis que armazenam os resultados em Strings ao inves de numeros
    char sfx1 [4];
    char sfx2 [4];
    char sfx3 [4];
    char sfx4 [4];
    char sfx5 [4];

//Array para armazenar os valores dos bixos
    int avestruz[4] = {1, 2, 3 ,4};
    int aguia[4] = {5, 6, 7, 8};
    int burro[4] = {9, 10, 11, 12};
    int borboleta[4] = {13, 14, 15, 16};
    int cachorro[4] = {17, 18, 19, 20};
    int cabra[4] = {21, 22, 23, 24};
    int carneiro[4] = {25, 26, 27, 28};
    int camelo[4] = {29, 30, 31, 32};
    int cobra[4] = {33, 34, 35, 36};
    int coelho[4] = {37, 38, 39, 40};
    int cavalo[4] = {41, 42, 43, 44};
    int elefante[4] = {45, 46, 47, 48};
    int galo[4] = {49, 50, 51, 52};
    int gato[4] = {53, 54, 55, 56};
    int jacare[4] = {57, 58, 59, 60};
    int leao[4] = {61, 62, 63, 64};
    int macaco[4] = {65, 66, 67, 68};
    int porco[4] = {69, 70, 71, 72};
    int pavao[4] = {73, 74, 75, 76};
    int peru[4] = {77, 78, 79, 80};
    int touro[4] = {81, 82, 83, 84};
    int tigre[4] = {85, 86, 87, 88};
    int urso[4] = {89, 90, 91, 92};
    int veado[4] = {93, 94, 95, 96};
    int vaca[4] = {97, 98, 99, 00};

//Variavél para receber opção escolhida no menu
    int opcao_menu;

//Variavél para receber tipo de aposta escolhida pelo usuario
    int aposta_tipo;

//Variavél para receber valores apostados
    int aposta1;
    int aposta2;

//Variável para receber aposta na Milhar
    int numeros_aposta_milhar;

//Varivél para recber aposta no bixo
    int bixo_escolha;

//Variavél para armazenar o valor a ser apostado
    int valor_aposta;

//Variável para armazenar o valor dos premios
    int valor_premio_primeira_faixa;
    int valor_premio_demais_faixas;
//Variavél para armazenar os valores da carteira
    int valor_carteira = 0;

//Variavél para armazenar valor a se adcionar a carteira
    int novo_valor_carteira;

/*============================================================ Funções ===============================================================*/
//Função que define numeros aleatórios para as variaveis
void define_numeros() {

    srand(time(0));

    fx11 = 01;
    fx12 = 02;
    fx21 = 03;
    fx22 = 04;
    fx31 = rand() % 100;
    fx32 = rand() % 100;
    fx41 = rand() % 100;
    fx42 = rand() % 100;
    fx51 = rand() % 100;
    fx52 = rand() % 100;   
    }
 
 //Função do menu inicial
void menu() {
    printf("\n===Bem vindo ao jogo do bixu!===");
    printf("\nVersão atual: v1.0.0 alpha.\n");
    printf("\n1) Apostar.\n2) Depositar.\n3) Consultar carteira. \n4) Sair.");
    printf("\nEscolha o que deseja fazer: ");
}

//Função para subtrair valor apostado da carteira
void subtrai_carteira() {
    valor_carteira = valor_carteira - valor_aposta;
}

 //Função para receber duas dezenas 
void recebe_valores_aposta_dezena() {
    printf("\nEscolha duas dezenas que deseja apostar.");
    do{
    printf("\nEscolha a primeira dezena: ");
    scanf("%d", &aposta1);
    if(aposta1 > 99 || aposta1 < 0) {
        printf("\nDezena inválida, digite uma dezena entre 0 e 99!");
        }
    } while(aposta1 > 99 || aposta1 < 0);
    do{
    printf("\nEscolha a segunda dezena: ");
    scanf("%d", &aposta2);
    if(aposta2 > 99 || aposta2 < 0) {
        printf("\nDezena inválida, digite uma dezena entre 0 e 99!");
        }
    } while(aposta2 > 99 || aposta2 < 0);
    printf("Dezenas escolhidas: %d e %d.\n", aposta1, aposta2);
}

//Função para receber valor aposta milhar
void recebe_valores_aposta_milhar() {
    printf("\nVocê escolheu a aposta na milhar!");
     while(numeros_aposta_milhar > 9998 || numeros_aposta_milhar < 0) {
    printf("\nDigite a milhar de deseja apostar: ");
    scanf("%d", &numeros_aposta_milhar);
        if(numeros_aposta_milhar > 9998 || numeros_aposta_milhar < 0001) {
            printf("\nMilhar inválida, digite um numero entre 0001 e 9998!");
        }
    }
    printf("\nNúmero escolhido: %d", numeros_aposta_milhar);
}

//Função de calcular premiação na primeira faixa
void calculo_aposta_cabeca() {
    valor_premio_primeira_faixa = valor_aposta * 60;
    valor_carteira = valor_premio_primeira_faixa;
    subtrai_carteira();
}

//Função de calcular premiação nas demais faixas
void calculo_aposta_dezena() {
    valor_premio_demais_faixas = valor_aposta * 12;
    valor_carteira = valor_premio_demais_faixas;
    subtrai_carteira();
}

//Função para analisar se ganhou na primeira faixa
void analise_aposta_cabeca() {
    if(aposta1 == fx11 || aposta1 == fx12 || aposta2 == fx11 || aposta2 == fx12){
        calculo_aposta_cabeca();
        printf("\nVocê ganhou %d reais na primeira faixa!\n", valor_premio_primeira_faixa);
    } else {
        printf("\nVocê não ganhou na primeira faixa!");
    }
}

//Função para analisar se ganhou nas demais faixas 
void analise_aposta_dezena() {
    if(aposta1 == fx11 || aposta1 == fx12 || aposta2 == fx11 || aposta2 == fx12
    || aposta1 == fx21 || aposta1 == fx22 || aposta1 == fx31 || aposta1 == fx32  
    || aposta1 == fx41 || aposta1 == fx42 || aposta1 == fx51 || aposta1 == fx52
    || aposta2 == fx21 || aposta2 == fx22 || aposta2 == fx31 || aposta2 == fx32  
    || aposta2 == fx41 || aposta2 == fx42 || aposta2 == fx51 || aposta2 == fx52
    ) {
        calculo_aposta_dezena();
        printf("\nVocê ganhou %d reais nas demais faixas!\n", valor_premio_demais_faixas);
    } else {
        printf("\nVocê não ganhou da segunda a quarta faixa!\n");
    }
}

//Função para analisar se ganhou na milhar
void analise_aposta_milhar() {
    if(numeros_aposta_milhar = sfx1) {
        printf("\nVocê ganhou na milhar!");
        
    } else {
        printf("\nVocê não ganhou na milhar!");
    }
}

//Função para printar resultados
void resultados() {
    printf("\nResultados do jogo do bixo de hoje!");
    printf("\nprimeira faixa: %d, %d", fx11, fx12);
    printf("\nsegunda faixa: %d, %d", fx21, fx22);
    printf("\nterceira faixa: %d, %d", fx31, fx32);
    printf("\nquarta faixa: %d, %d", fx41, fx42);
    printf("\nquinta faixa: %d, %d\n", fx51, fx52);
}

//Função para mostrar o valor atual na carteira
void carteira_atual() {
    printf("Você possui atualmente %d reais em sua carteira.\n", valor_carteira);
}

//Função para depositar na carteira
void deposito() {
    do{
        printf("\nDigite o valor que deseja depositar a sua carteira: ");
        scanf("%d", &novo_valor_carteira);
            if(novo_valor_carteira <= 0) {
                printf("Valor de depósito não pode ser 0 ou números negativos!");
            } else {
        valor_carteira = valor_carteira + novo_valor_carteira;
        printf("Você depositou %d em sua carteira!\n", novo_valor_carteira);
        carteira_atual();
        }
    } while(novo_valor_carteira <= 0);
}

//Função aposta de dezena na cabeça
void aposta_dezena_cabeca() {
            do{
                printf("\nDigite o valor que deseja apostar: ");
                scanf("%d", &valor_aposta);
                    if (valor_aposta <= 0) {
                        printf("Valor de aposta não pode ser 0 ou números negativos!!\n");
                    } else if(valor_aposta <= valor_carteira) {
                        printf("Você apostou %d reais!\n", valor_aposta);
                        recebe_valores_aposta_dezena();
                        analise_aposta_cabeca();
                        resultados();
                    } else {
                        printf("Valor de aposta desejado é maior que o valor da carteira. \n");
                        printf("Tente novamente com outro valor ou deposite mais dinheiro em sua carteira.");
                    }
            } while(valor_aposta <= 0);
}

//Função aposta de dezena
void aposta_dezena() {
            do{
                printf("\nDigite o valor que deseja apostar: ");
                scanf("%d", &valor_aposta);
                    if (valor_aposta <= 0) {
                        printf("Valor de aposta não pode ser 0 ou números negativos!!\n");
                    } else if(valor_aposta <= valor_carteira) {
                        printf("Você apostou %d reais!\n", valor_aposta);
                        recebe_valores_aposta_dezena();
                        analise_aposta_dezena();
                        resultados();
                    } else {
                        printf("Valor de aposta desejado é maior que o valor da carteira. \n");
                        printf("Tente novamente com outro valor ou deposite mais dinheiro em sua carteira.");
                    }
            } while(valor_aposta <= 0);
}

//Função aposta na Milhar
void aposta_milhar() {
    do{
        printf("\nDigite o valor que deseja apostar: ");
        scanf("%d", &valor_aposta);
            if (valor_aposta <= 0) {
                printf("Valor de aposta não pode ser 0 ou números negativos!!\n");
            } else if(valor_aposta <= valor_carteira) {
                printf("Você apostou %d reais!\n", valor_aposta);
                recebe_valores_aposta_milhar();
                analise_aposta_milhar();
                resultados();
            } else {
                printf("Valor de aposta desejado é maior que o valor da carteira. \n");
                printf("Tente novamente com outro valor ou deposite mais dinheiro em sua carteira.");
            }
    } while(valor_aposta <= 0);
}

//Função aposta no Bixo
void aposta_no_bixo() {
    printf("1. AVESTRUZ\n2. ÁGUIA\n3. BURRO\n4. BORBOLETA\n5. CACHORRO\n6. CABRA\n7. CARNEIRO\n8. CAMELO\n9. COBRA\n10. COELHO\n11. CAVALO\n12. ELEFANTE\n13. GALO\n14. GATO\n15. JACARÉ\n16. LEÃO\n17. MACACO\n18. PORCO\n19. PAVÃO\n20. PERU\n21. TOURO\n22. TIGRE\n23. URSO\n24. VEADO\n25. VACA\n");
    printf("Escolha o bixo: ");
    scanf("%d", &bixo_escolha);
        switch (bixo_escolha) {
            case 1:
                printf("Bixo escolhido: Avestruz\n");
                break;
            case 2:
                printf("Bixo escolhido: Aguia\n");
                break;
            case 3:
                printf("Bixo escolhido: Burro\n");
                break;
            case 4:
                printf("Bixo escolhido: Borboleta\n");
                break;
            case 5:
                printf("Bixo escolhido: Cachorro\n");
                break;
            case 6:
                printf("Bixo escolhido: Cabra\n");
                break;
            case 7:
                printf("Bixo escolhido: Carneiro\n"); 
                break;
            case 8:
                printf("Bixo escolhido: Camelo\n");
                break;
            case 9:
                printf("Bixo escolhido: Cobra\n");
                break;
            case 10:
                printf("Bixo escolhido: Coelho\n");
                break;
            case 11:
                printf("Bixo escolhido: Cavalo\n");
                break;
            case 12:
                printf("Bixo escolhido: Elefante\n");
                break;
            case 13:
                printf("Bixo escolhido: Galo\n");
                break;
            case 14:
                printf("Bixo escolhido: Gato\n"); 
                break;       
            case 15:
                printf("Bixo escolhido: Jacaré\n");
                break;
            case 16:
                printf("Bixo escolhido: Leão\n");
                break;
            case 17:
                printf("Bixo escolhido: Macaco\n");
                break;
            case 18:
                printf("Bixo escolhido: Porco\n");
                break;
            case 19:
                printf("Bixo escolhido: Pavão\n");
                break;
            case 20:
                printf("Bixo escolhido: Peru\n");
                break;
            case 21:
                printf("Bixo escolhido: Touro\n");
                break;
            case 22:
                printf("Bixo escolhido: Tigre\n"); 
                break;
            case 23:
                printf("Bixo escolhido: Urso\n");
                break;
            case 24:
                printf("Bixo escolhido: Veado\n");
                break;
            case 25:
                printf("Bixo escolhido: Vaca\n");
                break;
        default:
            printf("Opção inválida!\n");
        }
}

//Função que converte os resultados em string
void converter_resultados_em_string() {
    sprintf(sfx1, "%d%d", fx11, fx12);   
    sprintf(sfx2, "%d%d", fx21, fx22);
    sprintf(sfx3, "%d%d", fx31, fx32);
    sprintf(sfx4, "%d%d", fx41, fx42);
    sprintf(sfx5, "%d%d", fx51, fx52);
}

//Função para escolher o tipo de aposta
void aposta_escolha() {
    do{
    printf("\n1) Dezena na Cabeça.\n2) Dezena.\n3) Centena. \n4) Milhar. \n5) Bixo.");
    printf("\nEscolha que tipo de aposta deseja fazer: ");
    scanf("%d", &aposta_tipo);
        if(aposta_tipo == 1) {
            printf("\nAposta Escolhida: Dezena na Cabeça.");
            aposta_dezena_cabeca();

        } else if(aposta_tipo == 2){
            printf("\nAposta Escolhida: Dezena.");
            aposta_dezena();

        } else if(aposta_tipo == 3){
            printf("\nAposta Escolhida: Centena.");

        } else if(aposta_tipo == 4){
            printf("\nAposta Escolhida: Milhar.");
            aposta_milhar();

        } else if(aposta_tipo == 5){
            printf("\nAposta Escolhida: Bixo.\n");
            aposta_no_bixo();
        } else {
            printf("\nAposta escolhida inválida, digite o número novamente.");
        }
    } while (aposta_tipo > 4 || aposta_tipo < 1);
}

//Função do Menu Princiapl
void menu_principal() {
do {
    menu();
        scanf("%d", &opcao_menu);
        
        if (opcao_menu == 1) {
            aposta_escolha();

        } else if (opcao_menu == 2) {
            deposito();

        } else if (opcao_menu == 3) {
            carteira_atual();

        } else if (opcao_menu == 4) {
            printf("\nVocê escolheu sair.");

        } else {
            printf("\nOpção inválida.\n");
        }
    } while (opcao_menu != 4);
}

/*======================================================= Execução do código ========================================================*/
define_numeros();
converter_resultados_em_string();
menu_principal();

    return 0;
}
