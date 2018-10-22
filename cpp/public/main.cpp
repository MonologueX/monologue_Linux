#include <iostream>
using namespace std;

//#define Max(a, b) ((a)>(b)?(a):(b))

inline int Max(int a, int b)
{
  return ((a)>(b)?(a):(b));
}

int main()
{
  int a1 = 10;
  int a2 = 20;
  cout << Max(a1, a2) << endl;
  cout << Max(a1, a2++) << endl;
  cout << Max(a1, ++a2) << endl;
  return 0;
}
