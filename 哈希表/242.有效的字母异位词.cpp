/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        int alphabet[26] = {0};
        for (auto chr : s)
        {
            alphabet[chr - 'a']++;
        }
        for (auto chr : t)
        {
            alphabet[chr - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (alphabet[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
