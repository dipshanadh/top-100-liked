#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string decodeString(string &s) {
      stack<int> numStack;
      stack<string> strStack;

      int currNum = 0;
      string currString;

      for (char &ch : s) {
        if (isdigit(ch)) 
          currNum = currNum * 10 + (ch - '0');

        if (isalpha(ch))
          currString += ch;

        if (ch == '[') {
          numStack.push(currNum);
          strStack.push(currString);

          currNum = 0;
          currString = "";
        }

        if (ch == ']') {
          int times = numStack.top();
          string str = strStack.top();

          numStack.pop();
          strStack.pop();

          currString = str + repeatString(currString, times);
        }
      }

      return currString;
    }

  private:
    string repeatString(string &s, int times) {
      string result;

      while (times-- > 0)
        result += s;

      return result;
    }
};