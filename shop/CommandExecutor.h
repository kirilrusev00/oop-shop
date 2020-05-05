#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H
#include "Shop.h"

class CommandExecutor {
private:
	Shop shop = Shop::getInstance();
	
	CommandExecutor() { };

	void printMenuLogin();
	void printMenuShopForLoggedUsers();
	void printMenuShopForNotLoggedUsers();

	void executeCommandsInShopForLoggedUsers();
	void executeCommandsInShopForNotLoggedUsers();

public:
	static CommandExecutor& getInstance() {
		static CommandExecutor instance;
		return instance;
	}

	void executeCommandsForLogin();
	void executeCommandsInShop();
};

#endif