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
    ListNode *entryNodeLoop(ListNode *head) {

        // 判断链表是否有环
        ListNode *meetingNode = meeting(head);
        if (meetingNode == nullptr)
            return nullptr;

        // 得到链表环中节点的数目
        int loopNodeNum = 1;
        ListNode *pNode = meetingNode;
        while (pNode->next != meetingNode) {
            pNode = pNode->next;
            ++ loopNodeNum;
        }

        // 先移动快指针，移动距离等于链表环中节点数目
        ListNode *pFast = head;
        for (int i=0; i<loopNodeNum; ++i)
            pFast = pFast->next;

        // 再移动快慢指针直至两者相遇
        ListNode *pSlow = head;
        while (pFast != pSlow) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pFast;
    }
private:
    ListNode *meeting(ListNode *head) {
        if (head == nullptr)
            return nullptr;

        ListNode *pSlow = head->next;
        if (pSlow == nullptr)
            return nullptr;
        ListNode *pFast = pSlow->next;
        while (pFast != nullptr && pSlow != nullptr) {
            if (pFast == pSlow)
                return pFast;

            pSlow = pSlow->next;

            pFast = pFast->next;
            if (pFast != nullptr)
                pFast = pFast->next;
        }
        return nullptr;
    }
};

int main()
{

    return 0;
}

