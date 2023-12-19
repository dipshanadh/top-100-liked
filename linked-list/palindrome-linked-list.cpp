#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    bool isPalindrome(ListNode *head) {
      ListNode *mid = reverse(getMid(head));

      while (mid && mid->val == head->val) {
        mid = mid->next;
        head = head->next;
      }

      return mid == NULL;
    }

    ListNode *getMid(ListNode *head) {
      ListNode *fast = head, *slow = head;

      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }

      return slow;
    }

    ListNode *reverse(ListNode *head) {
      ListNode *prev = NULL, *curr = head;

      while (curr) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }

      return prev;
    }
};