// https://leetcode.com/problems/min-stack

class MinStack {
 public:
  vector<int> val, prev;
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    val.push_back(x);
    if (prev.empty() or x < val[prev.back()])
      prev.push_back(prev.size());
    else
      prev.push_back(prev.back());
  }

  void pop() {
    val.pop_back();
    prev.pop_back();
  }

  int top() { return val.back(); }

  int getMin() { return val[prev.back()]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
