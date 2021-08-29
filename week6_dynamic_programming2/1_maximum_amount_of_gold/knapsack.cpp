#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::memset;
using std::min;
using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
  const int items = w.size();
  int **weights = new int *[items + 1];

  for (int i = 0; i <= items; i++)
  {
    weights[i] = new int[W + 1];
  }

  for (int i = 0; i <= items; i++)
  {
    for (int j = 0; j <= W; j++)
    {
      if (i == 0 || j == 0)
      {
        weights[i][j] = 0;
      }
      else if (w[i - 1] <= j)
        weights[i][j] = std::max(w[i - 1] + weights[i - 1][j - w[i - 1]], weights[i - 1][j]);
      else
        weights[i][j] = weights[i - 1][j];
    }
  }

  return weights[items][W];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
