#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "Account.h"
#include "ClientManager.h"
#include <vector>

class AccountManager {
public:
    AccountManager(ClientManager &cm);
    bool addAccount(const Account &a);
    Account* getAccount(int num);
    void loadFromFile();
    void saveToFile() const;

private:
    std::vector<Account> accounts;
    ClientManager &clientMgr;
    const std::string accountFile = "account-info";
};

#endif // ACCOUNTMANAGER_H

