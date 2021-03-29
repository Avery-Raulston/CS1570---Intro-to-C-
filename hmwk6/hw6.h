/////////////////////////////////////////////////////
//Name: Avery Raulston
//File: hw6.h
//Description: This is the header file for hw6.cpp
/////////////////////////////////////////////////////

#ifndef hw6_h
#define hw5_h
#include<iostream>
using namespace std;

const int COLOR_ARRAY_SIZE = 7; //size of string array for pant colors
const int NUM_PANTS = 100; //amount of pants Bart can sell
const int MAX_WAIST = 40; //max waist size of pants that bart has
const int MIN_WAIST = 20; //min waist size of pants that bart has

struct pants
{
  int m_waist_measure; //waist measurment for pants
  int m_inseam; //inseam measurement for pants
  int m_color; //color of pants. must be from [0, COLOR_ARRAY_SIZE-1] number correlates with position in pants_color array in main
  bool m_available; //availability of pants
};

struct pants_of_size
{
  int m_waist_size; //waist size
  short m_color_waist_size[COLOR_ARRAY_SIZE]; //how many different colors of pants bart has of m_waist_size
};

//Description: assigns values to the member varaibles of the elements in the pants array passed to it
//Pre: None
//Post: pants array passed will have all the elements member variables assigned values
void assign_values(pants pants_array[], const int size);

//Description: returns a random nonnegative number in the range[min, max]
//Pre: min must be nonnegative, and max must be > min
//Post: a random positive numbe has been returned
int get_random_num(const int min, const int max);

//Desription: counts and returns the amount of integers in inseams.dat
//Pre: None
//Post: amount of integers in inseams.dat has been returned
int get_file_length();

//Description: returns a random integer from the inseams.dat file
//Pre: None
//Post: a random integer is found and returned from the inseams.dat file
int random_file_num(const int file_length);

//Description: fills pants_of_size array 
//Pre: None
//Post: pants_of_size array has been filled
void fill_index(const pants pants_array[], const int pants_array_size, pants_of_size index_array[], const int index_size);

//Description: sorts a pants array based on m_waist_measure first and then on m_inseam
//Pre: None
//Post: pants_array has been sorted based on m_waist measure first and then on m_inseam
void sort_inventory(pants pants_array[], const int size);

//Description: prints the pants bart has to the screen
//Pre: None
//Post: the pants bart can sell have been printed to the screen
void print_inventory(const pants pants_array[], const int pants_array_size, const string color_array[]);

//Description: tells the customer what colors bart has of the customers waist size, and returns what color the user chooses
//Pre: None
//Post: user has chosen a color of pants for their waist size
int get_customer_color(const int waist_size, const pants_of_size index_array[], const int size);

//Description: returns true if there is at least one element in pants_array with m_waist_measure that is equal to waist_size, returns false otherwise
//Pre: waist_size must be an integer in [20, 40]
//Post: tested if waist_size is equal to any elements m_waist_measure in pants_array, and returned true or false accordingly
bool does_waist_size_exist(const int waist_size, const pants pants_array[], const int size);

#endif
