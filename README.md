# Sistema de Gerenciamento de Biblioteca

Sistema de gerenciamento de biblioteca desenvolvido em C++ para controle de livros, usuários e empréstimos.

## Funcionalidades

- Cadastro e gerenciamento de livros
- Cadastro e gerenciamento de usuários
- Sistema de empréstimos e devoluções
- Controle de disponibilidade de livros
- Validação de regras de negócio para empréstimos

## Estrutura do Projeto

```
Biblioteca/
├── src/                    # Código fonte
│   ├── main.cpp           # Ponto de entrada da aplicação
│   ├── Library.cpp        # Implementação da classe Library
│   ├── Book.cpp           # Implementação da classe Book
│   ├── User.cpp           # Implementação da classe User
│   └── Loan.cpp           # Implementação da classe Loan
├── include/               # Arquivos de cabeçalho
│   ├── Library.h          # Definição da classe Library
│   ├── Book.h             # Definição da classe Book
│   ├── User.h             # Definição da classe User
│   └── Loan.h             # Definição da classe Loan
├── docs/                  # Documentação
└── Makefile              # Configuração de build
```

## Regras de Negócio

### Livros
- Cada livro possui ID único
- Controle de disponibilidade (disponível/emprestado)
- Não permite múltiplos empréstimos simultâneos do mesmo exemplar

### Usuários
- ID único por usuário
- Limite de 3 empréstimos ativos por usuário
- Bloqueio para usuários com livros em atraso

### Empréstimos
- Vincula livro a usuário
- Estados: ativo ou finalizado
- Validações automáticas antes da criação

## Requisitos

- Compilador C++ com suporte ao padrão C++17
- Make (para build automatizado)

## Compilação

### Build de Release
```bash
make
```

### Build de Debug
```bash
make MODE=debug
```

### Limpeza
```bash
make clean
```

## Execução

```bash
./bin/biblioteca
```

## Classes Principais

### Library
Classe principal que gerencia todo o sistema, incluindo coleções de livros, usuários e empréstimos.

### Book
Representa um livro com informações como título, autor, ano de publicação e controle de disponibilidade.

### User
Representa um usuário do sistema com controle de empréstimos ativos e permissões.

### Loan
Gerencia os empréstimos, incluindo datas e status.

## Licença

Este projeto é desenvolvido para fins educacionais.
