#include "view.h"

// Constructor
View::View(RocketEngine* rocketRunTime, std::vector<std::string> cmdVector) {
	m_rocketRunTime = rocketRunTime;
	m_cmdVector = cmdVector;
	parseInput(cmdVector);
}

// Parses user input from previous step
void View::parseInput(std::vector<std::string> userInput) {
	for (int i = 0; i < userInput.size(); i++) {
		if (userInput[i] == "xpos") {
			std::cout << ":> X POSITION: " << m_rocketRunTime->getXPos() << std::endl;
		}
		else if (userInput[i] == "ypos") {
			std::cout << ":> Y POSITION: " << m_rocketRunTime->getYPos() << std::endl;
		}
		else if (userInput[i] == "zpos") {
			std::cout << ":> z POSITION: " << m_rocketRunTime->getZPos() << std::endl;
		}
		else if (userInput[i] == "velocity") {
			std::cout << ":> Velocity: " << m_rocketRunTime->getVelocity() << std::endl;
		}
		else if (userInput[i] == "thrust") {
			std::cout << ":> Thrust: " << m_rocketRunTime->getThrust() << std::endl;
		}
		else if (userInput[i] == "throttle") {
			std::cout << ":> Throttle: " << m_rocketRunTime->getThrottle() << std::endl;
		}
	}	
}
