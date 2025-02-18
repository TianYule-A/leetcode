/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        map[nums1[i] + nums2[j]]++;
      }
    }
    int res = 0;
    for (int i = 0; i < nums3.size(); i++) {
      for (int j = 0; j < nums4.size(); j++) {
        if (map.find(-nums3[i] - nums4[j]) != map.end()) {
          res += map[-nums3[i] - nums4[j]];
        }
      }
    }
    return res;
  }
};
// @lc code=end
