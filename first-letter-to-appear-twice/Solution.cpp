// https://leetcode.com/problems/first-letter-to-appear-twice

class Solution {
 public:
  char repeatedCharacter(string s) {
    set<char> ss;
    for (char c : s) {
      if (ss.count(c)) return c;
      ss.insert(c);
    }
    return ' ';
  }
};
