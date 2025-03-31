/*Desafio no nível mestre*/
#include <stdio.h>
#include <stdlib.h> /*bibliotaca usada para limpar o terminal*/
#include <string.h> /*biblioteca usada para capturar string composta, ou seja com espaço ou mais de uma palavra*/

/*Variaveis da carta do super trunfo e algumas usadas no código*/
struct carta {
    int populacao;
    float area;
    float PIB;
    int turist;
    float densidade;
    float PIBC;
    int escolha;
    float guarda1;
    float guarda2;
};

int main() {
    struct carta cart[2]; /*linkando as variaves com o main*/
    float result1;
    float result2;
    char pais[50];
    char pais2[50];

    /*captura das informações das cartas*/
    for (size_t i = 0; i < 2; i++) {

        printf("---------- Cadastro da carta %d: -------------\n", i + 1);

        /*if e else para capturar o nome da cidade mesmo se for uma string composta*/
        if (i == 0)/*carta 1*/
        {
            printf("Nome do Pais: ");
            fgets(pais, sizeof(pais), stdin); /*captura do nome da cidade*/
            if (pais[strlen(pais) - 1] == '\n') pais[strlen(pais) - 1] = '\0'; /*retirar o "\n" ou o "enter" da variavel cidade*/
        } else /*carta 2*/
        {
            printf("Nome do Pais: ");
            fgets(pais2, sizeof(pais2), stdin); /*captura do nome da cidade*/
            if (pais2[strlen(pais2) - 1] == '\n') pais2[strlen(pais2) - 1] = '\0'; /*retirar o "\n" ou o "enter" da variavel cidade*/
        }
        
        printf("Quantidade da Populacao: ");
        scanf("%d", &cart[i].populacao);  

        printf("Quantidade de area: ");
        scanf("%f", &cart[i].area);

        printf("Quantidade de PIB: ");
        scanf("%f", &cart[i].PIB);

        printf("Quantidade de pontos turisticos: ");
        scanf("%d", &cart[i].turist);  

        /*Calculos das variaves adicionais*/
        cart[i].densidade = cart[i].populacao / cart[i].area;
        cart[i].PIBC = cart[i].PIB / cart[i].populacao;
        getchar(); /*função utilizada para limpar o fgets, para não bugar na captura da segunda carta*/
    }

    system("cls"); /*limpeza do terminal*/

    /*escolha da primeira variavel a ser comparada*/
    printf(
        "Escolha qual será o primeiro atributo comparado:\n 1-Pais(não compara, apenas mostra o pais)\n 2-Populacao \n 3- Area \n 4- PIB \n 5- Pontos turisticos \n 6- Densidade \n 7- PIB per Capita\n"
        );
    scanf("%d", &cart[0].escolha);

    system("cls"); /*limpeza do terminal*/

    /*menu dinamico, switch baseado na escolha acima*/
    switch (cart[0].escolha)
    {
    case 1:
        printf(
            "Escolha qual será o primeiro atributo comparado:\n 2-Populacao \n 3- Area \n 4- PIB \n 5- Pontos turisticos \n 6- Densidade \n 7- PIB per Capita\n"
            );
        scanf("%d", &cart[1].escolha);
        break;
    case 2:
        printf(
            "Escolha qual será o primeiro atributo comparado:\n 1-Pais(não compara, apenas mostra o pais)\n 3- Area \n 4- PIB \n 5- Pontos turisticos \n 6- Densidade \n 7- PIB per Capita\n"
            );
        scanf("%d", &cart[1].escolha);
        break;  
    case 3:
        printf(
            "Escolha qual será o primeiro atributo comparado:\n 1-Pais(não compara, apenas mostra o pais)\n 2-Populacao \n 4- PIB \n 5- Pontos turisticos \n 6- Densidade \n 7- PIB per Capita\n"
            );
        scanf("%d", &cart[1].escolha);
        break;
    case 4:
        printf(
            "Escolha qual será o primeiro atributo comparado:\n 1-Pais(não compara, apenas mostra o pais)\n 2-Populacao \n 3- Area \n 5- Pontos turisticos \n 6- Densidade \n 7- PIB per Capita\n"
            );
        scanf("%d", &cart[1].escolha);
        break;
    case 5: 
        printf(
            "Escolha qual será o primeiro atributo comparado:\n 1-Pais(não compara, apenas mostra o pais)\n 2-Populacao \n 3- Area \n 4- PIB \n 6- Densidade \n 7- PIB per Capita\n"
            );
        scanf("%d", &cart[1].escolha);
        break;
    case 6:
        printf(
            "Escolha qual será o primeiro atributo comparado:\n 1-Pais(não compara, apenas mostra o pais)\n 2-Populacao \n 3- Area \n 4- PIB \n 5- Pontos turisticos \n 7- PIB per Capita\n"
            );
        scanf("%d", &cart[1].escolha);
        break;
    case 7:
        printf(
            "Escolha qual será o primeiro atributo comparado:\n 1-Pais(não compara, apenas mostra o pais)\n 2-Populacao \n 3- Area \n 4- PIB \n 5- Pontos turisticos \n 6- Densidade \n"
            );
        scanf("%d", &cart[1].escolha);
        break;
    default:
        printf("\nNumero/caractere inválido\n");
        break;
    }

    system("cls"); /*limpeza do terminal*/

    /*Comparação/ apresentação dos dados*/
    for (size_t i = 0; i < 2; i++)
    {
        switch (cart[i].escolha){
        case 1:
            printf("\n");
            printf("\n-------- Nome dos Paises --------\n");
            printf("País carta 1: %s\n", pais);
            printf("País carta 2: %s\n \n", pais2);
            break;
        case 2:
            /*variaveis para calcular o resultado final*/
            cart[i].guarda1 = cart[0].populacao;
            cart[i].guarda2 = cart[1].populacao;

            printf("\n------ Resultado -------\n");
            printf("Carta 1 - Populacao (%s): %d\n", pais, cart[0].populacao);
            printf("Carta 2 - Populacao (%s): %d\n", pais2, cart[1].populacao);
            if (cart[0].populacao == cart[1].populacao)
            {
                printf("Carta 1 e Carta 2 empataram\n \n");
                break;
            }
            
            printf((cart[0].populacao > cart[1].populacao) ? "Carta 1 (" : "Carta 2 (");
            printf((cart[0].populacao > cart[1].populacao) ? "%s", pais : "%s", pais2);
            printf(") venceu \n \n");
            break;
        case 3:
            /*variaveis para calcular o resultado final*/
            cart[i].guarda1 = cart[0].area;
            cart[i].guarda2 = cart[1].area;

            printf("\n------ Resultado -------\n");
            printf("Carta 1 - area (%s): %f\n", pais, cart[0].area);
            printf("Carta 2 - area (%s): %f\n", pais2, cart[1].area);
            if (cart[0].area == cart[1].area)
            {
                printf("Carta 1 e Carta 2 empataram\n \n");
                break;
            }
            
            printf((cart[0].area > cart[1].area) ? "Carta 1 (" : "Carta 2 (");
            printf((cart[0].area > cart[1].area) ? "%s", pais : "%s", pais2);
            printf(") venceu \n \n");
            break;
        case 4:
            /*variaveis para calcular o resultado final*/
            cart[i].guarda1 = cart[0].PIB;
            cart[i].guarda2 = cart[1].PIB;

            printf("\n------ Resultado -------\n");
            printf("Carta 1 - PIB (%s): %f\n",pais, cart[0].PIB);
            printf("Carta 2 - PIB (%s): %f\n", pais2, cart[1].PIB);
            if (cart[0].PIB == cart[1].PIB)
            {
                printf("Carta 1 e Carta 2 empataram\n \n");
                break;
            }
            
            printf((cart[0].PIB > cart[1].PIB) ? "Carta 1 (" : "Carta 2 (");
            printf((cart[0].PIB > cart[1].PIB) ? "%s", pais : "%s", pais2);
            printf(") venceu \n \n");
            break;
            break;
        case 5:
            /*variaveis para calcular o resultado final*/
            cart[i].guarda1 = cart[0].turist;
            cart[i].guarda2 = cart[1].turist;

            printf("\n------ Resultado -------\n");
            printf("Carta 1 - Pontos Turisticos (%s): %d\n", pais, cart[0].turist);
            printf("Carta 2 - Pontos Turisticos (%s): %d\n", pais2, cart[1].turist);
            if (cart[0].turist == cart[1].turist)
            {
                printf("Carta 1 e Carta 2 empataram\n \n");
                break;
            }
            printf((cart[0].turist > cart[1].turist) ? "Carta 1 (" : "Carta 2 (");
            printf((cart[0].turist > cart[1].turist) ? "%s", pais : "%s", pais2);
            printf(") venceu \n \n");
            break;
        case 6: 
            /*variaveis para calcular o resultado final*/
            cart[i].guarda1 = cart[0].densidade;
            cart[i].guarda2 = cart[1].densidade;

            printf("\n------ Resultado -------\n");
            printf("Carta 1 - Densidade (%s): %f\n", pais, cart[0].densidade);
            printf("Carta 2 - Densidade (%s): %f\n", pais2, cart[1].densidade);
            if (cart[0].densidade == cart[1].densidade)
            {
                printf("Carta 1 e Carta 2 empataram\n \n");
                break;
            }
            printf((cart[0].densidade < cart[1].densidade) ? "Carta 1 (" : "Carta 2 (");
            printf((cart[0].densidade < cart[1].densidade) ? "%s", pais : "%s", pais2);
            printf(") venceu \n \n");
            break;
        case 7:
            /*variaveis para calcular o resultado final*/
            cart[i].guarda1 = cart[0].PIBC;
            cart[i].guarda2 = cart[1].PIBC;

            printf("\n------ Resultado -------\n");
            printf("Carta 1 - PIB per Capita (%s): %f\n", pais, cart[0].PIBC);
            printf("Carta 2 - PIB per Capita (%s): %f\n", pais2, cart[1].PIBC);
            if (cart[0].PIBC == cart[1].PIBC)
            {
                printf("Carta 1 e Carta 2 empataram\n \n");
                break;
            }
            
            printf((cart[0].PIBC > cart[1].PIBC) ? "Carta 1 (" : "Carta 2 (");
            printf((cart[0].PIBC > cart[1].PIBC) ? "%s", pais : "%s", pais2);
            printf(") venceu \n \n");
            break;

        default:
            printf("\nNumero/caractere inválido\n \n");
            break;
        }
    }

    /*calculando o resultado da soma das duas variaveis*/
    result1 = cart[0].guarda1 + cart[1].guarda1;
    result2 = cart[0].guarda2 + cart[1].guarda2;

    /*apresentação do resultado da comparação*/
    printf("\n--------- Soma e Resultado -----------\n");

    printf("Resultado da soma da carta 1: %f\n", result1);
    printf("Resultado da soma da carta 2: %f\n", result2);
    if (result1 == result2)
    {
        printf("Soma da carta 1 e soma da carta 2 empatou.");
    } else
    {
        printf((result1 > result2) ? "Carta 1 (" : "Carta 2 (");
        printf((result1 > result2) ? "%s", pais : "%s", pais2);
        printf(") venceu \n \n");
    }
    
    printf("--------- Fim Do Jogo ------------\n");
    printf("\n");
    printf("Obrigado por jogar.");
    
    return 0;
}
