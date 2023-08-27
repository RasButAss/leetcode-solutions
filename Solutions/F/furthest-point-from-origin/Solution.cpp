// https://leetcode.com/problems/furthest-point-from-origin/

class Solution {
 public:
  int furthestDistanceFromOrigin(string moves) {
    unordered_map<char, int> cnt;
    for (char c : moves) ++cnt[c];
    return max(cnt['L'] + cnt['_'] - cnt['R'], cnt['R'] + cnt['_'] - cnt['L']);
  }
};
