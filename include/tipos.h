#ifndef TIPOS_H
#define TIPOS_H

// Estrutura principal dos dados
typedef struct {
    double salario;
    double renda_extra;
    double renda_total;

    double aluguel;
    double energia;
    double agua;
    double internet;
    double compras_supermercado;

    double gastos_adicionais; // Soma dos gastos extras
    
    double gastos_basicos;
    double total_gastos_mes;
    double saldo_final;

} DadosFinanceiros;

#endif