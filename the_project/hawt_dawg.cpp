/////////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: hawt_dawg.cpp
//Description: this file contains the Hawt_dawg class for main.cpp
//Date last edited: Apr 15, 2021
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdlib>
#include "hawt_dawg.h"
#include "random.h"
using namespace std;

Hawt_dawg::Hawt_dawg(const int animals, const int onions, const int pickles, bool relish, bool cheese, bool pathogen)
{
  m_num_animals = animals;
  m_onion_ounces = onions;
  m_num_pickles = pickles;
  m_is_relish = relish;
  m_is_cheese = cheese;
  m_is_pathogen = pathogen;
  m_cost = (BREAD_COST + (ANIMAL_COST * animals) + (ONION_COST * onions) + (PICKLE_COST * pickles) + (RELISH_COST * relish) + (CHEESE_COST * cheese));//formula for cost of hawt_dawg
}

Hawt_dawg::Hawt_dawg()
{
  m_num_animals = get_random_num(MIN_CONDIMENTS, MAX_CONDIMENTS);
  m_onion_ounces = get_random_num(MIN_CONDIMENTS, MAX_CONDIMENTS);
  m_num_pickles = get_random_num(MIN_CONDIMENTS, MAX_CONDIMENTS);
  m_is_relish = rand() % 2;//fifty percent chance of being true
  m_is_cheese = rand() % 2;//fifty percent chance of being true
  m_is_pathogen = rand() % 100 > 90;//ten percent chance of being true
  m_cost = (BREAD_COST + (ANIMAL_COST * m_num_animals) + (ONION_COST * m_onion_ounces) + (PICKLE_COST * m_num_pickles) + (RELISH_COST * m_is_relish) + (CHEESE_COST * m_is_cheese));//formula for cost of hawt_dawg
}

ostream & operator <<(ostream & os, const Hawt_dawg & h)
{
  string relish = h.get_relish() ? "relish" : "no relish";
  string cheese = h.get_cheese() ? "cheese" : "no cheese";
  string pathogen = h.get_pathogen() ? "pathogen" : "no pathogen";
  os<<"The hawt_dawg has: "<<h.get_animals()<< "animals"<<endl;
  os<<"                   "<<h.get_onions()<<"ounces of onions"<<endl;
  os<<"                   "<<h.get_pickles()<<"pickles"<<endl;
  os<<"                   "<<relish<<endl;
  os<<"                   "<<cheese<<endl;
  os<<"                   "<<pathogen<<endl;
  return os;
}

