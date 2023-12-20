#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *tempA = headA, *tempB = headB;

      size_t lenA, lenB;

      for (lenA = 0; tempA; ++lenA)
        tempA = tempA->next;

      for (lenB = 0; tempB; ++lenB) 
        tempB = tempB->next;
      
      if (tempA != tempB) return nullptr;

      while (lenA > lenB) {
        headA = headA->next;
        --lenA;
      }

      while (lenB > lenA) {
        headB = headB->next;
        --lenB;
      }

      while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
      }

      return headA;
    }
};