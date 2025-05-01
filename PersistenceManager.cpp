#include "PersistenceManager.h"

PersistenceManager::PersistenceManager(UserManager &um,
                                       ClientManager &cm,
                                       AccountManager &am)
    : userMgr(um), clientMgr(cm), accountMgr(am) {}

void PersistenceManager::loadAll() {
    userMgr.loadFromFile();
    clientMgr.loadFromFile();
    accountMgr.loadFromFile();
}

void PersistenceManager::saveAll() {
    userMgr.saveToFile();
    clientMgr.saveToFile();
    accountMgr.saveToFile();
}

