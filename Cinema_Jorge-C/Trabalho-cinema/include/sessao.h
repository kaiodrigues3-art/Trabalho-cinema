#ifndef SECOES_H
#define SECOES_H

#include "structs.h"

/*
 * Estrutura para representar a Sessão de Cinema.
 * Inclui:
 * - id: Identificador único da sessão
 * - idFilme: ID do filme em exibição
 * - idSala: ID da sala onde ocorrerá a sessão
 * - horario: Horário da sessão (ex: "19:30")
 * - idioma: Idioma/Tipo de áudio ("Dublado", "Legendado" ou em inglês/português)
 * - e3D: Indicador se é sessão 3D (1 para Sim, 0 para Não)
 * - mapaAssentos: Matriz representando os assentos da sala (ex: 3 linhas x 5 colunas = 15 assentos)
 */
typedef struct {
    int id;
    int idFilme;
    int idSala;
    char horario[10];      // Ex: "14:00", "18:30"
    char idioma[20];       // Ex: "Dublado", "Legendado", "Ingles", "Portugues"
    int e3D;               // 1 = 3D, 0 = 2D
    int mapaAssentos[3][5]; // Matriz 2D para 15 assentos (0 = Livre 'O', 1 = Ocupado 'X')
} Sessao;

/*
 * Protótipos das funções (Pessoa 4 - Sessão)
 */

// Cria e cadastra uma nova sessão no sistema
void criarSessao(Sessao sessoes[], int *totalSessoes, Filme filmes[], int totalFilmes, Sala salas[], int totalSalas);

// Verifica se um assento em uma linha/coluna específica está livre (retorna 1) ou ocupado/inválido (retorna 0)
int assentoDisponivel(Sessao *sessao, int linha, int coluna);

// Busca e retorna o ponteiro para uma sessão com base no seu ID
Sessao* buscarSessaoPorId(Sessao sessoes[], int totalSessoes, int id);

// Função auxiliar para inicializar sessões padrão (3 filmes, 15 assentos, opções em inglês/português e 3D)
void inicializarSessoesPadrao(Sessao sessoes[], int *totalSessoes);

#endif // SECOES_H
