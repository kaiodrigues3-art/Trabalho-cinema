#ifndef RESERVAS_H
#define RESERVAS_H

#include "structs.h"

void reservarAssento(Sessao *sessao, Reserva reservas[], int *totalReservas, int linha, int coluna, char nome[]);
void cancelarReserva(Sessao *sessao, Reserva reservas[], int *totalReservas, int idReserva);
void menuPrincipal(Filme filmes[], int *totalFilmes, Sala salas[], int *totalSalas,
                    Sessao sessoes[], int *totalSessoes, Reserva reservas[], int *totalReservas);

#endif
