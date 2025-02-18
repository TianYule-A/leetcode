// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem18.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> res;
      if (nums.size() < 4) return res;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++) {
        if(nums[i] > target && nums[i] >= 0 ) break;
        if (i>0 && nums[i] == nums[i-1]) continue;
        for (int j=i+1; j<nums.size(); j++) {
            if (nums[i]+nums[j] > target && nums[i]+nums[j] >= 0 ) break;
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                long  sum = (long)nums[i] + nums[j] + nums[left] + nums[right]; //注意类型转换，中间结果溢出
                if (sum == target) {
                  res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                  left++;
                  right--;
                }else if (sum < target) {
                    left++;
                
                }else {
                    right--;
                }
            }
        } 
       
      }
      return res;
    }
};
// @lc code=end

