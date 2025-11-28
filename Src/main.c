/*
Projeto: Planejador Financeiro
Autores: Nicole Naira Ribeiro da Silva & Bruno Santos Soares
Data: 27/11/2025
Descrição: Projeto Integrador - Parte 3
*/

#include <stdio.h>
#include "../include/tipos.h"       
#include "../include/globais.h"      
#include "../include/entrada.h"      
#include "../include/processamento.h"
#include "../include/saida.h"        

// Variavel global da struct
DadosFinanceiros dados; 

enum opcao {
    informe_gastos = 1,
    calculadora_gastos_adicionais,
    saldo_mensal_atual,
    gastos_futuros,
    sair
};

int main() {
    int escolha;

    // Zera as variaveis pra nao dar erro
    dados.gastos_adicionais = 0.0;
    dados.aluguel = 0.0; dados.energia = 0.0; dados.agua = 0.0; 
    dados.internet = 0.0; dados.compras_supermercado = 0.0;

    // Pede renda logo no inicio
    informarRenda();
    calcularTotais(); 

    // Menu principal
    do {
        escolha = exibirMenu();

        switch (escolha) {
            case informe_gastos:
                informarGastosFixos();
                calcularTotais(); 
                printf("\nGastos fixos informados!\n");
                break;

            case calculadora_gastos_adicionais:
                calculadoraGastos();
                calcularTotais(); 
                printf("\nGastos adicionais calculados!\n");
                break;

            case saldo_mensal_atual:
                calcularTotais(); 
                exibirSaldo();
                break;

            case gastos_futuros:
                planejarObjetivoFuturo();
                break;

            case sair:
                printf("Obrigado por utilizar nosso sistema!\n");
                break;

            default:
                printf("Opcao invalida!!!\n");
                break;
        }

    } while (escolha != sair);

    return 0;
}