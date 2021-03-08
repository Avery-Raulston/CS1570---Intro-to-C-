////////////////////////////////////////////////////////////////////////
//Name: Avery Raulston
//File: hw5.cpp
//Description: This file contains the main function for homework 5
////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdlib>
#include "hw5.h"
using namespace std;

int main()
{
  srand(time(NULL));
//Variables
  int min_distance;
  int max_distance;
  int successes;
  float probability_of_success;

//Greeting and Input
  cout<<"Bart's Casino Arrival Percentage Calculator"<<endl<<endl;
  cout<<"Please enter the minimum distance you would like calculated: ";
  cin>>min_distance;
  cout<<"Please enter the maximum distance you would like calculated: ";
  cin>>max_distance;

//Logic and Output
  for (int i = min_distance; i <= max_distance; i++)
  {
    successes = 0; //This resets the amount of times someone makes it to the casino every time a new 10000 simulations is started
    for (int j = 0; j < NUM_ATTEMPTS; j++)
    {
      if (simulate_crisis_walk(i))
        successes++;
    }
    probability_of_success = calculate_probability(successes);
    print_result(i, probability_of_success);
  }
//Signing off statement
  cout<<"Thanks for using Bart's Casino Arrival Percentage Calculator"<<endl;
  cout<<"Goodbye!"<<endl;
  return 0;
}
