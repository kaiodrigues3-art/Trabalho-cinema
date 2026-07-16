#include <stdio.h>
#include <string.h>

#include "filmes.h"

void cadastrarFilme(Filme filmes[], int *totalFilmes)
{
    if (*totalFilmes >= 100)
    {
        printf("Limite de filmes atingido!\n");
        return;
    }

    Filme novo;

    printf("\n===== CADASTRAR FILME =====\n");

    printf("Titulo: ");
    scanf("%s[^\n]", novo.titulo);

    printf("Genero: ");
    scanf("%s[^\n]", novo.genero);

    printf("Duracao (minutos): ");
    scanf("%d", &novo.duracao);

    printf("Ano de lancamento: ");
    scanf("%d", &novo.ano);

    filmes[*totalFilmes] = novo;

    (*totalFilmes)++;

    printf("\nFilme cadastrado com sucesso!\n");
}


void listarFilmes(Filme filmes[], int totalFilmes)
{
    if (totalFilmes == 0)
    {
        printf("\nNenhum filme cadastrado.\n");
        return;
    }


    printf("\n===== FILMES CADASTRADOS =====\n");

    for(int i = 0; i < totalFilmes; i++)
    {
        printf("\nFilme %d\n", i + 1);
        printf("Titulo: %s\n", filmes[i].titulo);
        printf("Genero: %s\n", filmes[i].genero);
        printf("Duracao: %d minutos\n", filmes[i].duracao);
        printf("Ano: %d\n", filmes[i].ano);
    }
}


int buscarFilme(Filme filmes[], int totalFilmes, char titulo[])
{
    for(int i = 0; i < totalFilmes; i++)
    {
        if(strcmp(filmes[i].titulo, titulo) == 0)
        {
            return i;
        }
    }

    return -1;
}