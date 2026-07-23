# Trabalho Cinema

Sistema de reserva de cinema desenvolvido em C, como trabalho em grupo.

## Estrutura do projeto

```
Trabalho-cinema/
├── include/          # Headers (.h)
│   ├── cinema.h
│   ├── filmes.h
│   └── structs.h
├── src/              # Código-fonte (.c)
│   ├── main.c
│   ├── filmes.c
│   ├── persistencia.c
│   ├── reservas.c
│   ├── salas.c
│   └── secoes.c
├── .gitignore
└── README.md
```

## Funcionalidades

- Cadastro e listagem de filmes
- Gerenciamento de salas
- Gerenciamento de sessões
- Reservas de ingressos
- Persistência dos dados

## Como compilar

Com o GCC instalado, na raiz do projeto:

```bash
gcc -Iinclude src/*.c -o cinema
```

O parâmetro `-Iinclude` diz ao compilador para procurar os arquivos `.h` dentro da pasta `include/`.

## Como executar

```bash
./cinema
```

## Requisitos

- GCC (ou outro compilador C compatível)
- Sistema Linux, macOS ou Windows (com MinGW/WSL)

## Autores

- Trabalho em grupo — 5 integrantes
