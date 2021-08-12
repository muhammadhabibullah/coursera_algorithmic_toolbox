#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];

  int mid = (left + right) / 2;
  vector<int> majors(2);
  majors[0] = get_majority_element(a, left, mid);
  majors[1] = get_majority_element(a, mid + 1, right);

  for (int i = 0; i < 2; i++)
  {
    if (majors[i] == -1)
    {
      continue;
    }

    int count = 0;
    for (int j = left; j <= right; j++)
    {
      if (a[j] == majors[i])
      {
        count++;
      }
    }

    if (count > ((right - left) / 2))
    {
      return majors[i];
    }
  }

  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
