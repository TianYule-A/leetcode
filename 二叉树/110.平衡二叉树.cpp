/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include <algorithm>
#include <cstdlib>
class Solution {
public:
    bool isBalanced(TreeNode* root) {
      if (getHeight(root) == -1) return false;
      return true;
    }
    int getHeight(TreeNode* node) {
        if (node==nullptr) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        if (leftHeight==-1) {
            return -1;
        }
      int rightHeight = getHeight(node->right);
      if (rightHeight==-1) {
        return -1;
      }
      if (std::abs(leftHeight-rightHeight)>1) {
        return -1;
      }
      int height=std::max(leftHeight,rightHeight);
      return height+1;
    }

};
// @lc code=end

