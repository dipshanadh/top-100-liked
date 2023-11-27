#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
      unordered_map<string, vector<string>> groups;

      for (string &s : strs) {
        string temp = s;

        sort(s.begin(), s.end());

        groups[s].push_back(temp);
      }

      vector<vector<string>> result;

      for (auto &pair : groups)
        result.push_back(pair.second);

      return result;
    }
};