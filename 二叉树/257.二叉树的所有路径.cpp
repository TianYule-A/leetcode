/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <string>
 using namespace std;
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<int> path;
      vector<string> result;
      if (root==nullptr) {
        return {};
      }
      getPath(root, path, result);
      return result;
    }
    void getPath(TreeNode* root, vector<int>& path, vector<string>& result) {
        path.push_back(root->val);
        if (root->left==nullptr && root->right==nullptr) {
          string path_str{};
          for (int i=0; i<path.size()-1; i++) {
            path_str +=  to_string(path[i])+"->" ;
          }
          path_str += to_string(path.back());
          result.push_back(path_str);
          return;
        }

        if (root->left) {
            getPath(root->left, path, result);
            path.pop_back();
        }
        if (root->right) {
            getPath(root->right, path, result);
            path.pop_back();
        }
        return;
    }
};
// @lc code=end

