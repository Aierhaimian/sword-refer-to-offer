#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(int x)
        :val(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

// 1. 如果一个节点有右子树，那么它的下一个节点就是它的右子树中
//    最左子节点；
// 2. 如果一个节点没有右子树：
//      a. 如果节点是它父节点的左子节点，那么它的下一个节点就是
//         它的父节点；
//      b. 如果一个节点既没有右子树，并且它还是它父节点的右子节
//         点，那么我们可以沿着指向父节点的指针一直向上遍历，直
//         到找到一个是它父节点的左子节点的节点，如果这样的节点
//         存在，那么这个节点的父节点就是我们要找的下一个节点。
class Solution {
public:
    TreeNode* getNext(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* pNext = nullptr;
        if (root->right != nullptr) {
            TreeNode* pRight = root->right;
            while (pRight->left != nullptr)
                pRight = pRight->left;
            pNext = pRight;
        }
        else if (root->parent != nullptr) {
            TreeNode* pCur = root;
            TreeNode* pParent = root->parent;
            while (pParent != nullptr && pCur == pParent->right) {
                pCur = pParent;
                pParent = pParent->parent;
            }
            pNext = pParent;
        }
        return pNext;
    }
};

int main()
{

    return 0;
}

