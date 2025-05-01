#ifndef TELLERTERMINAL_H
#define TELLERTERMINAL_H

#include "AuthenticationManager.h"
#include "ClientManager.h"
#include "AccountManager.h"
#include "PersistenceManager.h"

class TellerTerminal {
public:
    TellerTerminal();
    void run();

private:
    enum class State { IDLE, ACTIVE } currentState;
    UserManager userMgr;
    ClientManager clientMgr;
    AccountManager accountMgr;
    AuthenticationManager authMgr;
    PersistenceManager persistMgr;
    Teller* currentUser;

    void loginFlow();
    void adminMenu();
    void staffMenu();
    void clientAccountMenu();
    void changePassword();
    void addStaff();
    void deleteStaff();
    void displayStaff();
    void doAddClient();
    void doAddAccount();
    void doEditClient();
    void doManageAccount();
    void banner(const std::string &title);
};

#endif // TELLERTERMINAL_H

