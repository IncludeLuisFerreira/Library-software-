#ifndef LOAN_H
#define LOAN_H

#define MAX_LOANS 3

enum class LoanStatus {
    Active,
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
    Date loan_date;
    Date return_date;
    bool returned;
    LoanStatus status;

public:
    Loan(Book& book, User& user);
    
    bool UpdateReturnDate(Date new_return_date);
    
    Date GetReturnDate();
    
    bool isExpired();

    void finish();

    bool isActive() const;
    int getId() const;

private:
    Date GetDateNow();
};

#endif

