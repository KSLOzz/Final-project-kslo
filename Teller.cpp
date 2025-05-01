#include "Teller.h"
#include <functional>
#include <sstream>

Teller::Teller(const std::string &user, const std::string &hash, Role r)
    : username(user), passwordHash(hash), role(r) {}

const std::string& Teller::getUsername() const { return username; }
const std::string& Teller::getPasswordHash() const { return passwordHash; }
Role Teller::getRole() const { return role; }

bool Teller::verifyPassword(const std::string &plain) const {
    return simpleHash(plain) == passwordHash;
}

bool Teller::changePassword(const std::string &newPwd) {
    if (newPwd.empty() || simpleHash(newPwd) == passwordHash) return false;
    passwordHash = simpleHash(newPwd);
    return true;
}

std::string Teller::simpleHash(const std::string &input) {
    auto h = std::hash<std::string>{}(input);
    std::stringstream ss;
    ss << std::hex << h;
    return ss.str();
}

