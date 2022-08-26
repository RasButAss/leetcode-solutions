// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition

class Solution {
 public:
  int maximumGroups(vector<int>& grades) {
    int x = 1, y = 1, n = grades.size();
    while (y <= n) y += ++x;
    return x - 1;
  }
};
