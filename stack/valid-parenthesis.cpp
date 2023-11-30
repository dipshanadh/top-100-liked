#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      stack<char> chars;

      for (char &ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
          chars.push(ch);
          continue;
        }

        if (chars.empty())
          return false;

        if (!checkPair(ch, chars.top()))
          return false;

        chars.pop();
      }

      return chars.empty();
    }

  private:
    bool checkPair(char ch1, char ch2) {
      if (ch1 == ')' && ch2 == '(')
        return true;

      if (ch1 == '}' && ch2 == '{')
        return true;
        
      if (ch1 == ']' && ch2 == '[')
        return true;

      return false;
    }
};