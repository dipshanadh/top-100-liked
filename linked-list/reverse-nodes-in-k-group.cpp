#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
      ListNode *temp = head;

      for (int i = 0; i < k; ++i) {
        if (temp == nullptr)
          return head;

        temp = temp->next;
      }

      ListNode *prev = nullptr, *curr = head, *next;

      for (int i = 0; i < k; ++i) {
        next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
      }

      head->next = reverseKGroup(curr, k);

      return prev;
    }
};