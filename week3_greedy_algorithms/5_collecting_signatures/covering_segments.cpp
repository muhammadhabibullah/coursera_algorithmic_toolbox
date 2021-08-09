#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment
{
  int start, end;
};

bool compareSegmentByEnd(const Segment &a, const Segment &b)
{
  return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments)
{

  sort(segments.begin(), segments.end(), compareSegmentByEnd);

  vector<int> points;

  int current = segments[0].end;
  points.push_back(current);

  for (size_t i = 0; i < segments.size(); ++i)
  {
    if ((current < segments[i].start) || (current > segments[i].end))
    {
      current = segments[i].end;
      points.push_back(current);
    }
  }
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
