CXX := g++
CXXFLAGS := -std=c++17 -O0 -g -Wall -Wextra

SRC := \
  Teller.cpp \
  UserManager.cpp \
  AuthenticationManager.cpp \
  Client.cpp \
  ClientManager.cpp \
  Account.cpp \
  AccountManager.cpp \
  PersistenceManager.cpp \
  TellerTerminal.cpp \
  main.cpp

OBJ := $(SRC:.cpp=.o)

all: teller

teller: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o teller

.PHONY: all clean

