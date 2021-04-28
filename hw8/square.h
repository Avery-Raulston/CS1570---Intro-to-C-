//////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: square.h
//Description: this file is the header file for the skware class
//Date Last Edited: Apr 28, 2021
//////////////////////////////////////////////////////////////

const short MAX_SIZE = 10;//max size of skware
const short MIN_SIZE = 6;//min size of skware

#ifndef skware_h
#define skware_h

using namespace std;

//Name: skware
//Description: constructor for skware class
//Pre: s must be positive
//Post: an object of class skware has been created

class skware
{
  private: 
    short m_size;//row size and col size of matrix
    short * * m_matrix;//2D array for skware
    short * m_row_totals;//array of shorts for totals of rows in matrix
    short * m_col_totals;//array of shorts for totals of cols in matrix
  public: 
    skware(const short s); 
};

#endif
