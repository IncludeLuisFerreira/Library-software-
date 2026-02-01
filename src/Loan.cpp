#include "Loan.h"
#include "Book.h"
#include "User.h"
#include <stdexcept>
#include <chrono>
#include <ctime>

Loan::Loan(int id, Book& book, User& user)
    : id(id), book(book), user(user), status(LoanStatus::Active)
{
    if (!book.isAvailable())
        std::logic_error("Book already loaned");
    
    if (user.getActiveLoans() >= MAX_LOANS)
        std::logic_error("User have already 3 loand");

    book.markAsLoaned();    // teria que diminur a quantidae de copias
    user.incrementLoans();  // Seria legal a tela do usuario sabendo quais sao os livros

    return_date = chrono::system_clock::now()  + chrono::hours(24 * 7);
    status = LoanStatus::Active;
}

void Loan::finish() {
    if (status != LoanStatus::Active)
        // throw exception

    book.marKAsReturned();
    user.decrementLoans();
    status = LoanStatus::Finished;
}

auto Loan::GetDateNow() {
    return chrono::system_clock::now();
}

bool Loan::isActive() const {
    return status == LoanStatus::Active;
}


int Loan::getId() const {
    return id;
}

auto Loan::GetReturnDate() {
    return return_date;
}

Book& Loan::getBook() const {
    return book;
}

User& Loan::getUser() const {
    return user;
}

bool Loan::UpdateReturnDate() {
    if (isOverdue())
        return false;
    
    return_date = chrono::system_clock::now()  + chrono::hours(24 * 7);  
    return true;
}

bool Loan::isOverdue() {
    return status == LoanStatus::Overdue;
}


void Loan::updateLoanStatus() {
    auto now = chrono::system_clock::now();
    if (now > return_date)
        status == LoanStatus::Overdue;
}

void Loan::setStatus(LoanStatus loanStatus) {
    status = loanStatus;
}


