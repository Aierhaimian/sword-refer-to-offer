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

class Solution {
public:
    void deleteDuplication(ListNode **head) {
        if (head == nullptr || *head == nullptr)
            return;

        ListNode *preNode = nullptr;
        ListNode *pNode = *head;
        while (pNode != nullptr) {
            ListNode *pNext = pNode->next;
            // 当前节点与下一个节点重复
            if (pNext != nullptr && pNode->data == pNext->data) {
                int val = pNode->data;
                ListNode *delNode = pNode;
                while (delNode != nullptr && delNode->data == val) {
                    pNext = delNode->next;

                    delete delNode;
                    delNode = nullptr;

                    delNode = pNext;
                }

                if (preNode == nullptr)
                    *head = pNext;
                else
                    preNode->next = pNext;
                pNode = pNext;
            }
            else {
                preNode = pNode;
                pNode = pNext;
            }
        }
    }
};

int main()
{

    return 0;
}

