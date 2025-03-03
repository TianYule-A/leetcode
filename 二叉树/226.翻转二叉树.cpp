/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
public:
    TreeNode* invertTree(TreeNode* root) {
      queue<TreeNode*> que;
      if (root==nullptr) {
        return {};
      }
      que.push(root);
      while (!que.empty()) {
        int size = que.size();
        for (int i=0; i<size; i++) {
          TreeNode* node = que.front();
          que.pop();
          if(node->left) que.push(node->left);
          if(node->right) que.push(node->right);
          auto temp = node->left;
          node->left = node->right;
          node->right = temp;
        }
      }
      return root;  
    }
};
// @lc code=end

