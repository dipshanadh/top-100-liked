class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
      int size = nums.size();

      vector<int> result(size); 

      int prefix = 1, postfix = 1 ;
    
      for (int i = 0; i < size; ++i) {
        result[i] = nums[i] * prefix;
        prefix = result[i];
      }

      for (int i = size - 1; i > 0; --i) {
        result[i] = result[i - 1] * postfix;
        postfix *= nums[i];
      }

      result[0] = postfix;

      return result;
    }
};