//////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: square.cpp
//Description: this file contains the helper functions for the skware class
//Date Last Edited: Apr 28, 2021
//////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdlib>
#include "square.h"
using namespace std;

skware :: skware(const short s);
{
  int total
  m_size = s;
  m_matrix = new short * [s];//matrix pts to an array of ptrs to shorts and is s long
  m_row_totals = new short * [s];//row_totals pts to an array of shorts and is s long
  m_col_totals = new short * [s];//col_totals pts to an array of shorts and is s long
  for (int i = 0; i < s; i++)//each ptr points to an array of shorts and is s long
    m_matrix[i] = new short [s];

  for (int i = 0; i < s; i++)//loop through matrix, filling it with random shorts
  {
    for (int j = 0; j < s; j ++)//loop through matrix[i], filling it
    {
      m_matrix[i][j] = (rand() % (MAX_SIZE - MIX_SIZE + 1)) + MIN_SIZE;
    }
    
  }
}
