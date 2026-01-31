#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;


class Book {

    public:
        int id;

        string book_name;
        string author_name;
        unsigned int publication_year;
        unsigned int total_copies;
        unsigned int available_copies;
        string isbn; 
        string gender;
        
        Book(string bookName, string authorName, unsigned int publicationYear, unsigned int availablaCopies);


        // SETTERS AND GETTERS

        void SetBookName(string book_name);
        void SetAuthorName(string author_name);
        void SetPublicationYear(unsigned int publication_year);
        void SetTotalCopies(unsigned int copies);
        void SetAvailablesCopies(unsigned int availables_copies);

        int getId() const;
        string GetBookName();
        string GetAuthorName();
        unsigned int GetPublicationYear();
        unsigned int GetTotalCopies();
        unsigned int GetAvailablesCopies();

        
        bool isAvailable() const;
        void markAsLoaned();
        void marKAsReturned();

    private:
        bool available;
};

#endif