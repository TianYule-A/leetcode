/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
      queue<TreeNode*> que;
      vector<int> res;
      if (root==nullptr) {
        return {};
      }
      que.push(root);
      while (!que.empty()) {
        int size = que.size();
        for (int i=0; i<size; i++) {
          TreeNode* node = que.front();
          que.pop();
          if(i==size-1)
            res.push_back(node->val);
          if(node->left) que.push(node->left);
          if(node->right) que.push(node->right);
        }
      }
      return res;
    }
};
// @lc code=end

