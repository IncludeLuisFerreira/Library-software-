#include <iostream>
#include "Library.h"
#include "Book.h"
#include "User.h"

int main() {
    try {
        // Cria biblioteca
        Library library("Biblioteca Central", "Rua Principal, 123");

        // Cria livros
        Book book1(1, "Clean Code", "Robert C. Martin", 2000, 100);
        Book book2(2, "The C++ Programming Language", "Bjarne Stroustrup", 1989, 10);

        // Adiciona livros
        library.addBook(book1);
        library.addBook(book2);

        // Cria usuários
        User user1(1, "Alice");
        User user2(2, "Bob");

        // Adiciona usuários
        library.addUser(user1);
        library.addUser(user2);

        // Cria empréstimos
        library.createLoan(1, 1); // Alice pega Clean Code
        library.createLoan(2, 2); // Bob pega C++

        // Lista estado da biblioteca
        std::cout << library.toString() << std::endl;

        // Finaliza um empréstimo
        library.finishLoan(1);

        std::cout << "\nApós finalizar empréstimo:\n";
        std::cout << library.toString() << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cerr << "Erro de lógica: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Erro de busca: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Erro desconhecido" << std::endl;
    }

    return 0;
}
