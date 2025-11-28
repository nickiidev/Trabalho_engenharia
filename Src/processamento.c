#include <stdio.h>
#include "../include/processamento.h"
#include "../include/globais.h"

void calcularTotais() {
    dados.renda_total = dados.salario + dados.renda_extra;
    dados.gastos_basicos = dados.aluguel + dados.energia + dados.agua + dados.internet + dados.compras_supermercado;
    dados.total_gastos_mes = dados.gastos_basicos + dados.gastos_adicionais;
    dados.saldo_final = dados.renda_total - dados.total_gastos_mes;
}

void planejarObjetivoFuturo() {
    char nomeObjetivo[100];
    double valorObjetivo;
    int mesesDesejados;
    double economiaNecessaria;
    double mesesNecessariosSaldo;

    // Atualiza contas antes de mostrar
    calcularTotais(); 

    printf("\n==== Planejamento de Objetivos Futuros ====\n");
    printf("Qual e o nome do seu objetivo? (ex: Carro, Viagem): ");
    scanf("%s", nomeObjetivo);
    printf("Qual o valor total desse objetivo? R$ ");
    scanf("%lf", &valorObjetivo);
    printf("Em quantos meses voce quer conquistar isso? ");
    scanf("%d", &mesesDesejados);

    if (mesesDesejados <= 0) {
        printf("Erro: Meses deve ser maior que zero.\n");
        return;
    }

    economiaNecessaria = valorObjetivo / mesesDesejados;
    
    printf("\n--------------- ANALISE ------------------\n");
    printf("Voce mensalmente gasta um valor de R$ %.2f.\n", dados.total_gastos_mes);
    
    if (dados.saldo_final <= 0) {
        printf("Atualmente nao te sobra nada no mes (Saldo: R$ %.2f).\n", dados.saldo_final);
        printf("Voce precisa reduzir gastos para planejar algo.\n");
    } 
    else {
        if (dados.saldo_final >= economiaNecessaria)
        {
        printf("Para atingir esse objetivo, te sobram no mes R$ %.2f.\n", dados.saldo_final);
        
        // Calcula meses necessarios com o saldo atual
        mesesNecessariosSaldo = valorObjetivo / dados.saldo_final;

        printf("\nPlanejamentos\n");
        
        printf("1. Pela sua renda atual:\n");
        printf("Voce pode economizar R$ %.2f mensalmente (seu saldo livre)\n", dados.saldo_final);
        printf("e conquistar o seu objetivo em %.1f meses.\n", mesesNecessariosSaldo);

        printf("\n2. Pelo prazo estipulado (%d meses):\n", mesesDesejados);
        printf("Voce pode economizar R$ %.2f por mes e conquistar conforme o prazo.\n", economiaNecessaria);
        }
        if (dados.saldo_final < economiaNecessaria) {
            printf("(Obs: Seu saldo atual (%.2f) nao cobre essa opcao. Faltam R$ %.2f por mes (Da teu jeito de gastar menos que tu consegue)).\n", dados.saldo_final, dados.saldo_final - (economiaNecessaria / mesesDesejados));
        }
    }
    printf("-----------------------------------------\n");
}