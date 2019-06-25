#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int x) :data(x), next(nullptr) {}
};

// 有个前提就是要删除的节点必须在链表中存在
// 摊还分析时间复杂度
// Time  Complexity: O(1)
// Space Complexity: O(1)
class Solution {
public:
    void deleteNode(ListNode **head, ListNode *delNode) {
        if (!head || !delNode) return;

        // 要删除的节点不是尾节点
        if (delNode->next != nullptr) {
            ListNode *pNext = delNode->next;
            delNode->data = pNext->data;
            delNode->next = pNext->next;
            delete pNext; // 释放指针指向的对象，指针还在
            pNext = nullptr; // 因此需要将指针指空，否则便成了野指针
        }
        // 链表只有一个节点，删除头节点（也就是尾节点）
        else if (*head == delNode) {
            delete delNode;
            delNode = nullptr;
            *head = nullptr;
        }
        // 链表中有多个节点，删除尾节点
        else {
            ListNode *pNode = *head;
            while (pNode->next != delNode)
                pNode = pNode->next;

            pNode->next = nullptr;
            delete delNode;
            delNode = nullptr;
        }
    }
};

int main()
{

    return 0;
}

