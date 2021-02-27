//////////////////////////////////////////
//@file hmwk3.cpp
//@author Avery Raulston CS1570
//@brief Barts Financial Aid Program
////////////////////////////////////////// 

#include<iostream>
using namespace std;

//Description: The greeting() function will output a greeting message to the user
void greeting();

//Description: The sign_off() function will output a signing off message to the user
void sign_off();

//Description: The get_student_number() function will ask the user to input a 
//student number and return that value
int get_student_number();

//Description: The validate_student_number() function will be passed the student
// number returned in the get_student_number() function and return true or false 
// based on whether or not the number is a valid student number or not
bool validate_student_number(int student_number);

//Description: The input_assets() function will prompt for and return the monetary value of assets of the user
float input_assets();

//Description: The calculate_bfa() function will be passed user assets (assumes 
//zero if none have been entered), calculates and returns the BFA(Barts Financial Aid) formula
float calculate_bfa(float assets, int student_number);

int main()
{
// Variables and Constants
  
  const int ENTER_STUDENT_NUM = 1;
  const int VALIDATE_STUDENT_NUM = 2;
  const int ENTER_ASSETS = 3;
  const int CALCULATE_FINANCIAL_AID = 4;
  const int EXIT = 5; 
  int student_number = -1; //initialized because if num = -1, then we know to give an error message for case 2
  float student_assets = 0;
  float student_bfa;
  float financial_aid;
  short menu_choice = 0;
  bool is_student_num_valid = false; //initialized because if this is false, then we know to give an error messgae for case 3 and 4
  string menu = "\n1. Enter student number \n2. Validate this number \n3. Assets \n4. Calculate financial aid package \n5. Quit \nYou entered: ";

//Magic Code
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

// Logic, Calculations and Ouput

  greeting();
  while (menu_choice != EXIT)
  {
    do
    {
      cout<<menu;
      cin>>menu_choice;
      if (menu_choice <1 || menu_choice > 5)
      {
        cout<<"Invalid choice"<<endl;
      }
    } while (menu_choice < 1 || menu_choice > 5);
    
    switch (menu_choice)
    {
    case ENTER_STUDENT_NUM:
      student_number = get_student_number();
      is_student_num_valid = false;  // This makes sure that every time a new student number is entered, the user has to revalidate the number
      student_assets = 0; // This makes sure that the previous students assets don't carry over to the new student
      break;
    case VALIDATE_STUDENT_NUM:
      if (student_number == -1)
        cout<<"Error: Cannot validate student number because no student number has been entered"<<endl;
      else
      {  
        is_student_num_valid = validate_student_number(student_number);
        if (is_student_num_valid)
	  cout<<"The student number you entered is valid."<<endl;
	else
	  cout<<"The student number you entered is invalid."<<endl;
      }
      break;  
    case ENTER_ASSETS:
      if (student_number == -1)
        cout<<"Error: You must first enter a student number before you enter the student assets"<<endl;
      if (! is_student_num_valid)
        cout<<"Error: You must first validate the student number before you can enter the student assets"<<endl;
      if (student_number != -1 && is_student_num_valid)
        student_assets = input_assets();
      break;
    case CALCULATE_FINANCIAL_AID:
      if (student_number == -1)
        cout<<"Error: You must first enter a student number before you calculate the student financial aid"<<endl;
      if (! is_student_num_valid)
        cout<<"Error: You must first validate the student number before you can calculate the student financial aid"<<endl;
      if (student_number != 1 && is_student_num_valid)
      {
        financial_aid = calculate_bfa(student_assets, student_number);
        cout<<"The financial aid you will recieve is: $"<<financial_aid<<endl;
      }
      break;
    case EXIT:
      break;  
    }
  }
// Signing off Statement  
  sign_off();
  return 0;
}

void greeting()
{
  cout<<"	Bart's Financial Aid Calculation Program"<<endl;
  return;
}

void sign_off()
{
  cout<<"Goodbye!"<<endl;
  return;
}

int get_student_number()
{
  int student_number;
  do
  {
    cout<<"Please enter your seven digit student number: ";
    cin>>student_number;
    if (student_number < 1000000 || student_number > 9999999)
      cout<<"Invalid number"<<endl;
  }  
  while (student_number < 1000000 || student_number > 9999999);
  return student_number;
}

bool validate_student_number(int student_number)
{
  short digits_a_b = student_number/100000;
  if (digits_a_b == 15 || digits_a_b == 20 || digits_a_b == 25 || digits_a_b == 30 || digits_a_b == 35)
    return true;
  return false;
}

float input_assets()
{
  int student_assets;
  do
  { 
  cout<<"Please enter your student assets: ";
  cin>>student_assets;
  if (student_assets < 0 )
    cout<<"Error: Your assets must be zero or greater"<<endl;
  }
  while (student_assets < 0);
  return student_assets;
}

float calculate_bfa(float assets, int student_number)
{
  short digit_g = student_number % 10;
  short digit_f = (student_number % 100) / 10;
  short digit_e = (student_number % 1000) / 100;
  short digit_d = (student_number % 10000) / 1000;
  short digit_c = (student_number % 100000) / 10000;
  float student_aid;
  
  if (assets == 0)
    student_aid = digit_c * digit_d * digit_e * digit_f * digit_g;
  else
    student_aid = assets + ((digit_c + digit_d + digit_e + digit_f + digit_g) * 4.3);
  return student_aid;
}
