#include "AuthenticationManager.h"
#include <iostream>

AuthenticationManager::AuthenticationManager(UserManager &um)
    : userMgr(um) {}

Teller* AuthenticationManager::authenticate() {
    std::string user, pwd;
    std::cout << "User Name: "; std::getline(std::cin, user);
    std::cout << "Password: ";  std::getline(std::cin, pwd);
    for (auto &t : userMgr.listUsers()) {
        if (t.getUsername() == user && t.verifyPassword(pwd))
            return &t;
    }
    return nullptr;
}

