#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
      unordered_map<int, int> seenNums;

      for (int i = 0; i < nums.size(); ++i) {
        int req = target - nums[i];

        if (seenNums.count(req))
          return {i, seenNums[req]};

        seenNums[nums[i]] = i;
      }

      return {};
    }
};