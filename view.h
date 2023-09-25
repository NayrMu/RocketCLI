#pragma once
#include "rocketengine.h"

class View {
public:
	// Constructor
	View(RocketEngine* rocketRunTime, std::vector<std::string> cmdVector);

	// Parses user input from previous step
	void parseInput(std::vector<std::string> userInput);

private:
	// Inputted vector of command strings
	std::vector<std::string> m_cmdVector;
	// Current Running instance of Rocket Simulation
	RocketEngine* m_rocketRunTime;
};