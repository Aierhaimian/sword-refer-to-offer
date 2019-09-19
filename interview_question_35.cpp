#include <iostream>

using namespace std;

struct ComplexNode {
    int m_nValue;
    ComplexNode *m_pNext;
    ComplexNode *m_pSibling;
    ComplexNode(int value)
        :m_nValue(value), m_pNext(nullptr), m_pSibling(nullptr) {}
};

// i.   根据原始链表的每个节点N创建对应的N'，并将N'链在N的后面;
// ii.  设置复制出来的m_pSibling，由于i的设置，我们可以在O(1)时间复杂度内设置新的m_pSibling
// iii. 再将N和N'分开即可得到原始链表和新链表。

// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution{
public:
    ComplexNode *clone(ComplexNode *pHead) {
        if (!pHead)
            return pHead;

        cloneNode(pHead);

        connectSibling(pHead);

        ComplexNode *clonedHead = reconnectNode(pHead);

        return clonedHead;
    }
private:
    void cloneNode(ComplexNode *pHead)
    {
        ComplexNode *pNode = pHead;
        while (pNode != nullptr)
        {
            ComplexNode *pCloned = new ComplexNode(pNode->m_nValue);
            pCloned->m_pNext = pNode->m_pNext;
            pNode->m_pNext = pCloned;

            pNode = pCloned->m_pNext;
        }
    }

    void connectSibling(ComplexNode *pHead)
    {
        ComplexNode *pNode = pHead;
        while (pNode != nullptr)
        {
            ComplexNode *pCloned = pNode->m_pNext;
            if (pNode->m_pSibling != nullptr)
                pCloned->m_pSibling = pNode->m_pSibling->m_pNext;

            pNode = pCloned->m_pNext;
        }
    }

    ComplexNode *reconnectNode(ComplexNode *pHead)
    {
        ComplexNode *pNode = pHead;
        ComplexNode *pClonedHead = nullptr;
        ComplexNode *pClonedNode = nullptr;

        if (pNode != nullptr)
        {
            pClonedHead = pClonedNode = pNode->m_pNext;
            pNode->m_pNext = pClonedNode->m_pNext;
            pNode = pNode->m_pNext;
        }

        while (pNode != nullptr)
        {
            pClonedNode->m_pNext = pNode->m_pNext;
            pClonedNode = pNode->m_pNext;

            pNode->m_pNext = pClonedNode->m_pNext;
            pNode = pClonedNode->m_pNext;
        }

        return pClonedHead;
    }

    void buildingNodes(ComplexNode *pNode, ComplexNode *pNext, ComplexNode *pSibling)
    {
        if (pNode != nullptr)
        {
            pNode->m_pNext = pNext;
            pNode->m_pSibling = pSibling;
        }
    }

    void printList(ComplexNode *pHead)
    {
        ComplexNode *pNode = pHead;
        while(pNode != nullptr)
        {
            cout << "The value of this node is: " << pNode->m_nValue << endl;
            if (pNode->m_pSibling != nullptr)
                cout << "The value of its sibling is: " << pNode->m_pSibling->m_nValue << endl;
            else
                cout << "This node does not have a sibling." << endl;
            cout << endl;

            pNode = pNode->m_pNext;
        }
    }
};


int main()
{
    return 0;
}

