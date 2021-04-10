#include<cstdlib>
#include "random.h"
using namespace std;

int get_random_num(const int min, const int max)
{
  return (rand() % (max-min + 1)) + min;//returns a value in the range [min, max]
}
