#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Client.h"

enum class AccountType { CHECKING, SAVINGS };

class Account {
public:
    Account() = default;
    Account(int num, AccountType t, double b, Client* o);

    int getNumber() const;
    double getBalance() const;
    bool deposit(double amt);
    bool withdraw(double amt);
    Client* getOwner() const;
    AccountType getType() const;

private:
    int accountNumber;
    AccountType accountType;
    double balance;
    Client* owner;
};

#endif // ACCOUNT_H

