
#ifndef TRANSACTIONMANAGEMENT_USER_H
#define TRANSACTIONMANAGEMENT_USER_H

#include <string>
#include <iostream>
#include <fstream>

class User {

private:
    std::string nominative;
    std::string email;
    std::string telephoneNumber;

public:
    User(std::string nominative, std::string email, std::string telephoneNumber);

    const std::string &getNominative() const;

    const std::string &getEmail() const;

    const std::string &getTelephoneNumber() const;

    std::string toString();

    friend bool operator == (const User& leftUser, const User& rightUser) {
        return leftUser.nominative == rightUser.nominative &&
               leftUser.email == rightUser.email &&
               leftUser.telephoneNumber == rightUser.telephoneNumber;
    }

    friend std::ostream& operator << (std::ostream &out, const User& obj) {
        out << obj.nominative << "\n" << obj.email <<"\n"<< obj.telephoneNumber <<std::endl;
        return out;
    }

    friend std::istream& operator >> (std::istream &in, User &obj) {
        in >> obj.nominative;
        in >> obj.email;
        in >> obj.telephoneNumber;
        return in;
    }

    static bool writeToFileUser(std::ofstream &fileOutUser, const User& user);

    User readFromFileUser(std::ifstream &fileInUser);
};


#endif //TRANSACTIONMANAGEMENT_USER_H

