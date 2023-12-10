#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int trap(vector<int> &height) {
      int n = height.size(),
        left = 0, right = n - 1,
        leftMax = 0, rightMax = 0,
        trapped = 0;

      while (left < right) {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);

        if (height[left] < height[right])
          trapped += max(0, leftMax - height[left++]);
        else
          trapped += max(0, rightMax - height[right--]);
      }

      return trapped;
    }
};