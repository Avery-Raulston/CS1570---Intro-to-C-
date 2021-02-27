#include<iostream>
using namespace std;

int main()
{
//	Variables and Constants

  int action_number;
  int input_counter = 0;
  short digit_a;
  short digit_b;
  short digit_c;
  short digit_d;
  short digit_e;
  char continue_loop = 'y';
  

//	Input and Greeting
  cout<<"	Barts Security Code Analyzer"<<endl<<endl;
  while (continue_loop == 'y' and input_counter < 4) // ensure user wants to enter another code and that bart doesn't get annoyed with too many codes
  {
    do //make sure input is valid
    {  
      cout<<"Enter code: ";
      cin>>action_number;
      if (action_number < 10000 or action_number > 99999)    
        cout<<"Code invalid"<<endl;
    }
    while (action_number < 10000 or action_number > 99999);
    input_counter++;

//	Calculations, Logic, and Output
    digit_e = action_number % 10;
    digit_d = (action_number % 100) / 10;
    digit_c = (action_number % 1000) / 100;
    digit_b = (action_number % 10000) / 1000;
    digit_a = (action_number % 100000) / 10000;

    if (digit_e % 2 == 0)
    {  
      cout<<"The code "<<action_number<<" means: card counter is still at the table"<<endl;
      if (digit_c == 3)
        cout<<"The code "<<action_number<<" means: card counter is under the table"<<endl;
    }  
    else
    {
      if (digit_b == 4)
        cout<<"The code "<<action_number<<" means: card counter is on the run"<<endl;
      if (digit_b + digit_c == 4)
        cout<<"The code "<<action_number<<" means: card counter drank too much Duff Soda and is throwing up in the bathroom"<<endl;
      if ((digit_a + digit_c + digit_e - (digit_b + digit_d)) % 11 == 0)
        cout<<"The code "<<action_number<<" means: Lisa is trying to report Bart"<<endl;
      if ((digit_b != 4) and (digit_b + digit_c != 4) and ((digit_a + digit_c + digit_e - (digit_b + digit_d)) % 11 != 0))
        cout<<"The code "<<action_number<<" means: we don't know where the card counter is"<<endl;
    }  
    cout<<"Translate another code? (y/n) ";
    cin>>continue_loop;
  }
  
//	Signing off Statement
  cout<<endl<<"Goodbye!"<<endl;
  return 0;  
} 
