#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node *next;
  int val;
  int minVal;

  Node(int val, int minVal) : val(val), minVal(minVal), next(nullptr) {}
};

class MinStack {
  Node *head = nullptr;
  
  public:
    ~MinStack() {
      while (head)
        pop();
    }
   
    void push(int val) {
      if (!head) {
        head = new Node(val, val);
        return;
      }

      Node *temp = head;
      head = new Node(val, min(val, temp->minVal));
      head->next = temp;
    }
    
    void pop() {
      Node *temp = head;
      head = head->next; 

      delete temp;
    }
    
    int top() {
      return head->val;
    }
    
    int getMin() {
      return head->minVal; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */