#ifndef USER_H
#define USER_H

#include <string>

class User {
    private:
        int id;
        std::string name;
        int activeLoans = 0;

        bool canLoan;

    public:
        // CONSTRUCTORS
        User(int id, const std::string& name);
        
        void incrementLoans();
        void decrementLoans();
        
        void setCanLoan(bool state);
        bool userCanLoan();
        
        // GETTERS
        int getActiveLoans() const;
        int getId() const;

};

#endif