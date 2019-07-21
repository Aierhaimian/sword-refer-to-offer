#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    TreeNode *convert(TreeNode *root)
    {
        TreeNode *pLastNodeInList = nullptr;
        convertNode(root, &pLastNodeInList);

        // pLastNodeInList指向双向链表的尾节点
        // 我们需要返回头节点
        TreeNode *pHeadOfList = pLastNodeInList;
        while (pHeadOfList != nullptr && pHeadOfList->left != nullptr)
            pHeadOfList = pHeadOfList->left;

        return pHeadOfList;
    }

private:
    void convertNode(TreeNode *root, TreeNode **pLastNodeInList)
    {
        if (root == nullptr)
            return;

        TreeNode *curNode = root;

        // left
        if (root->left != nullptr)
            convertNode(root->left, pLastNodeInList);

        // root
        curNode->left = *pLastNodeInList;
        if (*pLastNodeInList != nullptr)
            (*pLastNodeInList)->right = curNode;

        *pLastNodeInList = curNode;

        // right
        if (root->right != nullptr)
            convertNode(root->right, pLastNodeInList);
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

