#ifndef SALAS_H
#define SALAS_H

#include "cinema.h"

void criarSala(Sala salas[], int *totalSalas);

void listarSalas(Sala salas[], int totalSalas);

Sala *buscarSalaPorId(
    Sala salas[],
    int totalSalas,
    int id
);

#endif