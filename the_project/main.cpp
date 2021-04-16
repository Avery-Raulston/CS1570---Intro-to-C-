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
//Variables
  Customer contestants[NUM_CONTESTANTS];//contestants in the eating contest
  bool contest = true; //true while eating contest is going on, false otherwise
  Hawtdawgmeister cletus("cletus", CLETUS_STARTING_MONEY);

  srand(time(NULL));

  while (contest)//simulate rounds of eating contest until contest ends
    contest = simulate_round(contestants, NUM_CONTESTANTS, cletus);
  return 0;
}
