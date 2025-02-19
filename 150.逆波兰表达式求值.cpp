/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  int evalRPN(vector<string>& tokens) {

    int res = 0;
    int num1, num2;
    stack<int> st;
    auto cacul = [](string operater, int num1, int num2) -> int {
      if (operater == "+") {
        return num1 + num2;
      } else if (operater == "-") {
        return num1 - num2;
      } else if (operater == "*") {
        return num1 * num2;
      } else {
        return num1 / num2;
      }
    };

    for (string s : tokens) {
      if (s == "+" || s == "-" || s == "*" || s == "/") {
        num2 = st.top();
        st.pop();
        num1 = st.top();
        st.pop();
        res = cacul(s, num1, num2);
        st.push(res);
      } else {
        int num = stoi(s);
        st.push(num);
      }
    }
    res = st.top();
    return res;
  }
};
// @lc code=end
