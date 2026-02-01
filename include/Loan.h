#ifndef LOAN_H
#define LOAN_H

#include "User.h"
#include "Book.h"
#include <chrono>

#define MAX_LOANS 3

enum class LoanStatus {
    Active,
    Overdue,
    Finished
};

class Loan {
public:
    typedef struct sDate {
        int day;
        int month;
        int year;
    } Date;
  
private:
    int id;
    Book& book;
    User& user;
    std::chrono::system_clock::time_point loan_date;
    std::chrono::system_clock::time_point return_date;
    bool returned;
    
    LoanStatus status;

public:
    Loan(int id, Book& book, User& user);
    
    bool UpdateReturnDate();
    
    auto GetReturnDate();
    
    bool isOverdue();

    void finish();

    bool isActive() const;
    int getId() const;

    Book& getBook() const;
    User& getUser() const;

    void updateLoanStatus();
    void setStatus(LoanStatus loanStatus);

private:
    auto GetDateNow();
};

#endif

