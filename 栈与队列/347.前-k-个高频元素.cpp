/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct Comparsion {
  
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
      return lhs.second>rhs.second;
    }
    };
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> map;
      for (auto num:nums) {
        map[num]++;
      }
      priority_queue<pair<int, int>, vector<pair<int, int>>, Comparsion> pq;
      for (auto pair : map) {
        pq.push(pair);
        if (pq.size()>k) {
            pq.pop();
        }
      }
      
      vector<int> res;
        while (!pq.empty()) {
          res.push_back(pq.top().first);
          pq.pop();
        }
        return res;
    }
};
// @lc code=end

