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
const int NUM_BARF_NOISES = 10;     //number of barf noises
const string BARF_NOISES[NUM_BARF_NOISES] = {"GAGGGG!", "BLAHHCCCH", "BARBARA", "STREISAND!", "UGGGGHHH", "AAACCKKKK", "BLUHHHHH!", "BOUGGHHH", "UUURRKKKKK", "JOHNNN"};//barf noises that contestants make when they barf


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

//Name: get_health()
//Description: getter function for m_health
//Pre: None
//Post: m_health has been returned

//Name: get_constestant
//Description: getter function for m_is_contestant
//Pre: None
//Post: m_is_contestant has been returned

//Name: get_name
//Description: getter function for m_name
//Pre: None
//Post: m_name has been returned

//Name: get_weight
//Description: getter function for m_weight
//Pre: None
//Post: m_weight has been returned

//Name: set_cash
//Description: setter function for m_cash
//Pre: None
//Post: m_cash is set to the value passed to the function 

//Name: dies()
//Description: simulates customer dying
//Pre: None
//Post: m_health is set to 0, and m_is_alive is set to false

//Name: vomit()
//Description: simulates a customer vomting
//Pre: None
//Post: customer vomiting has been simulated, and their health has been halved

//Name: print_vomit()
//Description: prints the person vomiting to the screen
//Pre: None
//Post: it has been printed to the screen that the person vomited

//Name: throws_dawg
//Description: simulates a customer throwing a hawt dawg
//Pre: position must be in the range [0, size - 1]
//Post: customer throwing a dawg has been simulated

//Name: friend os & operator<<
//Description: overloads the insertion operator for the Customer class
//Pre: None
//Post: the insertion operator has been defined for the Customer class

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
    float get_cash()const{return m_cash;}
    bool get_alive()const{return m_is_alive;}
    short get_health()const{return m_health;}
    bool get_contestant()const{return m_is_contestant;}
    string get_name()const{return m_name;}
    int get_weight()const{return m_weight;}
    void set_cash(const int money){m_cash = money; return;}
    void set_contestant(const bool value){m_is_contestant = value; return;}
    void dies(){m_health = 0; m_is_alive = false; return;}
    void vomit();
    void print_vomit();
    void throws_dawg(Customer & c, Hawt_dawg & h);
    friend os & operator <<(ostream & os, const Customer & c);
};

//Description: returns a string from names.dat based on how many times this
//             function has been called
//Pre: None
//Post: string has been returned from names.dat based on how many times this
//	function has been called
string get_name_from_file();

//Description: returns a random string from BARF_NOISES
//Pre: None
//Post: a random string from BARF_NOISES has been returned
string get_random_barf_noise();

#endif
