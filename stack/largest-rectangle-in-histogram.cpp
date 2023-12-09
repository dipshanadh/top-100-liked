#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
      int n = heights.size(), maxArea = 0;
      
      stack<pair<int, int>> indices; // <index, height>

      for (int i = 0; i < n; ++i) {
        int start = i;

        while (!indices.empty() && indices.top().second > heights[i]) {
          maxArea = max(
            maxArea, indices.top().second * (i - indices.top().first)
          );
          start = indices.top().first;

          indices.pop();
        }

        indices.push({start, heights[i]});
      }

      while(!indices.empty()) {
        maxArea = max(
          maxArea, indices.top().second * (n - indices.top().first)
        );

        indices.pop();
      }

      return maxArea;
    }
};