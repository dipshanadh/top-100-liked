#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
      deque<int> numsDq;
      vector<int> result;

      for (int i = 0; i < nums.size(); ++i) {
        if (!numsDq.empty() && i - k == numsDq.front())
          numsDq.pop_front();

        while (!numsDq.empty() && nums[numsDq.back()] < nums[i])
          numsDq.pop_back();

        numsDq.push_back(i);

        if (i - k >= -1)
          result.push_back(nums[numsDq.front()]);
      }

      return result;
    }
};