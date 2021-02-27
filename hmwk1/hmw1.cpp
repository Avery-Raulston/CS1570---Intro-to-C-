// Programmer: Avery Raulston	Date: January 29, 2021
// File: barts_sugar_calculator.cpp	Class: CS1570
// Purposex

#include<iostream>
using namespace std;

//	Constants
const short avg_sugar_consumption = 2;
const short gut_feeling = 20;

int main()
{
//	Variables and Constants
	
	short num_people;
	short duff_soda;
	float avg_weight;
	float selm_index;
	float pounds_of_sugar;
	bool add_selm_or_not;

//	Welcoming statements and input

	cout<<"     Welcome to Bart's Duff Soda and Sugar Calculator"<<endl;
	cout<<""<<endl;
	cout<<"Please enter the following information:"<<endl;
	cout<<"  Number of gamblers:  ";
	cin>>num_people;
	cout<<"  Average weight of gamblers:  ";
	cin>>avg_weight;
	cout<<"  Today's SELM index:  ";
	cin>>selm_index;
	cout<<""<<endl;	
//	Calculations	

	add_selm_or_not = num_people > 5;
	pounds_of_sugar = num_people * (avg_weight * (static_cast<float>(avg_sugar_consumption) / gut_feeling) + (add_selm_or_not * selm_index));
	duff_soda = pounds_of_sugar/3;

//	Output and Signing off message
	
	cout<<"You will need "<<pounds_of_sugar<<" pounds of sugar, and that will create "<<duff_soda<<" bottles of Duff Soda."<<endl;
	cout<<"Have a nice day!"<<endl;

	return 0;
}	
