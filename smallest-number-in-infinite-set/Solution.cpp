// https://leetcode.com/problems/smallest-number-in-infinite-set

class SmallestInfiniteSet {
 public:
  set<int> added;
  int smallest;
  SmallestInfiniteSet() : smallest(1) {}

  int popSmallest() {
    if (!added.empty()) {
      int ret = *added.begin();
      added.erase(added.begin());
      return ret;
    }
    return smallest++;
  }

  void addBack(int num) {
    if (num >= smallest) return;
    added.insert(num);
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
