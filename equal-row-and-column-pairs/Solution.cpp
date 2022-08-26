// https://leetcode.com/problems/equal-row-and-column-pairs

class Solution {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> cnt;
    for (auto row : grid) ++cnt[row];

    int n = grid.size();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j) swap(grid[i][j], grid[j][i]);

    int ret{};
    for (auto row : grid) ret += cnt[row];
    return ret;
  }
};
