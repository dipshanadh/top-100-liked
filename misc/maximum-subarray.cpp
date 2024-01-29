class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
      int maxCurr = nums[0], maxGlobal = nums[0];

      for (int i = 1; i < nums.size(); ++i) {
        maxCurr = max(maxCurr + nums[i], nums[i]);
        maxGlobal = max(maxCurr, maxGlobal);
      }

      return maxGlobal;
    }
};