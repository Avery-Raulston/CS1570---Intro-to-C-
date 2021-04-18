/////////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: hawtdawgmeister.h
//Description: this file is the header file for hawtdawgmeister.cpp
//Date last edited: Apr 15, 2021
/////////////////////////////////////////////////////////////////////

#ifndef hawtdawgmeister_h
#define hawtdawgmeister_h

const float CLETUS_STARTING_MONEY = 0;

//Name: Hawtdawgmeister
//Description: constructor for Hawtdawgmeister class
//Pre: None
//Post: an object of type Hawtdawgmeister has been created with the values passed to it

//Name: operator +=
//Description: overloads the += operator for the Hawtdawgmeister class
//Pre: None
//Post: the += operator has been define for the Hawtdawgmeister class

//Name: operator -=
//Description: overloads the -= operator for the Hawtdawgmeister class
//Pre: None
//Post: the -= operator has been define for the Hawtdawgmeister class

//Name: anger
//Description: simulates cletus getting angry
//Pre: None
//Post: cletus getting angry has been simulated

class Hawtdawgmeister
{
  private: 
    string m_name;//name of hawtdawgmeister
    float m_money;//how much money cletus has
  public: 
    Hawtdawgmeister(const string name, const float money): m_name(name), m_money(money){}
    float operator +=(const float money){return m_money += money;}
    float operator -=(const float money){return m_money -= money;}
    void anger(Customer & c);
};

#endif
