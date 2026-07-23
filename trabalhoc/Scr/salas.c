typedef struct {
    int  id;
    char nome[30];
    int  linhas;
    int  colunas;
    char layout[MAX_LINHAS][MAX_COLUNAS]; /* 'O' = assento, 'X' = vao */
} Sala;