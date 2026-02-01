#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;


class Book {

private:
        int id;
        int total_copies;
        int available_copies;
        string isbn; 

public:
        string book_name;
        string author_name;
        int publication_year;
        string gender;
        
        Book(int id, string bookName, string authorName, unsigned int publicationYear, unsigned int availablaCopies);


        // SETTERS AND GETTERS
        void SetBookName(string book_name);
        void SetAuthorName(string author_name);
        void SetPublicationYear(unsigned int publication_year);
        void SetTotalCopies(unsigned int copies);
        void SetAvailablesCopies(unsigned int availables_copies);

        int getId() const;
        string GetBookName();
        string GetAuthorName();
        int GetPublicationYear();
        int GetTotalCopies();
        int GetAvailablesCopies();

        
        bool isAvailable() const;
        void markAsLoaned();
        void marKAsReturned();

private:
        bool available;
};

#endif