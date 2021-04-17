///////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: main_functs.cpp
//Description: this file contains the helper functions for main.h
//Date last edited: Apr 15, 2021
////////////////////////////////////////////////////////////////////

#include<cstdlib>

#include "main.h"
#include "customer.h"
#include "hawt_dawg.h"
#include "hawtdawgmeister.h"
#include "random.h"

bool simulate_round(Customer contestants[], const int size, Hawtdawgmeister & cletus)
{
  bool contest = true;//true if contest is still going, false otherwise
  bool does_vomit = false;//true if customer vomits, false otherwise
  for (int i = 0; i < size; i++)//loop through Customer array, feeding each Customer a hawt_dawg, if they can eat it
  { 
    Hawt_dawg hot_dog;//get a new random dawg for every customer
    if (can_customer_eat(contestants[i], hot_dog))//if customer can eat the dawg, feed the customer the dawg
    {
      does_vomit = feed_customer(contestants[i], hot_dog);
      cletus += hot_dog.get_cost();
      if (does_vomit)//if cutomer vomits, walk down and up array until no one vomits or end of array is hit
        simulate_reactions(contestants[], size, i, cletus);
    }
  }
  return contest;
}

bool can_customer_eat(const Customer & c, const Hawt_dawg & h)
{
  return ((c.get_alive()) && (c.get_cash() >= h.get_cost()) && (c.get_contestant()));
}

bool feed_customer(Customer & c, const Hawt_dawg & h)
{
  bool does_vomit = false;//true if customer vomits, false otherwise
  int chance_of_death;
  c.eat(h);
  if (h.get_pathogen())//test for pathogen in hawt_dawg
  {
    chance_of_death = get_random_num(1, 100);
    if (chance_of_death > c.get_health())//if chance of death > customers health, customer dies. else, customer vomits
      c.dies();
    else
    {
      c.vomit();
      c.print_vomit();
      does_vomit = true;
    }
  }
  return does_vomit;
}

void vomit_reactions(Customer contestants[], const int size, const int starting_point, Hawtdawgmeister & cletus)
{
  return;
}
