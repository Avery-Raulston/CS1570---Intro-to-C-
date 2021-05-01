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
  {
    delete[] m_matrix[i];
    m_matrix[i] = nullptr;
  }
  delete[] m_matrix;
  delete[] m_row_totals;
  delete[] m_col_totals;
  m_matrix = nullptr;
  m_row_totals = nullptr;
  m_col_totals = nullptr;
}

skware :: skware(const skware & source)
{
  m_size = source.m_size;
  m_row_totals = new short [m_size];
  m_col_totals = new short [m_size];
  m_matrix = new short * [m_size];
  for (int i = 0; i < m_size; i++)//loop from 0 to m_size - 1, filling arrays
  {
    m_row_totals[i] = source.m_row_totals[i];
    m_col_totals[i] = source.m_col_totals[i];
    m_matrix[i] = new short [m_size];
    for (int j = 0; i < m_size; i++)//loop through each array in matrix, filling the arrays 
      m_matrix[i][j] = source.m_matrix[i][j];
  }
}

skware skware :: operator =(const skware & s)
{
  if ((*this) != s)
  {
    m_size = s.m_size;
    delete[] m_row_totals;
    m_row_totals = nullptr;
    delete[] m_col_totals;
    m_col_totals = nullptr;
    for (int i = 0; i < m_size; i++)//loop through matrix, deleteing each array
    {
      delete[] m_matrix[i];
      m_matrix[i] = nullptr;
    }
    delete[] m_matrix;
    m_matrix = nullptr;
    m_row_totals = new short [m_size];
    m_col_totals = new short [m_size];
    m_matrix = new short * [m_size];
    for (int i = 0; i < m_size; i++)//loop through matrix, row_totals, and col_totals, filling them
    {
      m_row_totals[i] = s.m_row_totals[i];
      m_col_totals[i] = s.m_col_totals[i];
      m_matrix[i] = new short [m_size];
      for (int j = 0; j< m_size; j++)//loop through matrix[i], filling it
        m_matrix[i][j] = s.m_matrix[i][j];
    }
  }
  return *this;
}

bool skware :: operator ==(const skware & s)
{
  bool test = true;//object to be returned. true until there is a difference found between the calling object and s
  if (m_size == s.m_size)//if the size of the two arrays dont match, then we dont need to loop through the matrix
  {
    for (int i = 0; i < m_size; i++)//loop through m_matrix
    {
      for (int j = 0; i < m_size; i++)//loop through m_matrix[i]
      {
        if (m_matrix[i][j] != m_matrix[i][j])
          test = false;
      }
    }
  }
  else
    test = false;

  return test;
}

bool skware :: operator !=(const skware & s)
{
  return !((*this) == s);
}
