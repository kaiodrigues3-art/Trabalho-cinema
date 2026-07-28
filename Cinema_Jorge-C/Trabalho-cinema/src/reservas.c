#include <stdio.h>
#include <string.h>
#include "reservas.h"
#include "filmes.h"
#include "cinema.h"

/* funcao da Pessoa 4 - so declarada aqui pra poder usar */
extern int assentoDisponivel(Sessao *sessao, int linha, int coluna);

void reservarAssento(Sessao *sessao, Reserva reservas[], int *totalReservas, int linha, int coluna, char nome[]) {
    if (!assentoDisponivel(sessao, linha, coluna)) {
        printf("Assento ocupado!\n");
        return;
    }

    sessao->assentos[linha][coluna] = 'X';

    Reserva r;
    r.id = *totalReservas + 1;
    r.idSessao = sessao->id;
    r.linha = linha;
    r.coluna = coluna;
    strcpy(r.nomeCliente, nome);

    reservas[*totalReservas] = r;
    (*totalReservas)++;

    printf("Reserva feita com sucesso! (id %d)\n", r.id);
}

void cancelarReserva(Sessao *sessao, Reserva reservas[], int *totalReservas, int idReserva) {
    int i, pos = -1;

    for (i = 0; i < *totalReservas; i++) {
        if (reservas[i].id == idReserva && reservas[i].idSessao == sessao->id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Reserva nao encontrada!\n");
        return;
    }

    sessao->assentos[reservas[pos].linha][reservas[pos].coluna] = 'O';

    for (i = pos; i < *totalReservas - 1; i++)
        reservas[i] = reservas[i + 1];
    (*totalReservas)--;

    printf("Reserva cancelada!\n");
}

void menuPrincipal(Filme filmes[], int *totalFilmes, Sala salas[], int *totalSalas,
                    Sessao sessoes[], int *totalSessoes, Reserva reservas[], int *totalReservas) {
    int opc;

    do {
        printf("\n===== SISTEMA DE RESERVA DE CINEMA =====\n");
        printf("1 - Cadastrar filme\n");
        printf("2 - Listar filmes\n");
        printf("3 - Criar sala\n");
        printf("4 - Criar sessao\n");
        printf("5 - Mostrar mapa de uma sessao\n");
        printf("6 - Reservar assento\n");
        printf("7 - Cancelar reserva\n");
        printf("8 - Salvar e sair\n");
        printf("Opcao: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                cadastrarFilme(filmes, totalFilmes);
                break;

            case 2:
                listarFilmes(filmes, *totalFilmes);
                break;

            case 3:
                criarSala(salas, totalSalas);
                break;

            case 4:
                criarSessao(sessoes, totalSessoes, filmes, salas);
                break;

            case 5: {
                int idS;
                printf("ID da sessao: ");
                scanf("%d", &idS);
                Sessao *s = buscarSessaoPorId(sessoes, *totalSessoes, idS);
                if (s) mostrarSala(s);
                else printf("Sessao nao encontrada!\n");
                break;
            }

            case 6: {
                int idS, l, c;
                char nome[50];
                printf("ID da sessao: ");
                scanf("%d", &idS);
                Sessao *s = buscarSessaoPorId(sessoes, *totalSessoes, idS);
                if (!s) { printf("Sessao nao encontrada!\n"); break; }

                printf("Linha: ");
                scanf("%d", &l);
                printf("Coluna: ");
                scanf("%d", &c);
                printf("Nome do cliente: ");
                scanf(" %[^\n]", nome);

                reservarAssento(s, reservas, totalReservas, l, c, nome);
                break;
            }

            case 7: {
                int idS, idR;
                printf("ID da sessao: ");
                scanf("%d", &idS);
                Sessao *s = buscarSessaoPorId(sessoes, *totalSessoes, idS);
                if (!s) { printf("Sessao nao encontrada!\n"); break; }

                printf("ID da reserva: ");
                scanf("%d", &idR);
                cancelarReserva(s, reservas, totalReservas, idR);
                break;
            }

            case 8:
                salvarReservas(reservas, *totalReservas);
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opc != 8);
}
