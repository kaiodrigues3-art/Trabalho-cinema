#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/secoes.h"
#include "../include/filmes.h"

// Função para buscar sessão por ID
Sessao* buscarSessaoPorId(Sessao sessoes[], int totalSessoes, int id) {
    for (int i = 0; i < totalSessoes; i++) {
        if (sessoes[i].id == id) {
            return &sessoes[i];
        }
    }
    return NULL;
}

// Função para verificar se o assento na linha/coluna está disponível (0 = 'O' Livre, 1 = 'X' Ocupado)
int assentoDisponivel(Sessao *sessao, int linha, int coluna) {
    if (sessao == NULL) {
        return 0;
    }
    // Valida os limites da matriz 3x5 (15 assentos)
    if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 5) {
        printf("Posicao de assento invalida! (Linhas: 0-2, Colunas: 0-4)\n");
        return 0;
    }
    
    // Retorna 1 se estiver livre (0), ou 0 se estiver ocupado (1)
    if (sessao->mapaAssentos[linha][coluna] == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Função para cadastrar uma nova sessão
void criarSessao(Sessao sessoes[], int *totalSessoes, Filme filmes[], int totalFilmes, Sala salas[], int totalSalas) {
    if (totalFilmes == 0) {
        printf("Erro: Nenhum filme cadastrado. Cadastre um filme primeiro!\n");
        return;
    }
    
    Sessao novaSessao;
    novaSessao.id = (*totalSessoes) + 1;

    printf("\n=== Criar Nova Sessao (ID: %d) ===\n", novaSessao.id);

    // Seleção de Filme
    printf("Escolha o ID do Filme:\n");
    for (int i = 0; i < totalFilmes; i++) {
        printf("  [%d] Filme ID %d\n", i + 1, filmes[i].id);
    }
    printf("ID do Filme: ");
    scanf("%d", &novaSessao.idFilme);

    // ID da Sala
    printf("Informe o ID da Sala: ");
    scanf("%d", &novaSessao.idSala);

    // Horário da Sessão
    printf("Informe o Horario da Sessao (ex: 16:30): ");
    scanf("%s", novaSessao.horario);

    // Idioma (Inglês / Português)
    printf("Informe o Idioma/Audio (1 - Portugues, 2 - Ingles): ");
    int opcaoIdioma;
    scanf("%d", &opcaoIdioma);
    if (opcaoIdioma == 2) {
        strcpy(novaSessao.idioma, "Ingles");
    } else {
        strcpy(novaSessao.idioma, "Portugues");
    }

    // Formato 3D
    printf("A sessao e em 3D? (1 - Sim, 0 - Nao): ");
    scanf("%d", &novaSessao.e3D);

    // Inicializa todos os 15 assentos (3x5) como Livres (0)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            novaSessao.mapaAssentos[i][j] = 0;
        }
    }

    sessoes[*totalSessoes] = novaSessao;
    (*totalSessoes)++;

    printf("-> Sessao criada com sucesso!\n");
}

// Função opcional para carregar/inicializar exemplos de sessões
void inicializarSessoesPadrao(Sessao sessoes[], int *totalSessoes) {
    // Exemplo de Sessão 1: Português 2D
    Sessao s1 = {
        .id = 1,
        .idFilme = 101,
        .idSala = 1,
        .horario = "14:30",
        .idioma = "Portugues",
        .e3D = 0
    };
    
    // Exemplo de Sessão 2: Inglês (Legendado) 3D
    Sessao s2 = {
        .id = 2,
        .idFilme = 102,
        .idSala = 2,
        .horario = "17:00",
        .idioma = "Ingles",
        .e3D = 1
    };

    // Exemplo de Sessão 3: Português 3D
    Sessao s3 = {
        .id = 3,
        .idFilme = 103,
        .idSala = 1,
        .horario = "20:00",
        .idioma = "Portugues",
        .e3D = 1
    };

    // Inicializa todos os assentos como livres (0)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            s1.mapaAssentos[i][j] = 0;
            s2.mapaAssentos[i][j] = 0;
            s3.mapaAssentos[i][j] = 0;
        }
    }

    sessoes[0] = s1;
    sessoes[1] = s2;
    sessoes[2] = s3;
    *totalSessoes = 3;
}
