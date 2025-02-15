/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty()) return true;
        if (magazine.empty()) return false;
        int count[26] = {0};
        for (char c : magazine) {
            count[c - 'a']++;
        }
        for(char c : ransomNote) {
            if (count[c - 'a'] == 0) return false;
            count[c - 'a']--;
        }
        return true;
    }
};
// @lc code=end

