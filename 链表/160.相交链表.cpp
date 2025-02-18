/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
#include <cmath>
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pa = headA;
        ListNode *pb = headB;
        int lenA=0, lenB = 0;
        while (pa != nullptr)
        {
            pa = pa->next;
            lenA++;
        }
        while (pb != nullptr)
        {
            pb = pb->next;
            lenB++;
        }
        int diff = std::abs(lenA - lenB);
        pa = headA;
        pb = headB;
        if (lenA > lenB)
        {
            while (diff > 0)
            {
                pa = pa->next;
                diff--;
            }
        }
        else
        {
            while (diff > 0)
            {
                pb = pb->next;
                diff--;
            }
        }
        while (pa != nullptr && pb != nullptr)
        {
            if (pa == pb)
            {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
        }
        return nullptr;
    }
};
// @lc code=end
