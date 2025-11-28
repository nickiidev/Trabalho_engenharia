#include <stdio.h>
#include <stdlib.h> 
#include "../include/saida.h"
#include "../include/globais.h"

int exibirMenu() {
    int escolha_menu;
    
    printf("\n_____________ .::..::. _____________\n");
    printf("-------------.'::''::'.-------------\n");

    printf("1. Informe gastos\n");
    printf("2. Calculadora de gastos adicionais\n");
    printf("3. Gastos mensais atuais (Saldo)\n");
    printf("4. Planejar Objetivo Futuro\n");
    printf("5. Sair\n");
    printf("------------------------------------\n");
    printf("Selecione a opcao: ");
    scanf("%d", &escolha_menu);
    return escolha_menu;
}

void exibirSaldo() {
    if (dados.saldo_final == dados.renda_total && dados.total_gastos_mes == 0) {
        printf("\n==================================\n");
        printf("Voce nao informou seus gastos!!!");
        printf("\n==================================");
    } else {
        printf("\n====================================\n");
        printf("\nSua Renda Total: R$ %.2f", dados.renda_total);
        printf("\nSeus Gastos Atuais: R$ %.2f \n", dados.total_gastos_mes);
        printf("\nSeu Saldo Atual e de: R$ %.2f \n", dados.saldo_final);
        printf("\n=====================================");
    }
}