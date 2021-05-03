//////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: main.cpp
//Description: this file contains the main function for hw8
//Date Last Edited: Apr 28, 2021
//////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdlib>
#include "main.h"
#include "square.h"
using namespace std;

int main()
{
  srand(time(NULL));
//Variables
  short size_of_board;//size of rows and columns for board
  bool is_playing = true;//true until user says they dont want to play a puzzle
  bool want_solution = false;//false until user says they want a solution to the puzzle displayed for them
  skware board = 3;//skware for user to solve
  skware soln = board;//copy of board

//Greeting
  cout<<"Welcome to the magic_skware puzzle giver!"<<endl;
  cout<<"Would you like to solve a magic_skware?(1 for yes, 0 for no) ";
  cin>>is_playing;

//Logic and Output
  while (is_playing)//loop until user doesn't want to play anymore
  {
    do //loop until user gives a value in [MAX_SIZE, MIN_SIZE]
    {
      cout<<"How big would you like your skware to be?"<<endl;
      cout<<"Please enter a number in the range [6, 10]: ";
      cin>>size_of_board;
      if (size_of_board < MIN_SIZE || size_of_board > MAX_SIZE)//if user doesnt give correct input, tell the user he/she is WRONG
        cout<<"WRONG!!"<<endl;
    }  while (size_of_board < MIN_SIZE || size_of_board > MAX_SIZE);
    skware board = size_of_board;
    soln = board;
    board.display_puzzle();
    cout<<"Here's your puzzle....solve it if you can!"<<endl;
    do//force user to say they want a solution
    {
      cout<<"Wanna solution?(1 for yes): ";
      cin>>want_solution;
      if (!want_solution)//if user doesnt want a solution, tell them they do
        cout<<"WRONG!!!"<<endl;
    } while (!want_solution);
    board.solve();
    cout<<"Would you like to solve another magic_skware?(1 for yes, 0 for no) ";
    cin>>is_playing;
  }

//Signing off Statement
 cout<<"BUH-BYE!"<<endl;  

  return 0;
}
