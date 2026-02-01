#include "Book.h"
#include <stdexcept>


Book::Book(int id, string book_name, string author_name, unsigned int publication_year,
    unsigned int copies) 
    : id(id),
      book_name(book_name), author_name(author_name),
      publication_year(publication_year), total_copies(copies),
      available_copies(copies)
{
    if (copies <= 0)
        std::logic_error("Book must have at least one copy");
}


bool Book::isAvailable() const {
    return available_copies > 0;
}

void Book::markAsLoaned() {
    if (!isAvailable())
        throw std::logic_error("Do not have copies");

    available_copies--;
}

void Book::marKAsReturned() {
    if (GetAvailablesCopies() >= total_copies)
        throw std::logic_error("This book is not cotaloged");
    available_copies++;
}


void Book::SetBookName(string book_name) {
    this->book_name = book_name;
}

void Book::SetAuthorName(string author_name) {
    this->author_name = author_name;
}

void Book::SetPublicationYear(unsigned int publication_year) {
    this->publication_year = publication_year;
}

void Book::SetTotalCopies(unsigned int copies) {
    this->total_copies = copies;
}

int Book::getId() const {
    return id;
}

string Book::GetBookName() {
    return this->book_name;
}

string Book::GetAuthorName() {
    return this->author_name;
}

 int Book::GetPublicationYear() {
    return this->publication_year;
}

 int Book::GetTotalCopies() {
    return this->total_copies;
}

int Book::GetAvailablesCopies() {
    return available_copies;
}
