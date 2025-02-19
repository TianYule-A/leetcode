/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>
using namespace std;
class MyStack {
  queue<int> s1;
  queue<int> s2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        s1.push(x);        
    }
    
    int pop() {
        
    }
    
    int top() {
        
    }
    
    bool empty() {
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

