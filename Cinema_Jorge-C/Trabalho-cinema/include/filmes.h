#ifndef FILMES_H
#define FILMES_H

typedef struct
{
    char titulo[100];
    char genero[50];
    int duracao;
    int ano;

} Filme;


void cadastrarFilme(Filme filmes[], int *totalFilmes);

void listarFilmes(Filme filmes[], int totalFilmes);

int buscarFilme(Filme filmes[], int totalFilmes, char titulo[]);


#endif