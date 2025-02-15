// @before-stub-for-debug-begin
#include "commoncppproblem202.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
      unordered_set<int> sum_set;
      int sum = sum_all(n);
      while (true) {
        if (sum==1) {
            return true;
        }
        sum_set.insert(sum);
        sum = sum_all(sum);
        if (sum_set.find(sum)!=sum_set.end() && sum!=1) {
            return false;
        }
      }
    }
    int sum_all(int n) {
      int num_pos = 0;
      int sum =0;
      while (n!=0) {
        num_pos = n % 10;
        sum += num_pos*num_pos;
        n= n/10;
      }
      return sum;
    }
};

// int main() {
//     Solution sol{};
//   bool num =  sol.isHappy(19);
// }
// @lc code=end

