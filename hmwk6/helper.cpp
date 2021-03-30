//////////////////////////////////////////////////////////////
//Name: Avery Raulston
//File: helper.cpp
//Description: This file contains the functions for hw6.cpp
//////////////////////////////////////////////////////////////

#include "hw6.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

void assign_values(pants pants_array[], const int size)
{
  int file_length = get_file_length();
  for (int i=0; i < size; i++)//loop through array and assign values to all elements' member variables
  {
    pants_array[i].m_waist_measure = get_random_num(MIN_WAIST, MAX_WAIST);
    pants_array[i].m_inseam = random_file_num(file_length);
    pants_array[i].m_color = get_random_num(0, (COLOR_ARRAY_SIZE - 1));
    pants_array[i].m_available = true;
  }
  return;
}

int get_random_num(const int min, const int max)
{
  int random_num = (rand() % (max - min + 1)) + min;//calculates a random number in the range [min, max]
  return random_num;
}

int get_file_length()
{
  ifstream fin;//gives ability to create a file stream
  int counter = 0;//current number of integers counted in inseams.dat
  int temp;//placeholder to loop through file
  fin.open("inseams.dat");
	
  while (fin>>temp)//loop through file
    counter++;

  return counter;
}

int random_file_num(const int file_length)
{
  ifstream fin;//gives ability to create a file stream
  int random_num;//random number from file to be returned
  int position_random_num = rand() % (file_length + 1);//position in file for the number that will be returned
  fin.open("inseams.dat");
  
  for (int i = 1; i <= position_random_num; i++)//loop through values until position_random_num is hit
    fin>>random_num;
  
  fin.close();
  return random_num;
}

void fill_index(const pants pants_array[], const int pants_array_size, pants_of_size index_array[])
{
  for (int i = MIN_WAIST; i <= MAX_WAIST; i++)//assign each of index_array elements waist size in index_array with an int from MIN_SIZE to MAX_SIZE such that no sorting is needed later
    index_array[i - MIN_WAIST].m_waist_size = i;
  for (int i = 0; i < pants_array_size; i++)//increments each of index_array elements m_color_waist_size's elements based on each of pants_array's elements m_color
    index_array[pants_array[i].m_waist_measure - MIN_WAIST].m_color_waist_size[pants_array[i].m_color]++;
  return;
}

void sort_inventory(pants pants_array[], const int size)
{
  bool sorted = false;//determines when to end loop
  pants temp;//placeholder in order to switch array[i] and array[i+1]
  while (! sorted)//go through for loop until array is sorted by m_waist_measure
  {
    sorted = true;
    for (int i = 0; i < (size - 1); i++)//go through array, switching array[i] and array[i+1] if array[i] is greater than array[i+1]
    {
      if (pants_array[i].m_waist_measure > pants_array[i+1].m_waist_measure)//if array[i] > array[i+1], switch array[i] and array[i+1]
      { 
        temp = pants_array[i];
        pants_array[i] = pants_array[i+1];
	pants_array[i+1] = temp;
	sorted = false;
      }
    }
  }
  sorted = false;
  while (! sorted)//go through for loop until array is sorted by m_waist meausure and then by m_inseam
  {
    sorted = true;
    for (int i = 0; i < (size - 1); i++)//go through array, switching array[i] and array[i+1] based on m_waist_measure and m_inseam
    {
      if (pants_array[i].m_waist_measure == pants_array[i+1].m_waist_measure)//make sure to not mix up m_waist_measure order
      {
        if (pants_array[i].m_inseam < pants_array[i+1].m_inseam)//sort by m_inseam
	{
  	  temp = pants_array[i];
          pants_array[i] = pants_array[i+1];
	  pants_array[i+1] = temp;
	  sorted = false;
	}
      }
    }
  }
  return;
}

void print_inventory(const pants pants_array[], const int pants_array_size, const string color_array[])
{
  for (int i = 0; i < pants_array_size; i++)//print necessary information of each element in pants_array[]
  {
    if ((i == 0) || (pants_array[i].m_waist_measure > pants_array[i-1].m_waist_measure))//if first loop or an increment in m_waist_measure print waist, inseam, and color, otherwise print inseam and color
      cout<<"waist "<<pants_array[i].m_waist_measure<<"      inseam  "<<pants_array[i].m_inseam<<"  "<<color_array[pants_array[i].m_color];
    else
      cout<<"              inseam  "<<pants_array[i].m_inseam<<"  "<<color_array[pants_array[i].m_color];
    cout<<endl;
  }
  return;
}

