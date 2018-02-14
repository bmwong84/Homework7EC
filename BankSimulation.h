//Bryant Wong
//CSCI 2421 Homework 7

#ifndef BANK_SIMULATION
#define BANK_SIMULATION
#include "Customer.h"
#include <queue>		//for using queues
#include <fstream>		//for reading files
#include <iostream>		//for cout
#include <vector>

//#include <vector>



class BankSimulation
{
private:
	int currentTime=0;		//timer, holding the current time of events
	int cumulativeWait=0;		//to hold the cumulative wait time
	int numCustomers=0;			//to hold the total number of customers
	bool teller1Available = true;		//whether each teller is available or not
	bool teller2Available = true;
	bool teller3Available = true;
	std::queue<Customer> teller1Line;		//create a queue to represent the customers waiting for each teller
	std::queue<Customer> teller2Line;
	std::queue<Customer> teller3Line;
	int departureTime = 0;		//to hold the departure time

	
public:
	BankSimulation();
	void runSimulation();		//runs the simulation
	//member function to process the arrival of a customer, passing a customer, priorityqueue plus everything to sort it, and the bankqueue
	
	void processArrival(Customer& customer, std::priority_queue<Customer>& events);
	void processDeparture(Customer & customer, std::priority_queue<Customer>& events);

};


#endif
