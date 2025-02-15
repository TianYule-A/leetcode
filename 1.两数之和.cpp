// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> target_map;

      int size = nums.size();
      for (int i=0; i<size; i++) {
        if (target_map.find(target-nums[i])!=target_map.end()) {
            return vector<int>{i,target_map[target-nums[i]]};
        }
        target_map[nums[i]]=i;
      }
      return {};
    }
};
// @lc code=end

