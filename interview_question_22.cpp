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
        :data(x), next(nullpt) {}
};

// Two Points -> 快慢指针
// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    ListNode* findKthToTail(ListNode* head, unsigned int k) {
        if (head == nullptr || k == 0) // 如果输入链表为空
            return nullptr;            // 或者k为0，由于k是无符号数，k-1 != -1
                                       // 而是0xFFFFFFFF
        
        ListNode *pFirst = head;
        ListNode *pSecond = nullptr;
        for (int i=0; i<k-1; i++) {
            if (pFirst->next == nullptr) // 如果链表长度小于k
                return nullptr;
            pFirst = pFirst->next;
        }

        pSecond = head;
        while (pFirst->next != nullptr) {
            pFirst = pFirst->next;
            pSecond = pSecond->next;
        }
        return pSecond;
    }
};

int main()
{

    return 0;
}

