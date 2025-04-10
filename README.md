算法代码 在main。cpp，包括了几个测试用例

在这里贴出核心代码：
```
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
```
