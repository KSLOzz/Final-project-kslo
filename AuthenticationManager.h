#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include "Teller.h"
#include "UserManager.h"

class AuthenticationManager {
public:
    AuthenticationManager(UserManager &um);
    Teller* authenticate();

private:
    UserManager &userMgr;
};

#endif // AUTHENTICATIONMANAGER_H

