#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      if (s.size() <= 1)
        return s.size();

      unordered_map<char, int> map;

      size_t start = 0, maxLength = 0, n = s.size();

      for (size_t i = 0; i < n; ++i) {
        if (map.count(s[i]) && map[s[i]] >= start) {
          maxLength = max(maxLength, i - start);
          start = map[s[i]] + 1;
        }

        map[s[i]] = i;
      }

      return max(maxLength, n - start);
    }
};