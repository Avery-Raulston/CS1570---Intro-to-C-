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

skware :: skware(const short s)
{
  m_size = s;
  m_matrix = new short * [s];//matrix pts to an array of ptrs to shorts and is s long
  m_row_totals = new short [s];//row_totals pts to an array of shorts and is s long
  m_col_totals = new short [s];//col_totals pts to an array of shorts and is s long
  for (int i = 0; i < s; i++)//loop through matrix, creating and filling it
  {  
    m_matrix[i] = new short [s];
    for (int j = 0; j < s; j ++)//loop through matrix[i], filling it with random shorts
    {
      m_matrix[i][j] = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;//random num in the range [MIN_NUM, MAX_NUM]
      m_row_totals[i] += m_matrix[i][j];
      m_col_totals[j] += m_matrix[i][j];
    }
  }
}

skware :: ~skware()
{
  for (int i = 0; i < m_size; i++)
    delete[] m_matrix[i];
  delete[] m_matrix;
  delete[] m_row_totals;
  delete[] m_col_totals;
}
