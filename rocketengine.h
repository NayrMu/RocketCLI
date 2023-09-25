#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <cmath>
/*
* Class for handling Rocket Simualtion
* Called Engine as in Game Engine or Physics Engine
*/
class RocketEngine {

public:
	
	RocketEngine();
	~RocketEngine();

	void updateLoop();

	//Getters
	double getXPos();
	double getYPos();
	double getZPos();
	double getVelocity();
	double getThrottle();
	double getThrust();
	bool getIsRunning();

	//Setters
	void setXPos(double dX);
	void setIsRunning(bool isRun);
	void setThrottle(double dThrottle);
	void setVelocity(double dV);
	void setThrust(double dThrust);



private:
	bool isRunning;

	std::thread updateThread;

	std::vector<double> fullPosition;
	double xPos;
	double yPos;
	double zPos;
	double velocity;
	double thrust;
	double throttle;
	std::mutex xPosMutex, yPosMutex, zPosMutex, velocityMutex, throttleMutex, thrustMutex; // For handling multiple threads using the same variables



};