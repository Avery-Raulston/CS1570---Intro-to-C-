/////////////////////////////////////////////////////////////
//Name: Avery Raulston
//File: hw6.cpp
//Description: This file contains the main function for hw5
//////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdlib>
#include "hw6.h"
using namespace std;

int main()
{
  srand(time(NULL));
  
//Variables
  const string pants_color[COLOR_ARRAY_SIZE] = {"black", "blue", "red", "rainbow", "checkered", "electric green", "polka dot"}; //array for colors of pants
  pants barts_pants[NUM_PANTS]; //array for all of the pants Bart can sell
  pants_of_size pants_index[MAX_WAIST-MIN_WAIST+1]; //array for how many colors and inseam of each waist measurment bart has

//Set up the arrays and print the pants bart has
  assign_values(barts_pants, NUM_PANTS);
  fill_index(barts_pants, NUM_PANTS, pants_index, MAX_WAIST - MIN_WAIST + 1);
  sort_inventory(barts_pants, NUM_PANTS);

  
  return 0;
}
