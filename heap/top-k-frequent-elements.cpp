class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // Get count - key: num, value: count
        unordered_map<int, int> map;
        for (int &x : nums) ++map[x];

        // Build buckets - index: count, value: nums
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &[key, value] : map)
            buckets[value].push_back(key);

        // Prepare result
        vector<int> result;
        for (int i = nums.size(); i >= 0; --i)
            for (int &x : buckets[i])
                if (--k >= 0) result.push_back(x);

        return result;
    }
};