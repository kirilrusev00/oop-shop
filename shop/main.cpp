#include <iostream>
#include <iomanip>
#include "CommandExecutor.h"

int main()
{
	CommandExecutor commandExecutor = CommandExecutor::getInstance();
	commandExecutor.executeCommandsForLogin();
	commandExecutor.executeCommandsInShop();

	system("pause");
	return 0;
}
