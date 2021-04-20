////////////////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: main.cpp
//Description: this file contains the main function for hw7 'the_project'
//Date Last edited: Apr 15, 2021
////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdlib>

#include "main.h"
#include "customer.h"
#include "hawt_dawg.h"
#include "hawtdawgmeister.h"

using namespace std;

int main()
{
  srand(time(NULL));

//Variables
  Customer contestants[NUM_CONTESTANTS];//contestants in the eating contest
  bool is_contest_going = true;//true while contest is going, false otherwise
  Hawtdawgmeister cletus("cletus", CLETUS_STARTING_MONEY);//the man who runs it all, Cletus

//Magic Code
  cout.setf(ios::fixed); 
  cout.setf(ios::showpoint); 
  cout.precision(2);

//Greeting  
  cout<<"Begin the Contest!!!"<<endl<<endl;
  cout<<"The Contestants are"<<endl<<endl;
  for (int i = 0; i < NUM_CONTESTANTS; i++)//print all of the contestants and their info
    cout<<"    "<<contestants[i]<<endl;

//Simulate Contest
  while (is_contest_going)//simulate rounds of eating contest until a winner has been declared
    is_contest_going = simulate_round(contestants, NUM_CONTESTANTS, cletus);
  cout<<"    No one ate anything! The contest is over!"<<endl<<endl;

//Declare winner and end program
  print_winner(contestants, NUM_CONTESTANTS, cletus);
  return 0;
}
