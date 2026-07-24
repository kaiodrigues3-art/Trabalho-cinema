#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "persistencia.h"

// ==========================================
// FILMES
// ==========================================

void carregarFilmes(Filme filmes[], int *totalFilmes) {
    FILE *file = fopen("filmes.dat", "rb");
    if (file == NULL) {
        *totalFilmes = 0; // Arquivo não existe ainda
        return;
    }

    *totalFilmes = fread(filmes, sizeof(Filme), 100, file); // 100 é um limite de exemplo
    fclose(file);
    printf("[Persistencia] %d filme(s) carregado(s) com sucesso.\n", *totalFilmes);
}

void salvarFilmes(Filme filmes[], int totalFilmes) {
    FILE *file = fopen("filmes.dat", "wb");
    if (file == NULL) {
        printf("Erro ao abrir filmes.dat para escrita!\n");
        return;
    }

    fwrite(filmes, sizeof(Filme), totalFilmes, file);
    fclose(file);
    printf("[Persistencia] %d filme(s) salvo(s) com sucesso.\n", totalFilmes);
}

// ==========================================
// SALAS
// ==========================================

void carregarSalas(Sala salas[], int *totalSalas) {
    FILE *file = fopen("salas.dat", "rb");
    if (file == NULL) {
        *totalSalas = 0;
        return;
    }

    *totalSalas = fread(salas, sizeof(Sala), 100, file);
    fclose(file);
    printf("[Persistencia] %d sala(s) carregada(s) com sucesso.\n", *totalSalas);
}

void salvarSalas(Sala salas[], int totalSalas) {
    FILE *file = fopen("salas.dat", "wb");
    if (file == NULL) {
        printf("Erro ao abrir salas.dat para escrita!\n");
        return;
    }

    fwrite(salas, sizeof(Sala), totalSalas, file);
    fclose(file);
    printf("[Persistencia] %d sala(s) salva(s) com sucesso.\n", totalSalas);
}

// ==========================================
// SESSÕES
// ==========================================

void carregarSessoes(Sessao sessoes[], int *totalSessoes) {
    FILE *file = fopen("sessoes.dat", "rb");
    if (file == NULL) {
        *totalSessoes = 0;
        return;
    }

    *totalSessoes = fread(sessoes, sizeof(Sessao), 100, file);
    fclose(file);
    printf("[Persistencia] %d sessao(oes) carregada(s) com sucesso.\n", *totalSessoes);
}

void salvarSessoes(Sessao sessoes[], int totalSessoes) {
    FILE *file = fopen("sessoes.dat", "wb");
    if (file == NULL) {
        printf("Erro ao abrir sessoes.dat para escrita!\n");
        return;
    }

    fwrite(sessoes, sizeof(Sessao), totalSessoes, file);
    fclose(file);
    printf("[Persistencia] %d sessao(oes) salva(s) com sucesso.\n", totalSessoes);
}

// ==========================================
// RESERVAS
// ==========================================

void carregarReservas(Reserva reservas[], int *totalReservas) {
    FILE *file = fopen("reservas.dat", "rb");
    if (file == NULL) {
        *totalReservas = 0;
        return;
    }

    *totalReservas = fread(reservas, sizeof(Reserva), 100, file);
    fclose(file);
    printf("[Persistencia] %d reserva(s) carregada(s) com sucesso.\n", *totalReservas);
}

void salvarReservas(Reserva reservas[], int totalReservas) {
    FILE *file = fopen("reservas.dat", "wb");
    if (file == NULL) {
        printf("Erro ao abrir reservas.dat para escrita!\n");
        return;
    }

    fwrite(reservas, sizeof(Reserva), totalReservas, file);
    fclose(file);
    printf("[Persistencia] %d reserva(s) salva(s) com sucesso.\n", totalReservas);
}
