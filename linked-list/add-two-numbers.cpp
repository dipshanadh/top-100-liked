#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      ListNode result(0), *temp = &result;

      int sum = 0;

      while (l1 || l2 || sum) {
        sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

        temp  = temp->next = new ListNode(sum % 10);
        sum   = sum > 9;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
      }

      return result.next;
    }
};