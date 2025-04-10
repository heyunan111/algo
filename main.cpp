#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<int> getK(const vector<vector<int>> &a, int k) {
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>> q;
  vector<int> res;

  for (int i = 0; i < a.size(); ++i)
    if (!a[i].empty())
      q.emplace(a[i][0], i, 0);

  while (k-- && !q.empty()) {
    auto [v, r, c] = q.top();
    q.pop();
    res.push_back(v);
    if (c + 1 < a[r].size())
      q.emplace(a[r][c + 1], r, c + 1);
  }

  return res;
}

void printVec(const vector<int>& v) {
  for (int x : v)
    cout << x << " ";
  cout << endl;
}

int main() {
  // Test 1
  vector<vector<int>> a1 = {
      {1, 4, 7},
      {2, 5, 8},
      {3, 6, 9}
  };
  cout << "Test 1 :";
  printVec(getK(a1, 5));

  // Test 2
  vector<vector<int>> a2 = {
      {10, 20},
      {5, 15},
      {1, 2, 3}
  };
  cout << "Test 2 : ";
  printVec(getK(a2, 6));

  // Test 3
  vector<vector<int>> a3 = {
      {},
      {1},
      {},
      {0, 2}
  };
  cout << "Test 3:";
  printVec(getK(a3, 6));

  // Test 4
  vector<vector<int>> a4 = {
      {3, 4},
      {1}
  };
  cout << "Test 4 :";
  printVec(getK(a4, 10));

  return 0;
}
