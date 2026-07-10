#ifndef CINEMA_H
#define CINEMA_H

/* ================== CONSTANTES ================== */

#define MAX_LINHAS     10
#define MAX_COLUNAS    10
#define MAX_FILMES     50
#define MAX_SALAS      10
#define MAX_SESSOES    100
#define MAX_RESERVAS   500

#define ARQ_FILMES     "data/filmes.dat"
#define ARQ_SALAS      "data/salas.dat"
#define ARQ_SESSOES    "data/sessoes.dat"
#define ARQ_RESERVAS   "data/reservas.dat"

/* ================== STRUCTS ================== */

typedef struct {
    int  id;
    char titulo[100];
    char genero[50];
    int  duracaoMin;
    char classificacao[10];
} Filme;

typedef struct {
    int  id;
    char nome[30];
    int  linhas;
    int  colunas;
    char layout[MAX_LINHAS][MAX_COLUNAS]; /* 'O' = assento, 'X' = vao */
} Sala;

typedef struct {
    int  id;
    int  idFilme;
    int  idSala;
    char dataHora[20];
    char assentos[MAX_LINHAS][MAX_COLUNAS]; /* 'O' livre, 'R' reservado, 'X' vao */
} Sessao;

typedef struct {
    int  id;
    int  idSessao;
    char cliente[50];
    int  linha;
    int  coluna;
} Reserva;

/* ================== PESSOA 1 - PERSISTENCIA ================== */

void carregarFilmes(Filme filmes[], int *totalFilmes);
void salvarFilmes(Filme filmes[], int totalFilmes);

void carregarSalas(Sala salas[], int *totalSalas);
void salvarSalas(Sala salas[], int totalSalas);

void carregarSessoes(Sessao sessoes[], int *totalSessoes);
void salvarSessoes(Sessao sessoes[], int totalSessoes);

void carregarReservas(Reserva reservas[], int *totalReservas);
void salvarReservas(Reserva reservas[], int totalReservas);

/* ================== PESSOA 2 - FILMES ================== */

void cadastrarFilme(Filme filmes[], int *totalFilmes);
void listarFilmes(Filme filmes[], int totalFilmes);
Filme* buscarFilmePorId(Filme filmes[], int totalFilmes, int id);

/* ================== PESSOA 3 - SALAS ================== */

void criarSala(Sala salas[], int *totalSalas);
void mostrarSala(Sessao *sessao);
Sala* buscarSalaPorId(Sala salas[], int totalSalas, int id);

/* ================== PESSOA 4 - SESSAO ================== */

void criarSessao(Sessao sessoes[], int *totalSessoes, Filme filmes[], Sala salas[]);
int  assentoDisponivel(Sessao *sessao, int linha, int coluna);
Sessao* buscarSessaoPorId(Sessao sessoes[], int totalSessoes, int id);

/* ================== PESSOA 5 - RESERVA + MENU ================== */

void reservarAssento(Sessao *sessao, Reserva reservas[], int *totalReservas,
                      int linha, int coluna, char nomeCliente[]);
void cancelarReserva(Sessao *sessao, Reserva reservas[], int *totalReservas, int idReserva);
void menuPrincipal(Filme filmes[], int *totalFilmes,
                    Sala salas[], int *totalSalas,
                    Sessao sessoes[], int *totalSessoes,
                    Reserva reservas[], int *totalReservas);

#endif
