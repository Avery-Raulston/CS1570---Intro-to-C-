//////////////////////////////////////////////////////////////////////////////
//Name: Avery Raulston
//File: hw5_functions.cpp
//Description: This file contains all of the helper functions for hw5.cpp
//////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include "hw5.h"
using namespace std;

bool simulate_crisis_walk(const int dist)
{
  bool success;
  int position = 1;
  int move = 0;
  do
  {
    if (simulate_move(move))
      position++;
    else
      position--;
    move++;
  } while (position != 0 and position != dist);
  if (position == 0)
    success == false;
  else
    success == true;
  cout<<position<<endl;
  return success;
}

bool simulate_move(const int num_moves)
{
  bool success;
  int percentage = 100 - (num_moves * 5);
  int num = rand() % 100;
  if (num > percentage)
    success = false;
  else
    success = true;
  return true;
}

float calculate_probability(const int successes)
{
  float probability = static_cast<float>(successes)/NUM_ATTEMPTS;
  return probability;
}

void print_result(const int dist, const int probability)
{
  cout<<"The odds of someone making it to the casino who lives "<<dist<<" blocks away is "<<probability<<endl;
  return;
}
