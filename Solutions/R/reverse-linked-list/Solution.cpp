// https://leetcode.com/problems/reverse-linked-list

class Solution {
 public:
  ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
    if (!head) return head;
    ListNode* temp = head->next;
    head->next = prev;
    return temp ? reverseList(temp, head) : head;
  }
};
