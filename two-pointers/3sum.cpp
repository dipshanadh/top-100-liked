#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
      sort(nums.begin(), nums.end());

      vector<vector<int>> results;

      for (int i = 0; i < nums.size(); ++i) {
        int req = -nums[i], low = i + 1, high = nums.size() - 1;

        while (low < high) {
          int sum = nums[low] + nums[high];

          if (sum > req) --high;
          if (sum < req) ++low;

          if (sum == req) {
            vector<int> result = {nums[i], nums[low++], nums[high--]};

            while (low < high && nums[low] == result[1]) ++low;
            while (low < high && nums[high] == result[2]) --high;

            results.push_back(result);
          }
        }

        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) ++i;
      }

      return results;
    }
};