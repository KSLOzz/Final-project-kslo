#include "Account.h"

Account::Account(int num, AccountType t, double b, Client* o)
    : accountNumber(num), accountType(t), balance(b), owner(o) {}

int Account::getNumber() const { return accountNumber; }
double Account::getBalance() const { return balance; }

bool Account::deposit(double amt) {
    if (amt <= 0) return false;
    balance += amt;
    return true;
}

bool Account::withdraw(double amt) {
    if (amt <= 0 || amt > balance) return false;
    balance -= amt;
    return true;
}

Client* Account::getOwner() const { return owner; }
AccountType Account::getType() const { return accountType; }

