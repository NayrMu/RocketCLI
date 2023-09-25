#include "rocketengine.h"
/*
* Implentation for handling Rocket Simulation
*/
RocketEngine::RocketEngine() {
	// Setting variables
	fullPosition.push_back(0);
	fullPosition.push_back(0);
	fullPosition.push_back(0);
	xPos = 0;
	yPos = 0;
	zPos = 0;
	velocity = 0;
	thrust = 0;
	throttle = 0;
	// Creating a thread for handling simulation
	updateThread = std::thread(&RocketEngine::updateLoop, this);

	// Print to screen to let user know the simulation has begun
	std::cout << ":: ROCKET SIMULATION NOMINAL" << std::endl;
}
RocketEngine::~RocketEngine() {
	isRunning = false;
}

void RocketEngine::updateLoop() {
	// Simulaiton loop
	while (true) {
		while (isRunning) {
			setThrust(throttle); // Always checking for thrust updates
			if (thrust > 0) { // If thrust is not going to cause divide by zero error
				double dV = (thrust * 0.01) / 1000;
				setVelocity(dV);
				setXPos(velocity);
			}
			else { // Else do this
				double dV = 0;
				setVelocity(dV);
				setXPos(velocity);
			}

			

			std::this_thread::sleep_for(std::chrono::milliseconds(10)); // updates every 1/100 of a second
		}
	}
}
// Getters
double RocketEngine::getXPos() {
	return xPos;
}
double RocketEngine::getYPos() {
	return yPos;
}
double RocketEngine::getZPos() {
	return zPos;
}
double RocketEngine::getVelocity() {
	return velocity;
}
double RocketEngine::getThrottle() {
	return throttle;
}
bool RocketEngine::getIsRunning() {
	return isRunning;
}
double RocketEngine::getThrust() {
	return thrust;
}

// Setter
void RocketEngine::setXPos(double dX) {
	std::lock_guard<std::mutex> lock(xPosMutex);
	xPos += dX;
}
void RocketEngine::setIsRunning(bool isRun) {
	isRunning = isRun;
}
void RocketEngine::setThrottle(double dThrottle) {
	std::lock_guard<std::mutex> lock(throttleMutex);
	throttle += dThrottle;
}
void RocketEngine::setVelocity(double dV) {
	std::lock_guard<std::mutex> lock(velocityMutex);
	velocity += dV;
}
void RocketEngine::setThrust(double dThrust) {
	std::lock_guard<std::mutex> lock(thrustMutex);
	thrust = (100 * dThrust);
}