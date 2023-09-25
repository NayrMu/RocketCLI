#include "routine.h"
/*
* Implementation of rocket Routines
*/

//Constructor
Routine::Routine(RocketEngine* rocketRunTime, std::vector<std::string> cmdVector) {
	m_rocketRunTime = rocketRunTime;
	m_cmdVector = cmdVector;
	parseInput(cmdVector);
}

// Parses userinput from previous step 
void Routine::parseInput(std::vector<std::string> userInput) {
	std::string cmdString = userInput[0];
	if (cmdString == "engineStart") {
		this->engineStart();
	}
	else if (cmdString == "throttleUp") {
		this->throttleUp(userInput[1]);
	}
	else if (cmdString == "throttleDown") {
		this->throttleDown(userInput[1]);
	}

}

// Starts the simulated rocket engine
void Routine::engineStart() {
	m_rocketRunTime->setIsRunning(true);
	std::cout << ":: ENGINE STARTUP PROCEDURE COMPLETE" << std::endl;
}

// Increases the throttle by specified amount ie: input(50) throttle(25)->(75) ex: throttleUp 50
void Routine::throttleUp(std::string dThrottle) {
	double inputThrottle = roundToDecimalPlaces(std::stod(dThrottle), 1);
	if (!(m_rocketRunTime->getIsRunning()) || inputThrottle < 0) {
		std::cout << "!! A CRITICAL ERROR HAS OCCURRED !!" << std::endl;
		return;
	}

	if (inputThrottle > 100 || (inputThrottle + m_rocketRunTime->getThrottle() > 100)) {
		//More than maximum throttle threshold
	}
	else {
		m_rocketRunTime->setThrottle(inputThrottle);
		m_rocketRunTime->setThrust(m_rocketRunTime->getThrottle());
		std::cout << ":> THROTTLING UP BY: " << inputThrottle << " TO: " << m_rocketRunTime->getThrottle() << "%" << std::endl;
	}
}
// Decreases the throttle by specified amount ie: input(50) throttle(75)->(25) ex: throttleDown 50
void Routine::throttleDown(std::string dThrottle) {
	double inputThrottle = roundToDecimalPlaces(std::stod(dThrottle), 1) * -1;
	if (!(m_rocketRunTime->getIsRunning()) || inputThrottle > 0) {
		std::cout << "!! A CRITICAL ERROR HAS OCCURRED !!" << std::endl;
		return;
	}

	if (inputThrottle > 100) {
		//More than maximum throttle threshold
	}
	else {
		m_rocketRunTime->setThrottle(inputThrottle);
		m_rocketRunTime->setThrust(m_rocketRunTime->getThrottle());
		std::cout << ":> THROTTLING DOWN BY: " << (inputThrottle * -1) << " TO: " << m_rocketRunTime->getThrottle() << "%" << std::endl;
	}
}

// Universal method for round a value to specified number of decimal places
double Routine::roundToDecimalPlaces(double val, int decPlaces) {
	double multiplier = std::pow(10.0, decPlaces);
	return std::round(val * multiplier) / multiplier;
}