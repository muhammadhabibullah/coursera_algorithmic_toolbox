#include <iostream>

int get_change(int m)
{
  int n = 0;
  int coin[3] = {10, 5, 1};

  for (int i = 0; i < 3; i++)
  {
    int c = coin[i];
    while (m >= c)
    {
      m -= c;
      n++;
    }
    if (m == 0)
    {
      break;
    }
  }

  return n;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
