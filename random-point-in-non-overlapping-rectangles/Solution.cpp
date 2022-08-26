// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles

class Solution {
 public:
  vector<vector<int>> rects;
  vector<int> psum;
  mt19937 gen;
  uniform_int_distribution<int> d1;
  Solution(vector<vector<int>>& rects) {
    this->rects = rects;
    psum.clear();

    int cur = 0;
    for (auto& r : rects) {
      cur += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
      psum.push_back(cur);
    }

    random_device rd;
    gen.seed(rd());
    d1 = uniform_int_distribution<int>(1, psum.back());
  }

  vector<int> pick() {
    int pos = lower_bound(psum.begin(), psum.end(), d1(gen)) - psum.begin();
    uniform_int_distribution<int> x(rects[pos][0], rects[pos][2]),
        y(rects[pos][1], rects[pos][3]);
    return {x(gen), y(gen)};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
