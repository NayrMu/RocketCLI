#include "commandcontroller.h"
/*
* Implementation for handling Command Line Interface
*/

// Constructor
CmdControl::CmdControl() {
	currentCommand = NUL;

	rocketRunTime = new RocketEngine(); // Create an instance of the rocket simulation

	std::cout << ":: COMMAND LINE NOMINAL" << std::endl; // Print to screen to let user know we're online

	while (true) {
		this->cmdPrompt();
	}
}
// Destructor
CmdControl::~CmdControl() {
	delete rocketRunTime;
}

// Prompts the user for input
void CmdControl::cmdPrompt() {
	const int maxInputLength = 1024;
	char userInput[maxInputLength];
	std::cout << "<: "; // Indicates input from user
	std::cin.getline(userInput, maxInputLength); // Get input from user as stringn with max length of 1024

	this->parseCommand(userInput); // calls parseInput from current instance of cmdcontrol on the users input
}

// Parses the initial user input
Commands CmdControl::parseCommand(std::string userInput) {

	std::vector<std::string> cmdVector = splitString(userInput, ' '); // Split input at spaces
	std::string cmdString = cmdVector[0]; // First item of user input is the command
	cmdVector.erase(cmdVector.begin()); // Remove first item to pass the rest of string down the line

	if (cmdString == "view") { // Create view instance and pass rest of user input into it for parsing
		currentCommand = VIEW;
		View* viewCmd = new View(rocketRunTime, cmdVector);
		delete viewCmd;
	}
	else if (cmdString == "start") { // Create routine instance and pass rest of user input into it for parsing
		currentCommand = START;
		Routine* startCmd = new Routine(rocketRunTime, cmdVector);
		delete startCmd;
	}
	else { // Command not found
		std::cout << "!: IMPROPER COMMAND :!" << std::endl; 
	}

	return currentCommand;
}

// Universal method for splitting a string at a specified delimiter
std::vector<std::string> CmdControl::splitString(std::string str, char delim) {
	std::vector<std::string> returnVector;
	std::size_t startIdx = 0, endIdx = 0;
	for (int i = 0; i <= str.size(); i++) {

		if (str[i] == delim || i == str.size()) {
			endIdx = i;
			std::string temp;
			if (endIdx >= startIdx) {
				temp.append(str, startIdx, endIdx - startIdx);
			}
			returnVector.push_back(temp);
			startIdx = endIdx + 1;
		}
	}

	return returnVector;
}