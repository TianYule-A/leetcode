

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      for (auto c : s) {
        switch (c) {
          case '(':
            st.push(c);
            break;
          case '[':
            st.push(c);
            break;
        case '{':
            st.push(c);
            break;
        case ')':if (!st.empty() && st.top()=='(') {
            st.pop();
            break;
        }else {
            return false;
        }
        case ']':if (!st.empty() && st.top()=='[') {
            st.pop();
            break;
        }else {
            return false;
        }
        case '}':if (!st.empty() && st.top()=='{') {
            st.pop();
            break;
        }else {
            return false;
        }
        }
      }
      if (st.empty()) {
        return true;
      }
      return false;
    }
};
// @lc code=end

