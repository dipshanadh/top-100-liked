#include <bits/stdc++.h> 

using namespace std;

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
      int count = 0, sum = 0;

      unordered_map<int, int> sumOccurencies(nums.size());

      for (int &n : nums) {
        sum += n;

        if (sum == k) 
          ++count;

        if (sumOccurencies.count(sum - k))
          count += sumOccurencies[sum - k];

        ++sumOccurencies[sum];
      }

      return count;
    }
};