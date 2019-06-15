#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = peek();
        stk_out.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        if (stk_out.empty()) {
            while (!stk_in.empty()) {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
            return stk_out.top();
        }
        return stk_out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if (stk_in.empty() && stk_out.empty())
            return true;
        return false;
    }
private:
    stack<int> stk_in;
    stack<int> stk_out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{

    return 0;
}

