/////////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: customer.cpp
//Description: this file contains the Customer class for main.cpp
//Date last edited: Apr 6, 2021
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include "customer.h"
#include "random.h"
using namespace std;

Customer::Customer()
{
  m_name = get_name_from_file();
  m_cash = get_random_num(MIN_CASH, MAX_CASH);
  m_health = get_random_num(MIN_HEALTH, MAX_HEALTH);
  m_weight = get_random_num(MIN_WEIGHT, MAX_WEIGHT);
  m_is_alive = true;
}

string get_name_from_file()
{
  string name;//variable to be returned
  string temp;//placeholder to loop through file
  static int counter = 1;//how many times function has been called
  ifstream fin;
  fin.open("names.dat");
  
  for (int i = 0; i < counter; i++)//loop through file until desired name has been reached
    fin>>temp;
  
  name = temp;
  fin>>temp;
  counter++;

  if (fin.eof())//reset counter if last name in file has been read in
    counter = 1;
  fin.close();
  return name;
}

void Customer::eat(const Hawt_dawg & hot_dog)
{
  m_cash -= hot_dog.get_cost();
  m_weight += WEIGHT_GAIN_FROM_DAWG;
  return;
}
