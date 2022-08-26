// https://leetcode.com/problems/poor-pigs

class Solution {
 public:
  int poorPigs(int B, int mD, int mT) {
    int R = mT / mD, ret = 0, cur = 1;
    while (cur < B) ++ret, cur = cur * (R + 1);
    return ret;
  }
};
