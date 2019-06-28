#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

struct TreeNode{
    double val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(double x)
        :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasSubTree(TreeNode *tree1, TreeNode *tree2) {
        bool res = false;
        if (!tree1 && !tree2) {
            if (isEqual(tree1->val, tree2->val))
                res = doesTree1HaveTree2(tree1, tree2);
            if (!res)
                res = hasSubTree(tree1->left, tree2);
            if (!res)
                res = hasSubTree(tree1->right, tree2);
        }
        return res;
    }
private:
    bool doesTree1HaveTree2(TreeNode *tree1, TreeNode *tree2) {
        if (!tree2)
            return true;
        if (!tree1)
            return false;

        if (!isEqual(tree1->val, tree2->val))
            return false;

        return doesTree1HaveTree2(tree1->left, tree2->left) && doesTree1HaveTree2(tree1->right, tree2->right);
    }

    bool isEqual(double x, double y) {
        return ((x-y) > -0.0000001) && ((x-y) < 0.0000001);
    }

};

int main()
{

    return 0;
}

