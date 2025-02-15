/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>::iterator left = s.begin();
        vector<char>::iterator right = s.end() - 1;
        while (left < right) {
          char temp = *left;
          *left = *right;
          *right = temp;
          left++;
          right--;
          
        }
    }
};
// @lc code=end

