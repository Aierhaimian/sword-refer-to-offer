#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    bool isSymmetrical(TreeNode *root) {
        return isSym(root, root);
    }
private:
    bool isSym(TreeNode *root1, TreeNode *root2){
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val != root2->val)
            return false;
        return isSym(root1->left, root2->right) && isSym(root1->right, root2->left);
    }

};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

