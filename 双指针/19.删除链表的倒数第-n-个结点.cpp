/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 ListNode* removeNthFromEnd(ListNode* head, int n) {
   // 使用虚拟头节点
   ListNode* dummyHead =new ListNode(0);
   dummyHead->next=head;
      ListNode* slow = dummyHead;
      ListNode* fast = dummyHead;
      while (n--) {
        fast = fast->next;
      }
      while (fast->next!=nullptr) {
        fast = fast->next;
        slow=slow->next;
      }
      ListNode* temp=slow->next;
      slow->next = temp->next;
      delete temp;
      ListNode* res = dummyHead->next;
      delete dummyHead;
      return res;

    }
};
// @lc code=end

