///////////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: main_functs.cpp
//Description: this file contains the helper functions for main.h
//Date last edited: Apr 6, 2021
////////////////////////////////////////////////////////////////////

#include<cstdlib>

int get_random_num(const int min, const int max)
{
  return (rand() % (max-min + 1)) + min;//returns a value in the range [min, max]
}