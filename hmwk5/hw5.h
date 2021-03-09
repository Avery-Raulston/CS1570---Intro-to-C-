////////////////////////////////////////////////////////////////////////////////
//Name: Avery Raulston
//File: hw5.h
//Description: This file contains the constants and parameters for hw5.cpp
////////////////////////////////////////////////////////////////////////////////

#ifndef hw5_h
#define hw5_h

const int NUM_ATTEMPTS = 10000;  //Amount of simulations per distance
const int PERCENTAGE_DECREASE = 5;

//Description: Simulates 10000 walks from home to casino and returns number of times the person makes it to the casino
//Pre: distance must be positive
//Post: 10000 walks have been simulated and amount of successes returned
int simulation(const int distance);

//Description: Simulates 1 walk from home to casino. Returns true if person makes it to the casino, and false if person returns to their home.
//Pre: dist must be positive
//Post: One walk from home to casino has been simulated
bool simulate_crisis_walk(const int dist);

//Description: Simulates 1 move. Returns true if person moves toward casino, and false if person moves toward home
//Pre: num_moves must be >= 0 
//Post: 1 move has been simulated
bool simulate_move(const int num_moves);

//Description: Calculates the probability of success out of 10000 trials
//Pre: successes must be in the range[0, 10000]
//Post: Probability of success has been calculated and returned
float calculate_probability(const int successes);

//Description: Prints result of simulation to the screen
//Pre: None
//Post: User is informed of the results of the simulation
void print_result(const int dist, const float probability);

#endif
