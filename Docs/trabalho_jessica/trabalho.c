/*
Projeto: Planejador Financeiro
Autores: Nicole Naira Ribeiro da Silva & Bruno Santos Soares
Data de criação: 18/10/2025
Descrição: Estrutura inicial do projeto integrador
*/

#include <stdio.h>  /* inclui a biblioteca padrão */

enum opcao {  /* Define o enum para as opções do menu */
    informe_gastos = 1,
    calculadora_gastos_adicionais,
    saldo_mensal_atual,
    gastos_futuros,
    sair
};

int main() {
    /* Declaração de variáveis para os gastos fixos */
    double aluguel, energia, internet, agua, compras_supermercado;
    /* Variáveis para cálculos e saldos */
    double saldo_final, gastos_adicionais, total_gastos_mes;
    /* Variáveis para a renda */
    double salario, renda_extra;
    /* Variável para a soma dos gastos básicos */
    double gastos_basicos;
    /* Variável para armazenar a escolha do usuário no menu */
    int escolha;
    /* Variáveis para a calculadora de gastos adicionais */
    double gasto1, gasto2;
    /* Variáveis para controle e nomes na calculadora de gastos adicionais */
    char adicionar_gasto ;
    /* Variáveis de string para armazenar nomes de gastos */
    char gasto1Nome[100], gasto2Nome[100];


    printf("Digite o valor do seu salario: ");
    scanf("%lf", &salario); /* Ler e escreve o valor do salário */
    printf("Digite o valor da renda extra: ");
    scanf("%lf", &renda_extra); /* Ler e escreve o valor da renda extra */

    gastos_adicionais = 0.0;
    saldo_final = salario + renda_extra; /* Calcula o saldo inicial, que é a soma da renda total */
    gasto1 = 0.0;
    gasto2 = 0.0;
    /* Inicia um laço 'do-while' para o menu principal. */
    /* O menu será exibido e executado pelo menos uma vez. */
    do
    {  
        printf("\n========= MENU ==========\n");  /* Exibe as opções do menu */
        printf("1. Informe gastos\n2. Calculadora de gastos\n3. Gastos mensais atuais\n4. Gastos futuros (Em breve)\n5. Sair\n");
        printf("=========================\n");
        printf("Selecione a opcao: ");
        scanf ("%d", &escolha); /* Ler e escrever a escolha do usuário */

    switch (escolha)
        {
    case informe_gastos:  /* case de informação de dados */
    printf("Digite o valor do aluguel: ");
    scanf("%lf", &aluguel);
    printf("Digite o valor da conta de energia: ");
    scanf("%lf", &energia);
    printf("Digite o valor da conta de agua: ");
    scanf("%lf", &agua);
    printf("Digite o valor da conta de internet: ");
    scanf("%lf", &internet);
    printf("Digite o valor das compras supermercado do mes: ");
    scanf("%lf", &compras_supermercado); /* Pede e ler os valores dos gastos fixos */
    if (gastos_adicionais == 0)
    {
        printf ("informe os valor total de gastos adicionais: ");
        scanf ("%lf", &gastos_adicionais); /* Pede e ler um valor total para gastos adicionais */
    }

    gastos_basicos = aluguel + energia + agua + internet + compras_supermercado; /* calcula os gastos basicos e fixos */
    total_gastos_mes = gastos_basicos + gastos_adicionais; /* calcula todos os gastos do mês */
    saldo_final = (salario + renda_extra) - total_gastos_mes; /* calcula o saldo fora gastos */
    /* obs: esse bloco é necessario para processamento e salvamento dos dados acima, assim não precisando serem re-calculados toda hora. */

    printf("\n---------------------------------------------------------------------\n");
    printf ("O seu total de gastos no valor de R$ %2.lf foi Informado com sucesso!!", total_gastos_mes); /* Exibe o total de gastos informado */
    printf("\n---------------------------------------------------------------------");
        break;
   
    case calculadora_gastos_adicionais: /* calculadora dos gastos adicionais, gastos não planejaos ou planejados, mas que não são basicos à sobrevivencia. */
        printf ("\n--- Calculadora de Gastos Adicionais ---\n");
        printf ("informe o nome do Gasto adicional 1: ");
        scanf ("%s", gasto1Nome);
        printf ("digite o valor do gasto 1: ");
        scanf ("%lf", &gasto1); /* esse bloco lê nome e valor do gasto adicional. */

        do /* adicionado loop para adição de um segundo gasto */
        {  /* Obs: não adicionamos mais pois a logica se tornou confusa, será melhorado em breve. */
            printf ("você tem mais um Gasto a adicionar? (s/n): ");
            scanf (" %c", &adicionar_gasto);

            if (adicionar_gasto == 's')
            {
                printf ("digite o nome do seu segundo Gasto: ");
                scanf ("%s", gasto2Nome);
                printf ("digite o valor do seu outro gasto: ");
                scanf ("%lf", &gasto2);
                printf("Gastos informados!\n");
            }

            else if (adicionar_gasto == 'n')
            {
                printf ("Ok, gastos finalizados.\n");
            }
            else
            {
                printf ("Erro!!! Responda apenas com 's' ou 'n'.\n");
            } /* esse bloco trata-se da implementação do segundo gasto do usuario */
           
        } while (adicionar_gasto != 's' && adicionar_gasto != 'n'); /* para fim do loop e continuação do programa */
       
        gastos_adicionais = gasto1 + gasto2;
        total_gastos_mes = gastos_basicos + gastos_adicionais;
        saldo_final = (salario + renda_extra) - total_gastos_mes;

        printf ("\n-------------------------------------\n");
        printf ("Gastos adicionais (R$ %.2f) atualizados!\n", gastos_adicionais);
        printf ("Saldo recalculado!");
        printf ("\n-------------------------------------");
        break;

    case saldo_mensal_atual: /* essa case é um extrato, informa ao usuario o saldo já calculados automaticamente. */
    if (saldo_final == (salario + renda_extra)) /* já processa a case junto do calculo necessario para caso o usuario ainda não tenha informado os gastos */
    {
        printf ("\n==================================\n");
        printf ("voce nao informou seus gastos!!!");
        printf ("\n=================================="); /* caso o usuario não tenha informado os dados necessarios */

    } else if (saldo_final != (salario + renda_extra))
    {
    printf ("\n====================================\n");
    printf ("\nseus gastos atuais: %2.lf \n", total_gastos_mes);
    printf ("\nSeu saldo atual e de: %2.lf \n", saldo_final);
    printf ("\n====================================="); /* caso sucesso e dados informados, a saida padrão */

    } else {
        printf ("\n=====================================\n");
        printf ("\n======= Erro Desconhecido!! =========\n");
        printf ("\n=====================================\n"); /* em caso de algum erro, o sistema retornará esta mensagem */
    }
        break;
    case gastos_futuros: /* por enquanto não foi possivel devido a tempo e conhecimento, efetuar a implementação deste recurso. */
    printf ("Esta opcao, nao esta disponivel!! em breve sera implementada!!");
        break;
    case sair:
        printf ("Obrigado por utilizar nosso sistema!!!\n");
        break;
    default:
    printf ("Opcao invalida! Tente novamente.\n");
        break;
    }
    } while (escolha != sair); /* Sai do loop quando o usuário escolhe a opção 'sair' */

    return 0;
}
