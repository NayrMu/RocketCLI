#pragma once
#include <string>
#include <iostream>
#include "rocketengine.h"
#include "commands.h"
#include "view.h"
#include "routine.h"
/*
* Class for handling the Command Line Interface
* 
*/
class CmdControl {
public:
	// Constructor
	CmdControl();
	//Destructor
	~CmdControl();
	// Parses the initial user input
	Commands parseCommand(std::string userInput);
	// Prompts the user for input
	void cmdPrompt();
	// Universal method for splitting a string at a specified delimiter
	std::vector<std::string> splitString(std::string str, char delim);


private:
	// Current Command being run
	Commands currentCommand;
	// Current running instance of rocket simulation engine
	RocketEngine* rocketRunTime;
};