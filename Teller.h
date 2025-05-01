#ifndef TELLER_H
#define TELLER_H

#include <string>

enum class Role { ADMIN, STAFF };

class Teller {
public:
    Teller() = default;
    Teller(const std::string &user, const std::string &hash, Role r);

    const std::string& getUsername() const;
    const std::string& getPasswordHash() const;
    Role getRole() const;

    bool verifyPassword(const std::string &plain) const;
    bool changePassword(const std::string &newPwd);

    // Expose hash for bootstrap and additions
    static std::string simpleHash(const std::string &input);

private:
    std::string username;
    std::string passwordHash;
    Role role;
};

#endif // TELLER_H
