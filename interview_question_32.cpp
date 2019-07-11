#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :val(x), left(nullptr), right(nullptr) {}
};

// BFS -> 基于队列
// 从上到下打印出二叉树的每个节点
// 同一层的节点按照从左到右的顺序打印
class Solution{
public:
    vector<int> printFromTopToBottom(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode *curNode = que.front();
            que.pop();
            res.push_back(curNode->val);

            if (curNode->left)
                que.push(curNode->left);
            if (curNode->right)
                que.push(curNode->right);
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

