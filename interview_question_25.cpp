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

// 迭代法
class Solution1 {
public:
    ListNode *listMerge(ListNode *head1, ListNode *head2) {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;

        ListNode *p1 = head1;
        ListNode *p2 = head2;
        ListNode *newHead;
        if (p1->data < p2->data) {
            newHead = p1;
            p1 = p1->next;
        }
        else {
            newHead = p2;
            p2 = p2->next;
        }

        ListNode *p = newHead;
        while (p1 && p2) {
            if (p1->data < p2->data) {
                p->next = p1;
                p1 = p1->next;
            }else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }

        while (p1) {
            p->next = p1;
            p = p->next;
            p1 = p1->next;

        }

        while (p2) {
            p->next = p2;
            p = p->next;
            p2 = p2->next;
        }
        return newHead;
    }
};

// 递归法
class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode *newHead = nullptr;
        if (l1->data < l2->data) {
            newHead = l1;
            newHead->next = mergeTwoLists(l1->next, l2);
        }else {
            newHead = l2;
            newHead->next = mergeTwoLists(l1, l2->next);
        }

        return newHead;
    }
};

int main()
{

    return 0;
}

