/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include<vector>
#include<unordered_set>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(auto num:nums2)
        {
            if (nums_set.find(num)!=nums_set.end())
            {
                result.insert(num);
            }
            
        }
        return {result.begin(),result.end()};
    }
};
// @lc code=end

