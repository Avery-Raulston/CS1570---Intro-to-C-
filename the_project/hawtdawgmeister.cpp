/////////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: hawtdawgmeister.cpp
//Description: this file contains the Hawdawgmeister class for main.cpp
//Date last edited: Apr 17, 2021
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include "customer.h"
#include "hawtdawgmeister.h"

void Hawtdawgmeister::anger(Customer & c)
{
  m_money += c.get_cash();
  c.set_cash(0);
  c.set_contestant(false);
  cout<<"        "<<c.get_name()<<" tosses a dawg at Cletus and gets disqualified"<<endl;
  return;
}
