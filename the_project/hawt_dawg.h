/////////////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: hawt_dawg.h
//Description: this file is the header file for the hawt_dawg.cpp file
//Date last edited: Apr 15, 2021
/////////////////////////////////////////////////////////////////////////

#ifndef hawt_dawg_h
#define hawt_dawg_h
#include<iostream>
using namespace std;

const int MIN_CONDIMENTS = 0;
const int MAX_CONDIMENTS = 4;
const float BREAD_COST = .5;
const float ANIMAL_COST = .75;
const float ONION_COST = .5;
const float PICKLE_COST = .25;
const float RELISH_COST = .25;
const float CHEESE_COST = .5;

//Name: Hawt_dawg(const int animals, const int onions, const int pickles, bool 
//      relish, bool chesse, bool pathogen)
//Description: constructor for Hawt_dawg class that can be passed values to all
//              of the member variables except m_cost
//Pre: animals, onions, and pickles must be in the range [0, 4]
//Post: all member variables have been set to the value passed to it

//Name: Hawt_dawg()
//Description: default constructor for Hawt_dawg class
//Pre: None
//Post: m_num_animals, m_onion_ounces, and m_num_pickles have been given a random
//      value in the range [0, 4], m_is_relish and m_is_relish have a 50% chance
//      of being true, and m_is_pathogen has a 10% chance of being true

//Name: get_animals()
//Description: getter function for m_num_animals
//Pre: None
//Post: m_num_animals has been returned

//Name: get_onions()
//Description: getter function for m_onion_ounces
//Pre: None
//Post: m_onion_ounces has been returned

//Name: get_pickles()
//Description: getter function for m_num_pickles
//Pre: None
//Post: m_num_pickles has been returned

//Name: get_relish()
//Description: getter function for m_is_relish
//Pre: None
//Post: m_is_relish has been returned

//Name: get_cheese()
//Description: getter function for m_is_cheese
//Pre: None
//Post: m_is_cheese has been returned

//Name: get_pathogen()
//Description: getter function for m_is_pathogen
//Pre: None
//Post: m_is_pathogen has been returned

//Name: get_cost()
//Description: getter function for m_cost
//Pre: None
//Post: m_cost has been returned

//Name: friend ostream & operator <<(ostream & os, const Hawt_dawg & hot_dog)
//Description: this function overloads the insertion operator
//Pre: None
//Post: the insertion operator has been defined for the Hawt_dawg class

class Hawt_dawg
{
  private: 
    int m_num_animals; //how many different animals are in the hawt_dawg
    int m_onion_ounces;//how many ounces of onions are in the hawt_dawg
    int m_num_pickles; //number of pickels on hawt_dawg
    bool m_is_relish;  //true if hawt_dawg contains relish, false otherwise
    bool m_is_cheese;  //true if hawt_dawg contains cheese, false otherwise
    bool m_is_pathogen;//true if hawt_dawg contains pathogen, false otherwise
    float m_cost;      //price of hawt_dawg
  public:
    Hawt_dawg(const int animals, const int onions, const int pickles, bool relish, bool cheese, bool pathogen);
    Hawt_dawg();
    int get_animals()const{return m_num_animals;}
    int get_onions()const{return m_onion_ounces;}
    int get_pickles()const{return m_num_pickles;}
    bool get_relish()const{return m_is_relish;}
    bool get_cheese()const{return m_is_cheese;}
    bool get_pathogen()const{return m_is_pathogen;}
    float get_cost()const{return m_cost;}
    friend ostream & operator <<(ostream & os, const Hawt_dawg & h);
};

#endif

