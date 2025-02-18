/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<vector>
#include<algorithm>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::vector<ListNode *> p_list;
        ListNode *p = head;
        while (p!=nullptr)
        {
            p_list.push_back(p);
            p = p->next;
            if (std::find(p_list.begin(),p_list.end(),p)!=p_list.end())
            {
                return p;
            }
            
        }
        return nullptr;
    }
};
// @lc code=end

