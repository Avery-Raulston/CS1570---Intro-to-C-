//////////////////////////////////////////////////////////////////////////////
//Name: Avery Raulston
//File: hw5_functions.cpp
//Description: This file contains all of the helper functions for hw5.cpp
//////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include "hw5.h"
using namespace std;

int simulation(const int distance)
{
  int successes = 0;  //Amount of times someone makes it to the casino
  for (int i = 0; i < NUM_ATTEMPTS; i++) //Simulates 10000 crisis_walks
  {
    if (simulate_crisis_walk(distance))  //Increases successes variable if person makes it to the casino
      successes++;
  }
  return successes;
}

bool simulate_crisis_walk(const int dist)
{
  bool success = false;  //true if person makes it to casino, false otherwise
  int blocks_from_home = 1;  //amount of blocks person is from home
  int move = 0;  //amount of blocks moved by person, forward or backwards
  do  //Simulates move towards or away from home
  {
    if (simulate_move(move))  //Increases blocks from home if person chooses to move toward casino and decreases otherwise
      blocks_from_home++;
    else
      blocks_from_home--;
    move++;  
  } while (blocks_from_home != 0 and blocks_from_home != dist);
  if (blocks_from_home == dist) //Tests if person has made it to the casino or not
    success = true;
  else
    success = false;
  return success;
}

bool simulate_move(const int num_moves)
{
  bool success = false;  //true if person moves toward casino, false otherwise
  int percentage = 100 - (num_moves * PERCENTAGE_DECREASE);  //chance of person moving toward casino
  int num = rand() % 100;  //random number from 1 to 100
  if (num <= percentage)  //tests if person moves forward or backwards
    success = true;
  else
    success = false;
  return success;
}

float calculate_probability(const int successes)
{
  float probability = (static_cast<float>(successes)/NUM_ATTEMPTS) * 100;  //Percentage of someone making it to the casino
  return probability;
}

void print_result(const int dist, const float probability)
{
  cout<<"The odds of someone making it to the casino who lives "<<dist<<" blocks away is "<<probability<<"%"<<endl;
  return;
}
