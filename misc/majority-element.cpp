class Solution {
public:
    int majorityElement(vector<int> &nums) {
      unordered_map<int, int> hmap;

      for (int &num : nums) ++hmap[num];

      int n = nums.size() / 2;

      for (auto &[num, times] : hmap)
        if (times > n)
          return num;

      return 0;
    }
};