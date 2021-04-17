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
#include "hawtdawgmeister.h"

const int NUM_CONTESTANTS = 15; //Number of contestants in the eating contest

//Description: simulation for one round hawt dawg eating contest
//Pre: None
//Post: one round of the hawt dawg eating contest has been simulated, returns 
//      true if contest is still going, returns fals otherwise
bool simulate_round(Customer contestants[], const int size, Hawtdawgmeister & cletus);

//Desription: tests if customer can eat a hawt_dawg
//Pre: None
//Post: tested if customer can eat a hawt_dawg, returns true if yes, false if no
bool can_customer_eat(const Customer & c, const Hawt_dawg & h);

//Description: simulates feed a customer a hawt_dawg and their reaction to it
//Pre: None
//Post: customer eating a hawt_dawg and their reaction to it has been simulated,
//      returns true if customer vomits, false otherwise
bool feed_customer(Customer & c, const Hawt_dawg & h);

//Description: simulates reaction to someone vomiting, calls food_fight() function
//             if someone doesn't vomit
//Pre: starting_point must be in the range [0, size]
//Post: reactions to someone vomiting has been simulated
void vomit_reactions(Customer contestants[], const int size, const int starting_point, Hawtdawgmeister & cletus);

#endif
