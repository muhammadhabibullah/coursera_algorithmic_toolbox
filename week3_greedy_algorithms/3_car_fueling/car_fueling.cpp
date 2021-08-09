#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    int numRefills = 0;
    int currentRefills = 0;
    stops.push_back(dist); // finished position
    int numOfStops = stops.size();
    while (currentRefills <= numOfStops)
    {
        int lastRefills = currentRefills;
        while (currentRefills <= numOfStops && stops[(currentRefills + 1)] - stops[lastRefills] <= tank)
        {
            currentRefills++;
        }

        if (currentRefills == lastRefills)
        {
            return -1; // IMPOSSIBLE
        }

        if (currentRefills <= numOfStops)
        {
            numRefills++;
        }
    }
    return numRefills;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+1);
    stops[0] = 0; // starting position always at 0
    for (size_t i = 1; i <= n; ++i)
    {
        cin >> stops.at(i);
    }

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
