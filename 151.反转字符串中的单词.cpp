// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem151.h"


using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
 public:
  string reverseWords(string s) {
    removeSpace(s);
    if (s.empty()) {
      return {};
    }
    reverse(s, 0, s.size() - 1);
    int slow = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        while (i < s.size() && s[i] != ' ') {
          i++;
        }
        reverse(s, slow, i - 1);
        slow = i + 1;
      }
    }
    return s;
  }
  void removeSpace(string &s) {
    int slow = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        if (slow != 0) {
          s[slow++] = ' ';
        }
        while (i < s.size() && s[i] != ' ') {
          s[slow++] = s[i++];
        }
      }
    }
    s.resize(slow);
  }
  void reverse(string &s, int start, int end) {
    while (start < end) {
      swap(s[start++], s[end--]);
      // start++;
      // end--;
    }
  }
};
// @lc code=end