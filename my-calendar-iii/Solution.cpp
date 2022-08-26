// https://leetcode.com/problems/my-calendar-iii

class MyCalendarThree {
 public:
  multiset<pair<int, int>> endpoint;
  MyCalendarThree() {}

  int book(int start, int end) {
    endpoint.insert({start, 1});
    endpoint.insert({end, -1});

    int cur = 0, best = 0;
    for (auto [t, d] : endpoint) best = max(best, cur += d);
    return best;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
