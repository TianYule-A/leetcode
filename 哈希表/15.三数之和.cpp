// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      sort(nums.begin(), nums.end());
      for (int i=0; i<nums.size(); i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int target = -nums[i];
        int left = i + 1, right = nums.size() - 1;
        while (left <right) {
          if (nums[left] +nums[right] == target ){
              res.push_back({nums[i], nums[left], nums[right]});
            }
            if(nums[left] + nums[right] < target) {
              left++;
              while (left < right && nums[left] == nums[left-1]) left++;
            } else {
              right--;
              while (left < right && nums[right] == nums[right + 1]) right--;
            }

        }
      }
     return res;
    }
};
// @lc code=end

