## Detalhes do desenvolvimento do objeto User - v0.2

<b> Essa é uma das primeiras versões do objeto, este que certamente enfretará mudanças coforme a perpectiva do projeto aumenta </b>


- User é um objeto que representa todo leitor da biblioteca
- Apresenta apenas atributos básicos de identificação
- Tem limite de 3 empréstimos ao mesmo tempo
- O User não pode fazer mais nenhum empréstimo caso esteja com a entrega atrasada de algum livro

```C
class User {
private:
    int id;
    std::string name;
    int activeLoans = 0;

    bool canLoan;

public:
    // CONSTRUCTORS
    User(int id, const std::string& name);
    
    void incrementLoans();
    void decrementLoans();
    
    void setCanLoan(bool state);
    bool userCanLoan();
    
    // GETTERS
    int getActiveLoans() const;
    int getId() const;
};

```

