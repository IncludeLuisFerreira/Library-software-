#include "User.h"
#include <stdexcept>

User::User(int id, const std::string& name)
    : id(id), name(name) {}

int User::getActiveLoans() const {
    return activeLoans;
}

void User::incrementLoans() {
    if (activeLoans >= 3) 
        throw std::logic_error("Usem loan limit reached");
    ++activeLoans;
}

void User::decrementLoans() {
    if (activeLoans == 0)
        throw std::logic_error("Invalid loan decrement");
    --activeLoans;
}

int User::getId() const {
    return id;
}

