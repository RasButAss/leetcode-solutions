// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

class Solution {
 public:
  int countOrders(int n) {
    long long ret = 1;
    for (int i = 1; i <= n; ++i) ret = (ret * i * (2 * i - 1)) % 1'000'000'007;
    return ret;
  }
};
