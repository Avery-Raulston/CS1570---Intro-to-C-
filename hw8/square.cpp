//////////////////////////////////////////////////////////////
//Programmer: Avery Raulston
//Professor: Price
//File: square.cpp
//Description: this file contains the helper functions for the skware class
//Date Last Edited: May 2, 2021
//////////////////////////////////////////////////////////////

#include<iostream>
#include<cstdlib>
#include "square.h"
using namespace std;

skware :: skware(const short s)
{
  m_size = s;
  m_matrix = new short * [s];//matrix pts to an array of ptrs to shorts and is s long
  m_row_totals = new short [s]{0};//row_totals pts to an array of shorts and is s long
  m_col_totals = new short [s]{0};//col_totals pts to an array of shorts and is s long
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
cout<<"short constructor called"<<endl;
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
    for (int j = 0; j < m_size; j++)//loop through each array in matrix, filling the arrays 
    {
      m_matrix[i][j] = source.m_matrix[i][j];
    }
  }
}

skware & skware :: operator =(const skware & s)
{
  if ((*this) != s)
  {
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
    m_size = s.m_size;
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
  cout<<"copy assignment called"<<endl;
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

void skware :: display_puzzle()
{
  short rand_row;//row part of cell to be replaced
  short rand_col;//col part of cell to be replaced
  for (int i = 0; i < REPLACEMENT_NUM; i++)//replace REPLACEMENT_NUM number of positions with -1
  {
    do//ensure that a different cell is replaced each time
    {
      rand_row = rand() % m_size;
      rand_col = rand() % m_size;
    } while (m_matrix[rand_row][rand_col] == -1);
    m_matrix[rand_row][rand_col] = -1;
  }
  for (int i = 0; i < m_size; i++)//loop through m_matrix to print each array
  {
    for (int k = 0; k < ((m_size * CELL_SIZE) + CELL_SIZE + 1); k++)//making output look pretty
      cout<<"-";
    cout<<"-"<<endl<<"|";

    for (int j = 0; j < m_size; j++)//loop through matrix[i], printing each element
    {
      if (m_matrix[i][j] == -1)//if cell is -1, dont print it
        cout<<"   |";
      else
        cout<<" "<<m_matrix[i][j]<<" |";
    }
    if (m_row_totals[i] >= 10)//more making output look pretty
      cout<<" "<<m_row_totals[i]<<" |";
    else
      cout<<"  "<<m_row_totals[i]<<" |";
    cout<<endl;
  }
  for (int i = 0; i < ((m_size * CELL_SIZE) + CELL_SIZE + 1); i++)//more pretty output
    cout<<"-";
  cout<<"-"<<endl<<"|";
  for (int i = 0; i < m_size; i++)//still making output look pretty
  {
    if (m_col_totals[i] >= 10)
      cout<<" "<<m_col_totals[i]<<"|";
    else
      cout<<" "<<m_col_totals[i]<<" |";
  }
  cout<<endl;
  for (int i = 0; i < (m_size * CELL_SIZE); i++)// even more making output look pretty
    cout<<"-";
  cout<<"-";
  cout<<endl;
  
  return;
}

void skware :: solve()
{
  short solve1;//holds solution to first empty cell
  short solve2;//holds solution to second empty cell
  short solve3;//holds solution to third empty cell
  short solve4;//holds solution to fourth empty cell
  short solve5;//holds solution to fifth empty cell

  for (short a = MIN_NUM; a <= MAX_NUM; a++)
  {
    for (short b = MIN_NUM; b <= MAX_NUM; b++)
    {
      for (short c = MIN_NUM; c <= MAX_NUM; c++)
      {
        for (short d = MIN_NUM; d <= MAX_NUM; d++)
	{
          for (short e = MIN_NUM; e <= MAX_NUM; e++)
	  {
             if (is_solved(a, b, c, d, e))
               {
                 solve1 = a;
		 solve2 = b;
		 solve3 = c;
		 solve4 = d;
		 solve5 = e;
	       }
	  }
	}
      }
    }
  }
  return;
}

bool skware :: is_solved(short a, short b, short c, short d, short e)const
{
  skware temp = *this;
  bool test = false;//value to be returned. false until puzzle has been proven to be true
  short counter = 0;//how many times an empty cell has been tested
  for (int i = 0; i < m_size; i++)
  {
    temp.m_row_totals[i] = 0;
    temp.m_col_totals[i] = 0;
  }
  for (int row = 0; row < temp.m_size; row++)//loop through matrix
  {
    for (int col = 0; col < temp.m_size; col++)//loop through matrix[row]
    {
      if (temp.m_matrix[row][col] == -1)//if empty cell is found, fill it
      {
        switch (counter)//decide which variable to enter into cell
	{
          case 0:
            m_matrix[row][col] = a;
	  case 1:
	    m_matrix[row][col] = b;
	  case 2:
	    m_matrix[row][col] = c;
	  case 3:
	    m_matrix[row][col] = d;
	  case 4:
	    m_matrix[row][col] = e;
	}
	counter++;
      }
      temp.m_row_totals[row] += temp.m_matrix[row][col];
      temp.m_col_totals[col] += temp.m_matrix[row][col];
    } 
  }
  if (temp == (*this))
    test = true;
  return test;
}
