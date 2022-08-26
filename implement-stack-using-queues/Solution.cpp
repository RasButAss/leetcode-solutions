// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
 public:
  queue<int> q1, q2;

  MyStack() {}

  void push(int x) { q1.push(x); }

  int pop(int p = 1) {
    while (q1.size() > 1) {
      int x = q1.front();
      q1.pop();
      q2.push(x);
    }

    int ret = q1.front();
    q1.pop();
    if (!p) q2.push(ret);

    while (!q2.empty()) {
      int x = q2.front();
      q2.pop();
      q1.push(x);
    }
    return ret;
  }

  int top() { return pop(0); }

  bool empty() { return q1.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
