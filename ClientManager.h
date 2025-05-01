#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "Client.h"
#include <vector>
#include <string>

class ClientManager {
public:
    ClientManager();
    bool addClient(const Client &c);
    Client* getClient(const std::string &name);
    bool editClient(const std::string &name);
    void loadFromFile();
    void saveToFile() const;

private:
    std::vector<Client> clients;
    const std::string clientFile = "client-info";
};

#endif // CLIENTMANAGER_H

