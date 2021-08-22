#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n)
{
  vector<int> min_steps(n + 1, 0);
  vector<int> predecessor(n + 1);
  min_steps[0] = 1;

  for (int i = 2; i <= n; ++i)
  {
    min_steps[i] = min_steps[i - 1] + 1;
    predecessor[i] = i - 1;

    if (i % 2 == 0)
    {
      if (min_steps[i / 2] < min_steps[i])
      {
        min_steps[i] = min_steps[i / 2] + 1;
        predecessor[i] = i / 2;
      }
    }
    if (i % 3 == 0)
    {
      if (min_steps[i / 3] < min_steps[i])
      {
        min_steps[i] = min_steps[i / 3] + 1;
        predecessor[i] = i / 3;
      }
    }
  }

  vector<int> sequence;

  for (int i = n; i != 0; i = predecessor[i])
  {
    sequence.push_back(i);
  }

  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
