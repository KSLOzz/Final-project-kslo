#include "UserManager.h"
#include <fstream>

UserManager::UserManager() {
    loadFromFile();
}

bool UserManager::addUser(const Teller &t) {
    for (auto &u : staffList)
        if (u.getUsername() == t.getUsername())
            return false;
    staffList.push_back(t);
    saveToFile();
    return true;
}

bool UserManager::removeUser(const std::string &username) {
    for (auto it = staffList.begin(); it != staffList.end(); ++it) {
        if (it->getUsername() == username) {
            staffList.erase(it);
            saveToFile();
            return true;
        }
    }
    return false;
}

std::vector<Teller>& UserManager::listUsers() {
    return staffList;
}

void UserManager::loadFromFile() {
    staffList.clear();
    std::ifstream in(staffFile);
    if (in) {
        std::string user, hash, roleStr;
        while (in >> user >> hash >> roleStr) {
            Role r = (roleStr == "ADMIN") ? Role::ADMIN : Role::STAFF;
            staffList.emplace_back(user, hash, r);
        }
    }
    // Bootstrap default admin
    if (staffList.empty()) {
        std::string defaultHash = Teller::simpleHash("0000");
        staffList.emplace_back("admin", defaultHash, Role::ADMIN);
        saveToFile();
    }
}

void UserManager::saveToFile() const {
    std::ofstream out(staffFile, std::ios::trunc);
    for (auto &t : staffList) {
        out << t.getUsername() << " "
            << t.getPasswordHash() << " "
            << (t.getRole() == Role::ADMIN ? "ADMIN" : "STAFF")
            << "\n";
    }
}

