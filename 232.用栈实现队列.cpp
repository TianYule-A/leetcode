/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;
class MyQueue {
  stack<int> s_in;
  stack<int> s_out;
public:
    MyQueue() {
    
    }
    
    void push(int x) {
        s_in.push(x);
    }
    
    int pop() {
        if (s_out.empty()) {
          while (!s_in.empty()) {
            s_out.push(s_in.top());
            s_in.pop();
          }
        }
        int x = s_out.top();
        s_out.pop();
        return x;
    }
    
    int peek() {
        if (s_out.empty()) {
          while (!s_in.empty()) {
            s_out.push(s_in.top());
            s_in.pop();
          }
        }
        int x = s_out.top();
        return x;
    }
    
    bool empty() {
        if (s_out.empty() && s_in.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

