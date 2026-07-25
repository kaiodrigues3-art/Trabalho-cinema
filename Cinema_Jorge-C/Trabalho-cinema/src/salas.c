#include <stdio.h>
#include "salas.h"

void criarSala(Sala salas[], int *totalSalas)
{   
    salas[*totalSalas].id = *totalSalas + 1;
    printf("Qual a quantidade de linhas?\n");
    scanf("%d", &salas[*totalSalas].linhas);
    printf("Qual a quantidade de colunas?\n");
    scanf("%d", &salas[*totalSalas].colunas);
    printf("Digite o nome da sala\n");
    scanf(" %49[^\n]", salas[*totalSalas].nome);
    (*totalSalas)++;
}

void listarSalas(Sala salas[], int totalSalas)
{
    for (int i = 0; i < totalSalas; i++) {
        printf("Sala %s, possui layout %d x %d e id %d\n", salas[i].nome, salas[i].linhas, salas[i].colunas, salas[i].id);
    }
}

Sala *buscarSalaPorId(Sala salas[], int totalSalas, int idsala){
    int pid = idsala;
    for (int i = 0; i < totalSalas; i++) {
        if (pid == salas[i].id){
            return &salas[i];
        }
    }
    return NULL;
}
