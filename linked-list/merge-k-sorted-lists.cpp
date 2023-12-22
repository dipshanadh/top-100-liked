#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode*> &lists) {
      if (lists.empty())
        return nullptr;

      while (lists.size() > 1) {
        lists.push_back(mergeTwoLists(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
      } 

      return lists[0];
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
      ListNode *dummy = new ListNode(0), *temp = dummy;

      while (list1 && list2) {
        if (list1->val < list2->val) {
          temp->next = list1;
          list1 = list1->next;
        } else {
          temp->next = list2;
          list2 = list2->next;
        }

        temp = temp->next;
      }

      temp->next = list1 ? list1 : list2;

      return dummy->next;
    }
};