#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> result;
      vector<int> map(26, 0);
      
      for (char &ch : p) ++map[ch - 'a'];

      size_t sLen = s.size(), pLen = p.size();

      for (size_t i = 0; i < sLen; ++i) {
        // new char entering the window
        --map[s[i] - 'a'];

        // check if window size is equal to pLen
        if (i + 1 >= pLen) { 
          if (allZeores(map))
            result.push_back(i - pLen + 1);
            
          // char leaving the window
          ++map[s[i - pLen + 1] - 'a']; 
        }
      }

      return result;
    }

    bool allZeores(vector<int> &map) {
      for (int &count : map)
        if (count != 0) return false;

      return true;
    }
};