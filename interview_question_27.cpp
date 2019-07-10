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
    void mirrorRecursively(TreeNode *root) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            return;

        TreeNode *tmpNode = root->left;
        root->left = root->right;
        root->right = tmpNode;

        if (root->left)
            mirrorRecursively(root->left);
        if (root->right)
            mirrorRecursively(root->right);
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

