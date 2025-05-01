#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "Teller.h"
#include <vector>
#include <string>

class UserManager {
public:
    UserManager();
    bool addUser(const Teller &t);
    bool removeUser(const std::string &username);
    std::vector<Teller>& listUsers();
    void loadFromFile();
    void saveToFile() const;

private:
    std::vector<Teller> staffList;
    const std::string staffFile = "staff";
};

#endif // USERMANAGER_H

