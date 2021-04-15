///////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: main.h
//Description: this file is the header file for main.cpp
//Date last edited: Apr 15, 2021
///////////////////////////////////////////////////////////

#ifndef main_h
#define main_h

#include "customer.h"
const int NUM_CONTESTANTS = 15;

//Description: simulation for one round hawt dawg eating contest
//Pre: None
//Post: one round of the hawt dawg eating contest has been simulated, returns 
//      true if contest is still going, returns fals otherwise
bool simulate_round(Customer[], const int size);

//Desription: tests if customer can eat a hawt_dawg
//Pre: None
//Post: tested if customer can eat a hawt_dawg, returns true if yes, false if no
bool can_customer_eat(const Customer & c, const Hawt_dawg & h);

//Description: simulates feed a customer a hawt_dawg and their reaction to it
//Pre: None
//Post: customer eating a hawt_dawg and their reaction to it has been simulated
void feed_customer(Customer & c, const Hawt_dawg & h);

#endif
