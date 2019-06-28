#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int x)
        :data(x), next(nullptr) {}
};

// 迭代的方法
class Solution1 {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *reversedHead = nullptr;

        ListNode *preNode = nullptr;
        ListNode *curNode = head;
        while (curNode != nullptr) {
            ListNode *pNext = curNode->next;
            if (pNext == nullptr)
                reversedHead = curNode;
            
            curNode->next = preNode;

            preNode = curNode;
            curNode = pNext;
        }
        return reversedHead;
    }
};

// 递归的方法
class Solution2 {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *reversedHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return reversedHead;
    }
};

int main()
{

    return 0;
}

