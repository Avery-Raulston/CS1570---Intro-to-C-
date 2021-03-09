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

//Magic Code
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

//Variables
  int min_distance;  //Minimum distance away for the simulation to run
  int max_distance;  //Maximum distance away for the simulation to run
  int successes;     //Amount of people that make it to the casino per 10000 simulations
  float probability_of_success;  //Probability that someone makes it to the casino based on how many blocks away they live 

//Greeting and Input
  cout<<"Bart's Casino Arrival Percentage Calculator"<<endl<<endl;
  do  //Force user to enter a positive number for min_distance
  {	  
  cout<<"Please enter the minimum distance you would like calculated: ";
  cin>>min_distance;
  if (min_distance <= 0) //Inform user they must input a positive number if they didnt do so
    cout<<"Error: minimum distance must be positive"<<endl<<endl;
  } while (min_distance <= 0);

  do  //Force user to enter a number greater than min_distance
  {
  cout<<"Please enter the maximum distance you would like calculated: ";
  cin>>max_distance;
  if (max_distance <= min_distance) //Inform user they must input a number greater than the one they entered before if they didnt do so
    cout<<"Error: maximum distance must be greater than minimum distance"<<endl<<endl;
  } while (max_distance <= min_distance);

//Logic and Output
  for (int i = min_distance; i <= max_distance; i++)  //Simulates min to max distance, calculates probability and outputs results
  {
    successes = simulation(i);
    probability_of_success = calculate_probability(successes);
    print_result(i, probability_of_success);
  }
//Signing off statement
  cout<<"Thanks for using Bart's Casino Arrival Percentage Calculator"<<endl;
  cout<<"Goodbye!"<<endl;
  return 0;
}
