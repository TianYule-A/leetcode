// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem404.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
      int res=0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
      if (root==nullptr) {
        return 0;
      }
      int leftVal = sumOfLeftLeaves(root->left);
      if (root->left !=nullptr && root->left->left == nullptr && root->left->right ==nullptr) {
        leftVal =  root->left->val;
      }
      int rightVal = sumOfLeftLeaves(root->right);
      int sum = leftVal + rightVal;
      return sum;
    }
};
// @lc code=end

