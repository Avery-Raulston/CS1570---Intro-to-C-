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
        vomit_reactions(contestants, size, i, cletus);
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
  int chance_of_death;//liklihood customer dies
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
  int i = starting_point + 1;//position in contestants [] array
  int chance_to_vomit;//liklihood of customer vomiting
  int chance_to_fight;//liklihood of cuustomer starting a food fight
  while (contestants[i].get_alive() && i < size)//walk down array, testing if contestant throws up or starts a food fight
  {
    chance_to_vomit = get_random_num(1, 100);
    chance_to_fight = get_random_num(1, 100);
    if (chance_to_vomit <= VOMIT_CHANCE)//if chance to vomit <= vomit chance, customer vomits
    { 
      contestants[i].vomit();
      contestants[i].print_vomit();
    }   
    i++;
  }
  cout<<"    "<<contestants[i].get_name()<<" doesn't barf"<<endl;
  if (chance_to_fight <= START_FOOD_FIGHT_CHANCE && contestants[i].get_alive())//test for food fight after vomiting ends)
    food_fight(contestants, size, i, cletus);
  
  i = starting_point - 1;
  while (contestants[i].get_alive() && i >= 0)//walk up array, testing if contestant throws up or starts a food fight
  {
    chance_to_vomit = get_random_num(1, 100);
    chance_to_fight = get_random_num(1, 100);
    if (chance_to_vomit <= VOMIT_CHANCE && contestants[i].get_alive())
    {
      contestants[i].vomit();
      contestants[i].print_vomit();
    }
    i--;
  }
  cout<<"    "<<contestants[i].get_name()<<" doesn't barf"<<endl;
  if (chance_to_fight <= START_FOOD_FIGHT_CHANCE && contestants[i].get_alive())
    food_fight(contestants, size, i, cletus);
  return;
}

void food_fight(Customer contestants[], const int size, const int starting_point, Hawtdawgmeister & cletus)
{
  int i = starting_point;//position in array
  int target = get_random_num(0, (size + 1));//target of thrown hawt_dawg
  int continue_chance; //chance food fight will continue
  bool thrown = false;//true if dawg was thrown, false otherwise
  do
  {
    Hawt_dawg h;//hot dawg to be thrown
    if (contestants[i].get_cash <= h.get_cost() && contestants[target].get_alive())//if contestant can afford the dawg, and taget is alive, then (s)he throws the dawg
    {
      contestants[i].throws_dawg(contestants, size, i, cletus, h);
      thrown = true;
    }
    else
    {
      thrown = false;
      if (! contestants[target].get_alive())//if target is dead, print it
        cout<<"        "<<contestants[i].get_name()<<" doesn't throw the hawt dawg at "<<contestants[target].get_name()<<" because "<<contestants[target].get_name()<<" is dead"<<endl;
    }
    continue_chance = get_random_num(1, 100);
    i = target;
    target = get_random_num(1, 100);
    if (continue_chance > CONTINUE_FOOD_FIGHT_CHANCE)//if target decides not to throw, print it
      cout<<"        "<<contestants[i].get_name()<<" decides not to throw a dawg"<<endl;
  } while ((target != (size + 1)) && (continue_chance <= CONTINUE_FOOD_FIGHT_CHANCE) && (thrown) && contestants[target].get_alive());//throw dawgs until food_fight ends
  return;
}
