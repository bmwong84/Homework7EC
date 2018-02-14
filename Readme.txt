*******************************************************
*  Name      :      Bryant Wong    
*  Student ID:      107571009           
*  Class     :  CSC 2421           
*  HW#       :  7  Extra Credit Assignment
*  Due Date  :  March 14, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program simulates customers arriving at a bank and being processed by three separate teller, each with their own queue.  
The program uses 3 queues to hold the customers waiting for certain tellers and a self-sorting priority queue to hold the 
arrival and departure events of each customer.

The program then calculates the total number of customers and the average waiting time for each customer.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This calls all the functions to carry out the steps in the description


Name:  BankSimulation.cpp
   Contains member functions for processing an arrival, departure, and for running the simulation.

Name:  BankSimulation.h
   Contains the class definition of BankSimulation and member functions processArrival and processDeparture and runSimulation.

Name:  Customer.h
   Contains the setters and getters for the class Customer and overloaded operator for sorting the priorityQueue.

   
*******************************************************
*  Circumstances of programs
*******************************************************
The program is complete and compiles and runs on visual studio community and csegrid.



Developed on Visual Studio Community 2015 14.0.25431.01 Update 3.



*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [WongHW7EC]

   Now you should see a directory named homework with the files:
	main.cpp
	BankSimulation.cpp
	BankSimulation.h
	Customer.h
	input.txt


2. Build the program.

    Change to the directory that contains the file by:
    % cd [WongHW7EC] 

    Compile the program by:
    % make

3. Run the program by:
   % ./hw7EC

4. Delete the obj files, executables, and core dump by
   %./make clean
