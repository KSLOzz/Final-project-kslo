#include "TellerTerminal.h"
#include <iostream>
#include <limits>

// Utility pause
void pauseEnter() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Safe int input
int getInt(const std::string &prompt, int minV, int maxV) {
    int x;
    while (true) {
        std::cout << prompt;
        if (std::cin >> x && x >= minV && x <= maxV) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
        std::cout << "Invalid. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

TellerTerminal::TellerTerminal()
  : userMgr(), clientMgr(), accountMgr(clientMgr),
    authMgr(userMgr), persistMgr(userMgr, clientMgr, accountMgr),
    currentUser(nullptr), currentState(State::IDLE)
{
    persistMgr.loadAll();
}

void TellerTerminal::run() {
    while (true) {
        if (currentState == State::IDLE) loginFlow();
        else if (currentUser->getRole() == Role::ADMIN) adminMenu();
        else staffMenu();
    }
}

void TellerTerminal::banner(const std::string &title) {
    std::cout << "===========================================================\n"
              << "| " << title << "\n"
              << "===========================================================\n";
}

void TellerTerminal::loginFlow() {
    banner("Login to Access the Teller Terminal System");
    currentUser = authMgr.authenticate();
    if (!currentUser) {
        std::cout << "Invalid credentials. Try again!\n";
    } else {
        currentState = State::ACTIVE;
    }
}

void TellerTerminal::adminMenu() {
    banner("Teller Terminal System – System Administration");
    std::cout << "1) Client and Account Management\n"
                 "2) Add a branch staff member\n"
                 "3) Delete a branch staff member\n"
                 "4) Display branch staff\n"
                 "5) Change password\n"
                 "6) Exit\n";
    int c = getInt("Please choose an option: ", 1, 6);
    switch (c) {
      case 1: clientAccountMenu(); break;
      case 2: addStaff();           break;
      case 3: deleteStaff();        break;
      case 4: displayStaff();       break;
      case 5: changePassword();     break;
      case 6: persistMgr.saveAll(); exit(0);
    }
}

void TellerTerminal::staffMenu() {
    banner("Teller Terminal System – Branch Staff");
    std::cout << "1) Client and Account Management\n"
                 "2) Change password\n"
                 "3) Exit\n";
    int c = getInt("Please choose an option: ", 1, 3);
    if (c == 1) clientAccountMenu();
    else if (c == 2) changePassword();
    else { persistMgr.saveAll(); exit(0); }
}

void TellerTerminal::changePassword() {
    std::string np;
    std::cout << "New Password: "; std::getline(std::cin, np);
    if (!currentUser->changePassword(np))
        std::cout << "Error- new password must differ. \n";
    else
        std::cout << "Password changed!\n";
    pauseEnter();
}

void TellerTerminal::addStaff() {
    std::string u,p; int r, cf;
    std::cout << "User Name: ";    std::getline(std::cin,u);
    std::cout << "Password: ";     std::getline(std::cin,p);
    r  = getInt("Role (1=Admin;2=Staff): ",1,2);
    cf = getInt("1) Confirm\n2) Cancel\nChoose: ",1,2);
    if (cf != 1) return;
    Role rl = (r==1?Role::ADMIN:Role::STAFF);
    userMgr.addUser(Teller(u,Teller::simpleHash(p),rl));
    std::cout << "Added " << u << ".\n";
    pauseEnter();
}

void TellerTerminal::deleteStaff() {
    std::string u; int cf;
    std::cout <<"Username to delete: "; std::getline(std::cin,u);
    cf = getInt("1) Confirm\n2) Cancel\nChoose: ",1,2);
    if (cf != 1) return;
    if (!userMgr.removeUser(u))
        std::cout << "Not found.\n";
    else
        std::cout << "Deleted " << u << ".\n";
    pauseEnter();
}

void TellerTerminal::displayStaff() {
    auto &v = userMgr.listUsers();
    std::cout << v.size() << " users:\n";
    for (auto &t : v)
        std::cout << " - " << t.getUsername()
                  << " [" << (t.getRole()==Role::ADMIN?"Admin":"Staff") << "]\n";
    pauseEnter();
}

void TellerTerminal::clientAccountMenu() {
    banner("Client & Account Management");
    std::cout << "(stub for client/account flows)\n";
    pauseEnter();
}

