#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  int numOfItems = values.size();

  vector<double> valuesPerWeights(numOfItems);
  vector<int> valuesPerWeightsIdx(numOfItems);

  // count
  for (int i = 0; i < numOfItems; i++)
  {
    valuesPerWeights[(i)] = (double)values[i] / weights[i];
    valuesPerWeightsIdx[i] = i;
  }

  // sort
  sort(valuesPerWeightsIdx.begin(), valuesPerWeightsIdx.end(), [&](int i, int j)
       { return valuesPerWeights[i] > valuesPerWeights[j]; });

  // get them to bag
  for (int i = 0; i < numOfItems; i++)
  {
    if (capacity <= 0)
    {
      break;
    }

    int idx = valuesPerWeightsIdx[i];
    double w = weights[idx];
    if (capacity < weights[idx])
    {
      w = capacity;
    }

    value += valuesPerWeights[idx] * w;
    capacity -= w;
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout << fixed;
  cout << setprecision(4);
  cout << optimal_value << endl;
  return 0;
}
