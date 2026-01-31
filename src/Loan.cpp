#include "Loan.h"
#include "Book.h"
#include "User.h"
#include <stdexcept>
#include <ctime>

Loan::Loan(Book& book, User& user)
    : book(book), user(user), status(LoanStatus::Active)
{
    if (!book.isAvailable())
        std::logic_error("Book already loaned");
    
    if (user.getActiveLoans() >= MAX_LOANS)
        std::logic_error("User have already 3 loand");

    book.markAsLoaned();    // teria que diminur a quantidae de copias
    user.incrementLoans();  // Seria legal a tela do usuario sabendo quais sao os livros
    status = LoanStatus::Active;
}

void Loan::finish() {
    if (status != LoanStatus::Active)
        // throw exception

    book.marKAsReturned();
    status = LoanStatus::Finished;
}

Loan::Date Loan::GetDateNow() {
    time_t now = time(nullptr);
    tm *local = localtime(&now);
    
    int day = local->tm_mday;
    int month = local->tm_mon + 1;
    int year = local->tm_year + 1900;

    Date date = {
        .day = day,
        .month = month,
        .year = year
    };

    return date;
}

bool Loan::isActive() const {
    return status == LoanStatus::Active;
}

int Loan::getId() const {
    return id;
}

Loan::Date Loan::GetReturnDate() {
    return return_date;
}

bool Loan::UpdateReturnDate(Date new_return_Date) {
    if (isExpired())
        return false;
    
    return_date = new_return_Date;
    return true;
}

bool Loan::isExpired() {
    Date date = GetDateNow();
    
    return date.day > return_date.day && date.month > return_date.month;
}

