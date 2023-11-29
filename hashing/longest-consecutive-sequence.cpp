#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
      unordered_set<int> seen(nums.begin(), nums.end());

      int maxCount = 0;

      for (int &n : nums) {
        if (!seen.count(n - 1)) {
          int currCount = 1;

          while(seen.count(++n))
            ++currCount;

          maxCount = max(maxCount, currCount);
        }
      }

      return maxCount;
    }
};