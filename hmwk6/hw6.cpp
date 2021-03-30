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
//Variables
  const string pants_color[COLOR_ARRAY_SIZE] = {"black", "blue", "red", "rainbow", "checkered", "electric green", "polka dot"}; //array for colors of pants. tried to put this in .h file since its const but i was getting weird errors and couldn't figure out how to fix it
  pants barts_pants[NUM_PANTS]; //array for all of the pants Bart can sell
  pants_of_size pants_index[MAX_WAIST-MIN_WAIST+1]; //array for how many colors and inseam of each waist measurment bart has
  int waist_size; //waist size of customer
  int pant_color;//color of pants the customer wants
  int inseam;//inseam size the customer wants
  int price;//price of pant customer wants to buy
  bool customer = true; //true if there is a customer for bart, false if otherwise

//Set up the arrays and print the pants bart has
  srand(time(NULL));
  assign_values(barts_pants, NUM_PANTS);
  fill_index(barts_pants, NUM_PANTS, pants_index);
  sort_inventory(barts_pants, NUM_PANTS);
  print_inventory(barts_pants, NUM_PANTS, pants_color);  

//Interact with the customers
  cout<<"Hello and welcome to Bart's Pants Store!"<<endl;
  while (customer)//loops until customers are gone
  {
    do//prompt for user waist size until they enter an int in [20, 40]
    {
      cout<<"Enter waist size: ";
      cin>>waist_size;
      if (! does_waist_size_exist(waist_size, barts_pants, NUM_PANTS))//tell user to leave if bart doesnt have pants to fit them
        cout<<"We don't have that size, go somewhere else to shop"<<endl;
    }  while (! does_waist_size_exist(waist_size, barts_pants, NUM_PANTS));// waist size is randomly generated, and may not have every num in [20, 40], this ensures bart has the waist size the customer wants, and doesnt assume bart has every waist_size in [20, 40]

    pant_color = get_pants_color(waist_size, pants_index);
    if (pant_color == -1)//if customer doesnt want pants, ask for another customer
    {
      cout<<"Is there another customer? Enter 1 for yes, 0 for no: ";
      cin>>customer;
    }
    else//ask for inseam
    {	    
      inseam = get_inseam(waist_size, pant_color, barts_pants, NUM_PANTS);
      if (inseam == -1)//if customer doesnt want pants, ask for another customer
      {
        cout<<"Is there another customer? Enter 1 for yes, 0 for no: ";
        cin>>customer;
      }
      else//give price of pants, say thanks for business, remove pants from inventory, and ask for another customer
      {     
        sell_pant(waist_size, pant_color, inseam, barts_pants, NUM_PANTS, pants_index);
	price = calculate_price(waist_size, inseam);
	cout<<"The price is: $"<<price<<endl;
	cout<<"Thank you for you business. Please come again!"<<endl;
	cout<<"Is there another customer? Enter 1 for yes, 0 for no: ";
        cin>>customer;
      }      
    }    	      
  }
//Sign off statement  
  cout<<"Thank you for visiting Bart's Pants Store."<<endl<<"Have a great day!"<<endl;
  return 0;
}
