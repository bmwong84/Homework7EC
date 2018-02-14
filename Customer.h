//Bryant Wong
//CSCI 2421 Homework 7

#ifndef BANK_CUSTOMER
#define BANK_CUSTOMER
#include <string>

class Customer
{
private:

	int processTime = 0;		//the customer's processing time	
	char status;			//the customer's status, whether arrival or departure
	int arrivalTime = 0;		//the customer's arrival time


public:
	int eventTime = 0;		//the customer's eventTime (the time at whatever is happening to them is happening

	void setArrivalTime(int _arrival)		//setters & getters
	{
		arrivalTime = _arrival;
	}
	void setProcessTime(int _process)
	{
		processTime = _process;
	}
	void setEventTime(int _event)
	{
		eventTime = _event;
	}
	void setStatus(char _status)
	{
		status = _status;
	}
	int getArrivalTime()
	{
		return arrivalTime;
	}
	int getEventTime() const
	{
		return eventTime;
	}
	int getProcessTime()
	{
		return processTime;
	}
	char getStatus()
	{
		return status;
	}
};


inline bool operator < (const Customer& left, const Customer& right)
{
	return left.getEventTime() > right.getEventTime();
}

//struct CompareCustomer		//to sort the custom class in the priority queue
//{
//	bool operator () (Customer& left, Customer& right)		//overloaded operator()
//	{
//		return left.eventTime > right.eventTime;		//reversed to greater than because here, lowest time is the highest priority
//	}
//};





#endif