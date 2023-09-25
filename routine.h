#pragma once
#include "rocketengine.h"
/*
* Class for handling different rocket Routines
* accessed with the 'start' keyword in CLI
*/
class Routine {
public:
	//Constructor
	Routine(RocketEngine* rocketRunTime, std::vector<std::string> cmdVector);
	
	// Parses userinput from previous step 
	void parseInput(std::vector<std::string> userInput);
	// Starts the simulated rocket engine
	void engineStart();
	// Increases the throttle by specified amount ie: input(50) throttle(25)->(75) ex: throttleUp 50
	void throttleUp(std::string dThrottle);
	// Decreases the throttle by specified amount ie: input(50) throttle(75)->(25) ex: throttleDown 50
	void throttleDown(std::string dThrottle);
	// Universal method for round a value to specified number of decimal places
	double roundToDecimalPlaces(double val, int decPlaces);
private:
	// Inputted vector of command strings
	std::vector<std::string> m_cmdVector;
	// Current Running instance of Rocket Simulation
	RocketEngine* m_rocketRunTime;
};