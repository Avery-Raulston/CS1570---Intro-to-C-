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
  const string pants_color[COLOR_ARRAY_SIZE] = {"black", "blue", "red", "rainbow", "checkered", "electric green", "polka dot"}; //array for colors of pants. tried to put this in .h file since its const but i was getting weird errors and couldn't figure out how to fix it
  pants barts_pants[NUM_PANTS]; //array for all of the pants Bart can sell
  pants_of_size pants_index[MAX_WAIST-MIN_WAIST+1]; //array for how many colors and inseam of each waist measurment bart has
  int waist_size; //waist size of customer
  int pant_color;//color of pants the customer wants
  bool customer = true; //true if there is a customer for bart, false if otherwise

//Set up the arrays and print the pants bart has
  assign_values(barts_pants, NUM_PANTS);
  fill_index(barts_pants, NUM_PANTS, pants_index, MAX_WAIST - MIN_WAIST + 1);

  sort_inventory(barts_pants, NUM_PANTS);
  print_inventory(barts_pants, NUM_PANTS, pants_color);  

//Interact with the customers
  while (customer)//loops until customers are gone
  {
    do//prompt for user waist size until they enter an int in [20, 40]
    {
      cout<<"Enter waist size: ";
      cin>>waist_size;
      if (not does_waist_size_exist(waist_size, barts_pants, NUM_PANTS))//tell user to leave if bart doesnt have pants to fit them
        cout<<"We don't have that size, go somewhere else to shop"<<endl;
    }  while (not does_waist_size_exist(waist_size, barts_pants, NUM_PANTS));// waist size is randomly generated, and may not have every num in [20, 40], this ensures bart has the waist size the customer wants, and doesnt assume bart has every waist_size in [20, 40]
//FIXME print_color do while loop goes here
  }
  return 0;
}
