#ifndef random_h
#define random_h
#include<cstdlib>
using namespace std;

//Description: calculates and returns a value in the range [min, max]
//Pre: min >= 0, max > min
//Post: a random number in the range [min, max] has been calculated and returned
int get_random_num(const int min, const int max);

#endif
