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
  m_is_contestant = true;
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
  cout<<name<<endl;
  return name;
}

void Customer::eat(const Hawt_dawg & h)
{
  m_cash -= h.get_cost();
  m_weight += WEIGHT_GAIN_FROM_DAWG;
  return;
}

void Customer::vomit()
{
  m_health /= 2;//halve health
  if (m_health == 0)//if health goes to zero, they die
    dies();
  return;
}

void Customer::print_vomit()
{
  string barf_noise = get_random_barf_noise();//noise contestant makes when they vomit
  string second_barf_noise = get_random_barf_noise();//noise contestant makes when they vomit
  cout<<"    "<<m_name<<" barfs "<<barf_noise<<" "<<second_barf_noise<<endl;
  
  return;
}

string get_random_barf_noise()
{
  int position = get_random_num(0, NUM_BARF_NOISES - 1);
  return BARF_NOISES[position];
}

