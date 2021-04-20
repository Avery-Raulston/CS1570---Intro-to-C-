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
  static int num_rounds = 1;//number of rounds held so far
  cout<<endl<<"------------------------ ROUND #"<<num_rounds<<" ------------------------"<<endl<<endl;
  bool does_vomit = false;//true if customer vomits, false otherwise
  bool has_eaten = false;//true if someone is known to have eaten a dawg, false otherwise
  for (int i = 0; i < size; i++)//loop through Customer array, feeding each Customer a hawt_dawg, if they can eat it
  { 
    Hawt_dawg hot_dog;//get a new random dawg for every customer
    if (can_customer_eat(contestants[i], hot_dog))//if customer can eat the dawg, feed the customer the dawg
    {
      does_vomit = feed_customer(contestants[i], hot_dog);
      has_eaten = true;
      cletus += hot_dog.get_cost();
      if (does_vomit)//if cutomer vomits, walk down and up array until no one vomits or end of array is hit
        vomit_reactions(contestants, size, i, cletus);
    }
  }
  num_rounds++;
  return has_eaten;
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
  if (c.get_health() <= 0)//test if customer dies from eating dawg
  {
    c.dies();
    cout<<"    "<<c.get_name()<<" eats a dawg wt "<<c.get_weight()<<", health value "<<c.get_health()<<" ... DEAD"<<endl;
  }
  else if (h.get_pathogen())//test for pathogen in hawt_dawg
  {
    chance_of_death = get_random_num(1, 100);
    if (chance_of_death > c.get_health())//if chance of death > customers health, customer dies. else, customer vomits
    {
      c.dies();
      cout<<"    "<<c.get_name()<<" eats a dawg wt "<<c.get_weight()<<", health value "<<c.get_health()<<" ... DEAD"<<endl;
    }
    else
    {
      c.vomit();
      cout<<"    "<<c.get_name()<<" eats a dawg wt "<<c.get_weight()<<", health value "<<c.get_health()<<" ... ALIVE and barfs!"<<endl;
      does_vomit = true;
    }
  }
  else
    cout<<"    "<<c.get_name()<<" eats a dawg wt "<<c.get_weight()<<", health value "<<c.get_health()<<" ... ALIVE"<<endl;
  return does_vomit;
}

void vomit_reactions(Customer contestants[], const int size, const int starting_point, Hawtdawgmeister & cletus)
{
  int i = starting_point + 1;//position in contestants [] array
  int chance_to_vomit;//liklihood of customer vomiting
  int chance_to_fight;//liklihood of cuustomer starting a food fight
  bool did_vomit = true;//true if contestants vomited, false otherwise
  while (contestants[i].get_alive() && i < size && did_vomit)//walk down array, testing if contestant throws up
  {
    chance_to_vomit = get_random_num(1, 100);
    chance_to_fight = get_random_num(1, 100);
    if (chance_to_vomit <= VOMIT_CHANCE)//if chance to vomit <= vomit chance, customer vomits
    { 
      contestants[i].vomit();
      contestants[i].print_vomit();
      i++;
    } 
    else
    {
      did_vomit = false;  
      cout<<"        "<<contestants[i].get_name()<<" doesn't vomit"<<endl;
    }
  }
  if (starting_point + 1 < size && contestants[starting_point + 1].get_alive())//if loop above was entered, test for food fight
  {
    if (chance_to_fight <= START_FOOD_FIGHT_CHANCE && contestants[i].get_alive())//test for food fight
      food_fight(contestants, size, i, cletus);
  }
  i = starting_point - 1;
  did_vomit = true;
  while (contestants[i].get_alive() && i >= 0 && did_vomit)//walk up array, testing if contestant throws up
  {
    chance_to_vomit = get_random_num(1, 100);
    chance_to_fight = get_random_num(1, 100);
    if (chance_to_vomit <= VOMIT_CHANCE && contestants[i].get_alive())
    {
      contestants[i].vomit();
      contestants[i].print_vomit();
      i--;
    }
    else
    {
      did_vomit = false;
      cout<<"        "<<contestants[i].get_name()<<" doesn't vomit"<<endl;
    }
  }
  if (starting_point - 1 >= 0 && contestants[starting_point - 1].get_alive())//if above loop was enetered, check for food fight
  {
    if (chance_to_fight <= START_FOOD_FIGHT_CHANCE && contestants[i].get_alive())//test for food fight
      food_fight(contestants, size, i, cletus);
  }
  return;
}

void food_fight(Customer contestants[], const int size, const int starting_point, Hawtdawgmeister & cletus)
{
  int i = starting_point;//position in array
  int target;//target of thrown hawt_dawg
  int continue_chance; //chance food fight will continue
  bool thrown = false;//true if dawg was thrown, false otherwise
  do
  {
    target = get_random_num(0, size);
    Hawt_dawg h;//hawt_dawg to be thrown
    if (contestants[i].get_cash() < h.get_cost())//if contestant cant afford dog, print it
    {
      cout<<"            "<<contestants[i].get_name()<<" can't afford to throw a dawg"<<endl;
      thrown = false;
    }   
    else
    {
      if (target == size)//if target is cletus, cletus gets angry, otherwise, proceed as normal
        cletus.anger(contestants[i]);
      else
      {
        contestants[i].throws_dawg(contestants[target], h);
        thrown = true;
        continue_chance = get_random_num(1, 100);
        i = target;
      }
    }  
  } while ((target != (size + 1)) && (continue_chance <= CONTINUE_FOOD_FIGHT_CHANCE) && (thrown) && contestants[target].get_alive());//throw dawgs until food_fight ends
  return;
}

void print_winner(const Customer contestants[], const int size, const Hawtdawgmeister & cletus)
{
  Customer winners[size];//winners of the contest. technically could be all of them, however unlikely that is, so I made a big array
  int num_winners = 1;//number of winners, defaulted to 1
  winners[0] = contestants[0];
  for (int i =1 ; i < size; i++)//loop through contestants, adding winners to winners[] array
  {
    if (contestants[i].get_alive() && contestants[i].get_contestant())//test if contestants is alive and not dq'ed
    {
      if (contestants[i].get_health() > winners[0].get_health())//if contestants health is > winners health, contestants is new winner
      {
        winners[0] = contestants[i];
	num_winners = 1;
      }
      else if (contestants[i].get_health() == winners[0].get_health())//if contestants health == winners health, both are winners
      {
        winners[num_winners] = contestants[i];
	num_winners++;
      }
    }
  }
  
  if (num_winners == 1)//if one winner, print winner
    cout<<"The winner is: "<<winners[0]<<endl;
  else if (num_winners > 1)//if multiple winners, print all winners
  {
    cout<<"The winners are: "<<endl;
    for (int i = 0; i < num_winners; i++)//loop through winners array, printing winners
      cout<<"    "<<winners[i]<<endl;
  }
  else
    cout<<"The winner is: Cletus"<<endl;
  return;
}
