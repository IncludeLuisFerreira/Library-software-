## Regras de Negocios


### Livro
- Um livro possui ID unico
- Um livro pode estar disponível ou emprestado
- Um livro não pode ter mais de um empréstimo ativo

### Usuário - Aluno
- Usuário possui ID único
- Usuário pode ter até 3 empréstimos ativos

### Empréstimo
- Um emprestimo liga um livro a um usuário
- Um emprestio pode estar ativo ou finalizado
- Um emprestimo só pode ser criado se:
    - O livro estiver disponível
    - O usuário nao exceder o limite
    - O usuário não estiver com livros atrasados