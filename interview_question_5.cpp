#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x), next(nullptr) {}
};

// 假设单链表带头结点
class Solution {
public:
    void printListReversingly_Iteratively(ListNode* head) {
        stack<ListNode*> stk;

        ListNode* p = head;
        while (p->next != nullptr) {
            stk.push(p->next);
            p = p->next;
        }

        while (!stk.empty()) {
            ListNode* tmp = stk.top();
            cout << tmp->val << endl;
            stk.pop();
        }
    }

    void printListReversingly_Recursively(ListNode* head) {
        reverseList(head->next);
    }
private:
    void reverseList(ListNode* head) {
        if (head != nullptr && head->next != nullptr)
            reverseList(head->next);
        cout << head->val << endl;
    }
};

int main()
{
    return 0;
}

