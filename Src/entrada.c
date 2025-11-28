#include <stdio.h>
#include "../include/entrada.h"
#include "../include/globais.h"

void informarRenda() {

    printf(" .''..::..::. \n"); 
    printf(" :   '::''::' \n");
    printf(":: :  _  : :: \n");
    printf(" '..     ..' \n");
    printf("==================================\n");
    printf(".* $ + Planejador Financeiro $ *.\n");
    printf("\n==================================\n");
    printf("Bem vindo ao planejador financeiro!\n");
    printf("Informe sua renda.\n");
    printf("Digite o valor do seu salario: ");
    scanf("%lf", &dados.salario);
    printf("Digite o valor da renda extra (se houver): ");
    scanf("%lf", &dados.renda_extra);
}

void informarGastosFixos() {
    printf("\n--- Informar Gastos Fixos ---\n");
    printf("Digite o valor do aluguel: ");
    scanf("%lf", &dados.aluguel);
    printf("Digite o valor da conta de energia: ");
    scanf("%lf", &dados.energia);
    printf("Digite o valor da conta de agua: ");
    scanf("%lf", &dados.agua);
    printf("Digite o valor da conta de internet: ");
    scanf("%lf", &dados.internet);
    printf("Digite o valor das compras supermercado do mes: ");
    scanf("%lf", &dados.compras_supermercado);

    // Se ainda nao tiver gastos adicionais, da opcao de colocar um valor cheio
    if (dados.gastos_adicionais == 0.0) {
        printf("\n(Opcional) Informe o valor total de outros gastos adicionais: ");
        scanf("%lf", &dados.gastos_adicionais);
    }
}

void calculadoraGastos() {
    char nomeGasto[100];
    double valorGasto = 0.0;
    double totalGasto = 0.0;
    char continuar = 's';

    printf("\n--- Calculadora de Gastos Adicionais ---\n");
    printf("Vamos listar seus gastos extras.\n");
    
    // Feito loop para a quantidade de gastos adicionais poder ser infinita.
    do {
        printf("\nInforme o nome do gasto (ex: Netflix): ");
        scanf("%s", nomeGasto);
        
        printf("Digite o valor desse gasto: R$ ");
        scanf("%lf", &valorGasto);
        
        totalGasto = totalGasto + valorGasto;
        printf("Gasto adicionado! Total ate agora: R$ %.2f\n", totalGasto);

        printf("Voce quer adicionar mais um gasto? (s/n): ");
        scanf("%c", &continuar); 

    } while (continuar == 's' || continuar == 'S');
    
    printf("\nFinalizado! Total de gastos adicionais: R$ %.2f\n", totalGasto);
    
    // Guarda o total na struct global
    dados.gastos_adicionais = totalGasto;
}