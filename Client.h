#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client() = default;
    Client(const std::string &n, const std::string &a,
           const std::string &s, const std::string &e, double i);

    const std::string& getName() const;
    void updateAddress(const std::string &a);
    void updateEmployer(const std::string &e);
    void updateIncome(double i);
    void display() const;

private:
    std::string name, address, ssn, employer;
    double income;
};

#endif // CLIENT_H

