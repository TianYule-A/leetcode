
/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
#include <string>
#include <utility>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i=0; i<s.size(); i+=2*k) {
            if (i+k > s.size()) {
                reverse(s, i, s.size()-1);
            } else {
              reverse(s, i, i+k-1);
            }
        }
        return s;
    }
    void reverse(string &s, int start, int end) {
      while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
      }
    }
};
// @lc code=end

