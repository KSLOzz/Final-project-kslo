#ifndef PERSISTENCEMANAGER_H
#define PERSISTENCEMANAGER_H

#include "UserManager.h"
#include "ClientManager.h"
#include "AccountManager.h"

class PersistenceManager {
public:
    PersistenceManager(UserManager &um,
                       ClientManager &cm,
                       AccountManager &am);
    void loadAll();
    void saveAll();

private:
    UserManager &userMgr;
    ClientManager &clientMgr;
    AccountManager &accountMgr;
};

#endif // PERSISTENCEMANAGER_H