int get_pants_color(const int waist_size, const pants_of_size index_array[])
{	
  int color;//color user wants
  do//force user to enter valid input	
  {	  
    cout<<"For size "<<waist_size<<" we have: "<<endl;;
    if (index_array[waist_size - MIN_WAIST].m_color_waist_size[0] > 0)//list all colors for waist size. didnt want to use ifs but couldnt find another way
      cout<<"                     black(enter 0)"<<endl;
    if (index_array[waist_size - MIN_WAIST].m_color_waist_size[1] > 0)
      cout<<"                     blue(enter 1)"<<endl;
    if (index_array[waist_size - MIN_WAIST].m_color_waist_size[2] > 0)
      cout<<"                     red(enter 2)"<<endl;
    if (index_array[waist_size - MIN_WAIST].m_color_waist_size[3] > 0)
      cout<<"                     rainbow(enter 3)"<<endl;
    if (index_array[waist_size - MIN_WAIST].m_color_waist_size[4] > 0)
      cout<<"                     checkered(enter 4)"<<endl;
    if (index_array[waist_size - MIN_WAIST].m_color_waist_size[5] > 0)
      cout<<"                     electric green(enter 5)"<<endl;
    if (index_array[waist_size - MIN_WAIST].m_color_waist_size[6] > 0)
      cout<<"                     polka dot(enter 6)"<<endl;
    cout<<"Enter your choice: (-1 for none): ";
    cin>>color;
    if (!((index_array[waist_size - MIN_WAIST].m_color_waist_size[color] > 0) && (color >= 0) && (color <= (COLOR_ARRAY_SIZE - 1)) || (color == -1 )))//test for valid input
      cout<<"Please enter a valid number"<<endl;
  } while (!((index_array[waist_size - MIN_WAIST].m_color_waist_size[color] > 0) && (color >= 0) && (color <= (COLOR_ARRAY_SIZE - 1)) || (color == -1 )));  
  return color;

}

bool does_waist_size_exist(const int waist_size, const pants pants_array[], const int size)
{
  bool exist = false;//true if waist_size is known to be equal to an elements m_waist_measure in pants_array, false otherwise
  for (int i = 0; i < size; i++)//walk through pants_array
  {
    if (waist_size == pants_array[i].m_waist_measure)//test for waist_size equal to pants_array[i].m_waist_measure
      exist = true;
  }
  return exist;
}

int get_inseam(const int waist_size, const int pant_color, const pants pants_array[], const int size)
{
  bool exist = false;//true if the inseam the user wants exists, false otherwise	
  int inseam;//inseam user wants	
  int counter = 0;//how many pants the user will have to choose from	
  int position = 0;//position that inseam to go to in inseams[]
  cout<<"For the waist size and color you selected, we have inseam length(s): ";	
  for (int i = 0; i < size; i++)//search loop for available pants with waist_size and pant_color
  {
    if ((pants_array[i].m_waist_measure == waist_size) && (pants_array[i].m_color == pant_color) && pants_array[i].m_available)//increment counter if pant_color and waist_size match up
    {	    
      cout<<endl<<"                                                                    "<<pants_array[i].m_inseam;
      counter++;
    }    
  }
  cout<<endl;
  int inseams[counter];//array of inseams for user to choose from
  for (int i = 0; i < size; i++)//search loop for available pants with waist_size and pant_color
  {
    if ((pants_array[i].m_waist_measure == waist_size) && (pants_array[i].m_color == pant_color) && pants_array[i].m_available)//add inseam to inseams[] array if pant_color and waist_size match up
    {
      inseams[position] = pants_array[i].m_inseam;
      position++;
    }
  }
  do//force user input to be a valid inseam or -1 for none
  {
    cout<<"What inseam length would you like(-1 for none): ";
    cin>>inseam;
    for (int i = 0; i < counter; i++)//loop through inseams[]
    {
      if ((inseams[i] == inseam) || (inseam == -1))//test valid input
        exist = true;
    }       
    if (! exist)
      cout<<"Please enter an inseam that we have"<<endl;
  } while (! exist);
  return inseam;
}

void sell_pant(const int waist_size, const int color, const int inseam, pants pants_array[], const int pants_array_size, pants_of_size index_array[])
{
  for (int i = 0; i < pants_array_size; i++)//search for pants that has waist_size colo and inseam in pants_array
  {
    if (pants_array[i].m_waist_measure == waist_size && pants_array[i].m_color == color && pants_array[i].m_inseam == inseam && pants_array[i].m_available == true)//if pant matches up with other parameters, change availablity to false
      pants_array[i].m_available = false;
  }
  index_array[waist_size - MIN_WAIST].m_color_waist_size[color]--;
  return;
}

int calculate_price(const int waist_size, const int inseam)
{
  int price;//value to be returned
  price = (inseam < (HIGH_WATER_STANDARD * waist_size) - 2 ? waist_size + inseam + HIGH_WATER_BONUS : waist_size + inseam);//calculates price based on equation given for hw6
  return price;
}
