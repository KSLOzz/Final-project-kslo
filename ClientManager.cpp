#include "ClientManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>

ClientManager::ClientManager() {
    loadFromFile();
}

bool ClientManager::addClient(const Client &c) {
    for (auto &x : clients)
        if (x.getName() == c.getName())
            return false;
    clients.push_back(c);
    return true;
}

Client* ClientManager::getClient(const std::string &name) {
    for (auto &c : clients)
        if (c.getName() == name)
            return &c;
    return nullptr;
}

bool ClientManager::editClient(const std::string &name) {
    Client* c = getClient(name);
    if (!c) return false;

    std::cout << "Display " << name << "'s information:\n";
    c->display();

    int cf;
    std::cout << "1) Confirm\n2) Cancel\nPlease choose an option: ";
    std::cin >> cf;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (cf != 1) return false;

    std::string addr, emp;
    double inc;
    std::cout << "Address: "; std::getline(std::cin, addr);
    std::cout << "Employer: "; std::getline(std::cin, emp);
    std::cout << "Annual income: "; std::cin >> inc;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    c->updateAddress(addr);
    c->updateEmployer(emp);
    c->updateIncome(inc);
    return true;
}

void ClientManager::loadFromFile() {
    clients.clear();
    std::ifstream in(clientFile);
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream ss(line);
        std::string n,a,s,e; double i;
        if (std::getline(ss,n,'|') && std::getline(ss,a,'|') &&
            std::getline(ss,s,'|') && std::getline(ss,e,'|') &&
            (ss >> i)) {
            clients.emplace_back(n,a,s,e,i);
        }
    }
}

void ClientManager::saveToFile() const {
    std::ofstream out(clientFile, std::ios::trunc);
    for (auto &c : clients) {
        out << c.getName() << "|" 
            << /*address*/ "" << "|"
            << /*ssn*/     "" << "|"
            << /*employer*/"" << "|"
            << /*income*/  0.0 << "\n";
    }
}

