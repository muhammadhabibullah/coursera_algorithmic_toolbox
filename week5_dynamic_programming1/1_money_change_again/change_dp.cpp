#include <iostream>
#include <map>

using std::map;

int get_change(int money)
{
  const int biggestNum = 1000;
  int coins[3] = {1, 3, 4};

  map<int, int> min_num_coins;
  min_num_coins[0] = 0;
  for (int m = 1; m <= money; m++)
  {
    min_num_coins[m] = biggestNum;

    for (int i = 0; i < 3; i++)
    {
      if (m >= coins[i])
      {
        int numCoins = min_num_coins[m - coins[i]] + 1;
        if (numCoins < min_num_coins[m])
        {
          min_num_coins[m] = numCoins;
        }
      }
    }
  }

  return min_num_coins[money];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
