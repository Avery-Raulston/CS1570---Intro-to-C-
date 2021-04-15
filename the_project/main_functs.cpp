///////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: main_functs.cpp
//Description: this file contains the helper functions for main.h
//Date last edited: Apr 15, 2021
////////////////////////////////////////////////////////////////////

#include<cstdlib>

bool simulate_round(Customer[], const int size)
{
  for (int i = 0; i < size, i++)//loop through Customer array, feeding each Customer a hawt_dawg, if they can eat it
  { 
    Hawt_dawg hot_dog;//get a new random dawg for every customer
    if (can_customer_eat(Customer[i], hot_dog)//if customer can eat the dawg, feed the customer the dawg
      feed_customer(Customer[i], hot_dog)
  }
  return contest;
}

bool can_customer_eat(const Customer & c, const Hawt_dawg & h)
{
  return ((c.m_is_alive) && (c.m_get_cash >= h.get_cost) && (c.m_is_contestant))
}

void feed_customer(Customer & c, const Hawt_dawg & h)
{
  c.eat(h);

  return;
}
