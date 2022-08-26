// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
 public:
  /** initialize your data structure here. */
  multiset<int> right;
  multiset<int, greater<int>> left;
  MedianFinder() {}

  void addNum(int num) {
    left.insert(num);
    right.insert(*left.begin());
    left.erase(left.begin());
    if (left.size() < right.size()) {
      left.insert(*right.begin());
      right.erase(right.begin());
    }
  }

  double findMedian() {
    if (left.size() > right.size()) return *left.begin();
    return (*right.begin() + *left.begin()) / 2.;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
