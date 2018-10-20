#include <stdio.h>

namespace N1
{
  int a = 10;
  int b;

  int Add(int left, int right)
  {
    return left + right;
  }
}

namespace N2
{
  int a = 30;
  int b = 40;

  int Sub(int left, int right)
  {
    return left - right;
  }

  namespace N3
  {
    int a = 50;
    int b = 60;

    int Mul(int left, int right)
    {
      return left * right;
    }
  }
}


namespace N1
{
  int c = 70;
  int d = 80;

  int Div(int left, int right)
  {
    return left / right;
  }
}

int a = 0;

int main()
{
  int a = 1;
  printf("a=%d\n", ::a);
  printf("a=%d\n", N1::a);
  printf("a=%d\n", N2::N3::a);
  return 0;
}
