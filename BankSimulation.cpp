//Bryant Wong
//CSCI 2421 Homework 7

#include "BankSimulation.h"		
#include "Customer.h"		//to hold the duders' arrival and processing time

BankSimulation::BankSimulation()	//default constructor
{

}


void BankSimulation::runSimulation()
{
	//std::priority_queue<Customer, std::vector<Customer>, CompareCustomer> eventQueue;		//create a priority queue of custom class
	std::priority_queue<Customer> eventQueue;		//create a priority queue of a custom class

	std::ifstream infile ("input.txt");		//open the file with the arrival time and processing time information
	
	Customer cust;		//create an instance of Customer cust
	int arrival;		//temp int for inputting things
	int process;
	while (infile >> arrival)		//read until the end of the file into arrival
	{
		infile >> process;		//into process
		cust.setArrivalTime(arrival);		//set customer arrival time
		cust.setProcessTime(process);
		cust.setEventTime(arrival);		//set customer event time
		cust.setStatus('A');		//set customer status to "arrival" type
		eventQueue.push(cust);		//add to event queue
		numCustomers++;			//to keep track of total number of customers who entered
	}
	infile.close();


	std::cout << "Simulation Begins" << std::endl;
	while (eventQueue.empty() == false)		//while the priorityqueue has events in it
	{
		cust = eventQueue.top();		//the customer to be processed is the first in the eventqueue
		if (cust.getStatus() == 'A')		//if the event is an arrival
		{
			currentTime = cust.getEventTime();		//set the current time to the time of the event 
			std::cout << "Processing an arrival event at time: " << currentTime << std::endl;
			processArrival(cust, eventQueue);		//calling function to process an arrival
		}
		else
		{
			currentTime = cust.getEventTime();		//set the current time to the time of the event
			std::cout << "Processing a departure event at time: " << currentTime << std::endl;
			processDeparture(cust, eventQueue);		//calling the function to process a departure
		}
	}	
	std::cout << "Simulation ends. " << std::endl;
	std::cout << "Final Statistics:" << std::endl;
	std::cout << "Total number of people processed: " << numCustomers << std::endl;
	std::cout << "Average amount of time spent waiting: " << (float)cumulativeWait / (float)numCustomers << std::endl;
}


void BankSimulation::processArrival(Customer& customer, std::priority_queue<Customer>& events)
{

	events.pop();		//remove the event from the front of the eventqueue
	if (teller1Line.empty() && teller1Available)		//if the bankLine is empty and the teller is available
	{
		departureTime = currentTime + customer.getProcessTime();			//the departure time of this customer is the currentTime plus their processing time
		teller1Available = false;		//the teller is then unavailable
		customer.setEventTime(departureTime);		//set the time to the event that will happen next
		customer.setStatus('1');		//set the customer's status to departing
		events.push(customer);		//add the event to the eventqueue
	}
	else if (teller2Line.empty() && teller2Available)		//if the bankLine is empty and the teller is available
	{
		departureTime = currentTime + customer.getProcessTime();			//the departure time of this customer is the currentTime plus their processing time
		teller2Available = false;		//the teller is then unavailable
		customer.setEventTime(departureTime);		//set the time to the event that will happen next
		customer.setStatus('2');		//set the customer's status to departing
		events.push(customer);		//add the event to the eventqueue
	}
	else if (teller3Line.empty() && teller3Available)		//if the bankLine is empty and the teller is available
	{
		departureTime = currentTime + customer.getProcessTime();			//the departure time of this customer is the currentTime plus their processing time
		teller3Available = false;		//the teller is then unavailable
		customer.setEventTime(departureTime);		//set the time to the event that will happen next
		customer.setStatus('3');		//set the customer's status to departing
		events.push(customer);		//add the event to the eventqueue
	}

	else 	//if the line has people in it or the teller is not available
	{
		if (teller1Line.size() <= teller2Line.size() && teller1Line.size() <= teller3Line.size())		//if teller1's line is the shortest or equal to the other two lines
			teller1Line.push(customer);																	//put the customer into teller1's queue
		else if (teller2Line.size() < teller1Line.size() && teller2Line.size() <= teller3Line.size())
			teller2Line.push(customer);
		else if (teller3Line.size() < teller1Line.size() && teller3Line.size() < teller2Line.size())
			teller3Line.push(customer);
	}
}

void BankSimulation::processDeparture(Customer& customer, std::priority_queue<Customer>& events)
{
	events.pop();		//remove the event from the eventqueue

	if (!teller1Line.empty() && customer.getStatus() == '1')	//if teller's line is not empty
	{
		Customer tempCust = teller1Line.front();		//the customer is then the first person in the bankLine 
		teller1Line.pop();			//remove that person from the bankLine queue
		departureTime = currentTime + tempCust.getProcessTime();		//this customer's departure time is the currentTime plus their processing time
		cumulativeWait = cumulativeWait + (currentTime - tempCust.getArrivalTime());		//the cumulative waiting time is the cumulativeWait plus the difference between the previous event and the customer's arrival time
		tempCust.setStatus('1');		//set the customer's status to "left from teller 1's line"
		tempCust.setEventTime(departureTime);		//set the event time to the departure time
		events.push(tempCust);		//add the event to the eventqueue
	}
	else if (!teller2Line.empty() && customer.getStatus() == '2')       	//if teller's line is not empty and the previous person who left was from this line
	{
		Customer tempCust = teller2Line.front();		//the customer is then the first person in the bankLine 
		teller2Line.pop();			//remove that person from the bankLine queue
		departureTime = currentTime + tempCust.getProcessTime();		//this customer's departure time is the currentTime plus their processing time
		cumulativeWait = cumulativeWait + (currentTime - tempCust.getArrivalTime());		//the cumulative waiting time is the cumulativeWait plus the difference between the previous event and the customer's arrival time
		tempCust.setStatus('2');		//set the customer's status to "left from teller 2's line
		tempCust.setEventTime(departureTime);		//set the event time to the departure time
		events.push(tempCust);		//add the event to the eventqueue
	}
	else if (!teller3Line.empty() && customer.getStatus() == '3')
	{
		Customer tempCust = teller1Line.front();		//the customer is then the first person in the bankLine 
		teller1Line.pop();			//remove that person from the bankLine queue
		departureTime = currentTime + tempCust.getProcessTime();		//this customer's departure time is the currentTime plus their processing time
		cumulativeWait = cumulativeWait + (currentTime - tempCust.getArrivalTime());		//the cumulative waiting time is the cumulativeWait plus the difference between the previous event and the customer's arrival time
		tempCust.setStatus('1');		//set the customer's status to "left from teller 3's line"
		tempCust.setEventTime(departureTime);		//set the event time to the departure time
		events.push(tempCust);		//add the event to the eventqueue
	}
	else if (teller1Line.empty() && customer.getStatus() == '1')		//if the teller's line is empty and the person who departed came from this line, then the teller is available
		teller1Available = true;		
	else if (teller2Line.empty() && customer.getStatus() == '2')
		teller2Available = true;
	else if (teller3Line.empty() && customer.getStatus() == '3')
		teller3Available = true;
	
}

