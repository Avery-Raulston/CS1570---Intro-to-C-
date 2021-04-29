//////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: square.h
//Description: this file is the header file for the skware class
//Date Last Edited: Apr 28, 2021
//////////////////////////////////////////////////////////////

#ifndef square_h
#define square_h

const short MAX_SIZE = 10;//max size of skware
const short MIN_SIZE = 6;//min size of skware
const short MIN_NUM = 1;//min number each cell can be filled with
const short MAX_NUM = 7;//max number each cell can be filled with

using namespace std;

//Name: skware
//Description: constructor for skware class
//Pre: s must be positive
//Post: an object of class skware has been created

//Name: ~skware
//Description: destructor for skware class
//Pre: None
//Post: an object of class skware has been destructed

//Name: skware operator =
//Description: copy assignment for skware class
//Pre: None
//Post: an object of class skware has been created and is a copy of a preexisting
//      object of class skware

class skware
{
  private: 
    short m_size;//row size and col size of matrix
    short * * m_matrix;//2D array for skware
    short * m_row_totals;//array of shorts for totals of rows in matrix
    short * m_col_totals;//array of shorts for totals of cols in matrix
  public: 
    skware(const short s); 
    ~skware();
    skware operator =(const skware & source);

};

#endif
