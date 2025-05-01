#include "AccountManager.h"
#include <fstream>

AccountManager::AccountManager(ClientManager &cm)
    : clientMgr(cm) {
    loadFromFile();
}

bool AccountManager::addAccount(const Account &a) {
    for (auto &x : accounts)
        if (x.getNumber() == a.getNumber())
            return false;
    accounts.push_back(a);
    return true;
}

Account* AccountManager::getAccount(int num) {
    for (auto &a : accounts)
        if (a.getNumber() == num)
            return &a;
    return nullptr;
}

void AccountManager::loadFromFile() {
    accounts.clear();
    std::ifstream in(accountFile);
    int num; std::string type; double bal; std::string owner;
    while (in >> num >> type >> bal >> owner) {
        Client* c = clientMgr.getClient(owner);
        if (!c) continue;
        AccountType at = (type == "CHECKING")
                         ? AccountType::CHECKING
                         : AccountType::SAVINGS;
        accounts.emplace_back(num, at, bal, c);
    }
}

void AccountManager::saveToFile() const {
    std::ofstream out(accountFile, std::ios::trunc);
    for (auto &a : accounts) {
        out << a.getNumber() << " "
            << (a.getType()==AccountType::CHECKING?"CHECKING":"SAVINGS")
            << " " << a.getBalance()
            << " " << a.getOwner()->getName()
            << "\n";
    }
}

