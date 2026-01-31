#ifndef USER_H
#define USER_H

#include <string>

class User {
    private:
        int id;
        std::string name;
        int activeLoans = 0;

    public:
        User(int id, const std::string& name);
        
        int getActiveLoans() const;
        void incrementLoans();
        void decrementLoans();
        

        int getId() const;
};

#endif