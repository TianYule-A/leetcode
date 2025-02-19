/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
      stack<char> st;
      for (auto c : s) {
        if (!st.empty() && st.top()==c) {
            st.pop();
        }else {
        
        st.push(c);
        }
      }
      string res;
      while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
      }
      reverse(res.begin(), res.end());
      return res;
    }
};
// @lc code=end

