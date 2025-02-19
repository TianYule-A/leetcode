/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <deque>
#include <vector>
using namespace std;
class MyQueue {
    deque<int> Mon_que;

   public:
    int front() {
      return Mon_que.front();
    }
    void pop(int val) {
        if (!Mon_que.empty() && val==Mon_que.front()) {
            Mon_que.pop_front();
        }
    }
    void push(int val) {
      while (!Mon_que.empty() && val>Mon_que.back()) {
        Mon_que.pop_back();
      }
      Mon_que.push_back(val);
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      MyQueue que;
      vector<int>   res;
      for (int i=0; i<k; i++) {
        que.push(nums[i]);
      }
      res.push_back(que.front());
      for (int i=k; i<nums.size(); i++) {
        que.pop(nums[i - k]);
        que.push(nums[i]);
        res.push_back(que.front());
      }
      return res;
    }
};

// @lc code=end

