#include "Library.h"
#include <sstream>
using namespace std;


Library::Library(string name, string address) {
    this->name = name;
    this->address = address;
}

Library::Library(string name, string address, vector<Book> books) {
    this->name = name;
    this->address = address;
    this->books = books;
}

Library::Library(string name, string address, vector<Book> books, vector<User> users) {
    this->name = name;
    this->address = address;
    this->books = books;
    this->users = users;
}

void Library::addBook(const Book& book) {
    for (const auto& b : books) {
        if (b.getId() == book.getId()){
            throw std::logic_error("Book ID already exists");
        }
    }
    books.push_back(book);
}


void Library::RemoveBook(int id_book) {
    for (unsigned int i = 0; i < this->books.size(); i++) {
        if (this->books[i].getId() == id_book) {
            this->books.erase(this->books.begin() + i);
        }
    }

}

void Library::addUser(const User& user) {
    for (const auto& u : users) {
        if (user.getId() == u.getId()) {
            throw std::logic_error("User ID already exists");
        }
    }
    users.push_back(user);
}

void Library::createLoan(int bookId, int userId) {
    Book& book = findBook(bookId);
    User& user = findUser(userId);

    if (user.getActiveLoans() >= 3 || !user.userCanLoan())
        std::logic_error("User can no make another Loan");

    user.incrementLoans();
    book.markAsLoaned();
    loans.emplace_back(nextLoanId++,book, user);
}

void Library::rectifyOverdueLoan(int loanId) {
    Loan& overdueLoan = findLoan(loanId);
    
    if (!overdueLoan.isOverdue())
        throw std::logic_error("Loan is not Overdue");

    User& user = overdueLoan.getUser();
    user.setCanLoan(true);
    // Talves uma 'punicao' pelo atraso 
    overdueLoan.setStatus(LoanStatus::Active);
    overdueLoan.finish();
}

void Library::finishLoan(int loanId) {
    Loan& loan = findLoan(loanId);
    Book& book = loan.getBook();
    User& user = loan.getUser();

    book.marKAsReturned();
    user.decrementLoans();
    loan.finish();
}

string Library::ListAllBooks() {
    stringstream ss;
    
    if (!books.empty()) {
        
        for (Book book : books) {
            ss << "- " << book.book_name << " (" << book.author_name << ")" << endl;        
        }
    }
    else {
        ss << "There are no books!" << endl;
    }

    return ss.str();
}


string Library::toString() {
    std::stringstream ss;
    ss << "=== BIBLIOTECA ===" << endl;
    ss << "Nome: " << this->name << endl;
    ss << "Endereco: " << this->address << endl;
    ss << "Quantidade de livros: " << this->books.size() << endl;
    ss << "Quantidade de usuarios: " << this->users.size() << endl;
    ss << "Quantidade de emprestimos: " << this->loans.size() << endl;
    
    if (!this->books.empty()) {
        ss << "\n--- LIVROS ---" << endl;
        for (const Book& book : this->books) {
            ss << "- " << book.book_name << " (" << book.author_name << ")" << endl;
        }
    }
    
    return ss.str();
}

Book& Library::findBook(int bookId) {
    for (auto& b : books) {
        if (b.getId() == bookId)
            return b;
    }

    throw std::out_of_range("Book not found");
}

User& Library::findUser(int userId) {
    for (auto& u : users) {
        if (u.getId() == userId)
            return u;
    }
    throw std::out_of_range("User not found");
}

Loan& Library::findLoan(int loanId) {
    for (auto& l : loans) {
        if (l.getId() == loanId)
            return l;
    }
    throw std::out_of_range("Loan not found");
}
