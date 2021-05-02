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
const short REPLACEMENT_NUM = 5;//number of cells in m_matrix to be replaced 
                                //with -1
const short CELL_SIZE = 4;//size of cell displayed in display_puzzle

using namespace std;

//Name: skware(const short s)
//Description: constructor for skware class
//Pre: s must be positive
//Post: an object of class skware has been created

//Name: ~skware
//Description: destructor for skware class
//Pre: None
//Post: an object of class skware has been destructed

//Name: skware(const skware & source)
//Description: copy constructor for skware class
//Pre: None
//Post: an object of type skware has been created as a copy of an existing skware

//Name: skware operator =
//Description: copy assignment for skware class
//Pre: None
//Post: an object of class skware has been created and is a copy of a preexisting
//      object of class skware

//Name: skware operator ==
//Description: overloads the == operator for the skware class
//Pre: None
//Post: the == operator has been defined for the skware class

//Name: skware operator !=
//Description: overloads the != operator for the skware class
//Pre: None
//Post: the != operator has been defined for the skware class

//Name: void display_puzzle()
//Description: randomly chooses 5 positions in m_matrix and replaces them with -1
//             and outputs m_matrix to screen with blanks where the -1's are
//Pre: None
//Post: 5 positions in m_matrix has been replaced with -1 and m_matrix has been
//      outputted to the screen

//Name: void solve()
//Description: solves puzzle and then calls display_puzzle()
//Pre: 5 positions in m_matrix must be -1
//Post: board has been solved and display_puzzle() has been called

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
    skware(const skware & source);
    skware & operator =(const skware & source);
    bool operator ==(const skware & s);
    bool operator !=(const skware & s);
    void display_puzzle();
    void solve();
};

#endif
