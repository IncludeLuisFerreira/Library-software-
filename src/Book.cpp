#include "Book.h"
#include <stdexcept>


Book::Book(string book_name, string author_name, unsigned int publication_year,
    unsigned int copies) : available(true) 
{
    this->book_name = book_name;
    this->author_name = author_name;
    this->publication_year = publication_year;
    this->total_copies = copies;
}

bool Book::isAvailable() const {
    return available == true;
}

void Book::markAsLoaned() {
    if (!isAvailable())
        throw std::logic_error("Invalid book state");

    available = false;
    available_copies--;
}

void Book::marKAsReturned() {
    if (isAvailable())
        throw std::logic_error("Invalid book state");

    available = true;
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

unsigned int Book::GetPublicationYear() {
    return this->publication_year;
}

unsigned int Book::GetTotalCopies() {
    return this->total_copies;
}
