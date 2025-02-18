/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
      int slow = 0,fast = 0;
      for (int i = 0; i < haystack.size(); i++) {
        if (i+needle.size()>haystack.size()) {
         return -1;
        }
        if (haystack[i]==needle[0]) {
          slow = i;
          fast=0;
            while (haystack[slow]==needle[fast]) {
              if (fast ==needle.size()-1) {
                return i;
              }
              slow++;
              fast++;
            }
        }
      }
      return -1;
    }
};
// @lc code=end

