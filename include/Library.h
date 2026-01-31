#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Loan.h"
#include "User.h"
#include <vector>
#include <string>

using namespace std;

class Library {

private:
    string name;
    string address;
    vector<Book> books;
    vector<User> users;
    vector<Loan> loans;
    
public:

/*********************************** CONSTRUCTORS ***********************************/

   Library(string name, string address);
   
   Library(string name, string address, vector<Book> books);
   
   Library(string name, string address, vector<Book> books, vector<User> users);

   Library(string name, string address, vector<Book> books, vector<User> users, vector<Loan> loans);

/************************************************************************************/

 /*********************************** BOOK MANAGER ***********************************/
   
    /// @brief Add a new book to vectir
    /// @param book 
    /// @return True if sucessed or false if has ocurred an error
    void addBook(Book&book);

    /// @brief Remove a book from the vector
    /// @param id_book id of the book
    /// @return True if sucessed or false if has ocurred an error
    void RemoveBook(int id_book);

    /// @brief Remove a book from vector
    /// @param book 
    /// @return True if sucessed or false if has ocurred an error
    void RemoveBook(Book book);

    void addUser(const User& user);
    
    void createLoan(int bookId, int userId);
    void finishLoan(int loanId);
   
    string ListAllBooks();
    
    string toString();

private:
    Book& findBook(int bookId);
    User& findUser(int userId);
    Loan& findLoan(int loanId);

};


#endif