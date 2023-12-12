#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
      if (t == "") return "";

      unordered_map<char, int> target, window;

      for (char &ch : t) ++target[ch];

      size_t 
        have  = 0, need   = target.size(),
        res   = 0, resLen = SIZE_MAX,
        start = 0, size   = s.size();

      for (int end = 0; end < size; ++end) {
        char ch = s[end];

        if (target[ch] == ++window[ch]) ++have;

        while (have == need) {
          size_t currLen = end - start + 1;

          if (currLen < resLen) {
            res     = start;
            resLen  = currLen;
          }

          char toPop = s[start++];

          if (--window[toPop] < target[toPop]) --have;
        }
      }

      return resLen == SIZE_MAX ? "" : s.substr(res, resLen);
    }
};