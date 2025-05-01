#include "Client.h"
#include <iostream>

Client::Client(const std::string &n, const std::string &a,
               const std::string &s, const std::string &e, double i)
    : name(n), address(a), ssn(s), employer(e), income(i) {}

const std::string& Client::getName() const { return name; }
void Client::updateAddress(const std::string &a) { address = a; }
void Client::updateEmployer(const std::string &e) { employer = e; }
void Client::updateIncome(double i) { income = i; }

void Client::display() const {
    std::cout << "Address: " << address << "\n"
              << "Social security number: " << ssn << "\n"
              << "Employer: " << employer << "\n"
              << "Annual income: " << income << "\n";
}

