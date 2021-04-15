/////////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: customer.h
//Description: this file is the header file for the Customer class
//Date last edited: Apr 15, 2021
/////////////////////////////////////////////////////////////////////

#ifndef customer_h
#define customer_h
#include<iostream>
#include "hawt_dawg.h"
using namespace std;

const int WEIGHT_GAIN_FROM_DAWG = 4;//weight gain from eating a hawt dawg
const int MIN_CASH = 25;            //min cash customer can start with
const int MAX_CASH = 75;	    //max cash customer can start with
const int MIN_HEALTH = 1; 	    //min health customer can start with
const int MAX_HEALTH = 100;    	    //max health customer can start with
const int MIN_WEIGHT = 75;          //min weight customer can start with
const int MAX_WEIGHT = 300;         //max weight customer can start with

//Name: Customer()
//Description: default constructor for Customer class
//Pre: None
//Post: m_name has been assigned a value from names.dat, m_cash has been assigned
//      a random value in the range [25, 75], m_health has been assigned a 
//      random value in the range [1, 100], m_weight has been assigned a random
//      value in the range [70, 300], and m_is_alive has been assigned true 
//      and m_is_contestant has been assigned true

//Name: void eat(const hawt_dawg & hot_dog)
//Description: simulates the customer eating a hawt dawg
//Pre: None
//Post: m_weight has been increased by WEIGHT_GAIN_FROM_DAWG, and m_cash has 
//      been decreased by the price the hawt dawg

//Name: get_cash()
//Description: getter function for m_cash
//Pre: None
//Post: m_cash has been returned

//Name: get_alive()
//Description: getter function for m_is_alive
//Pre: None
//Post: m_is_alive has been returned

class Customer
{
  private:
    string m_name;       //name of customer
    float m_cash;        //amount of money customer can spend
    short m_health;      //health value of customer
    int m_weight;        //how much customer weighs
    bool m_is_alive;     //true if customer is alive, false otherwise
    bool m_is_contestant;//true if customer is a contestant, false otherwise
  public:
    Customer();
    void eat(const Hawt_dawg & h);
    float get_cash(){return m_cash;}
    bool get_alive(){return m_is_alive;}
};

//Description: returns a string from names.dat based on how many times this
//             function has been called
//Pre: None
//Post: string has been returned from names.dat based on how many times this
//	function has been called
string get_name_from_file();

#endif
