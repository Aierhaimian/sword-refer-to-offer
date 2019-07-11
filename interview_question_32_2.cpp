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
// 从上到下按层打印二叉树
// 同一层的节点按从左到右的顺序打印
// 每一层打印一行
class Solution{
public:
    void printFromTopToBottom(TreeNode *root)
    {
        if (!root)
            return;

        queue<TreeNode *> que;
        que.push(root);
        int nextLevel = 0; // 下一层节点的数目
        int toBePrinted = 1; // 当前层中将要打印的节点数
        while(!que.empty())
        {
            TreeNode *curNode = que.front();
            if (toBePrinted == 1) // 打印格式控制
                cout << curNode->val;
            else
                cout << curNode->val << " ";

            if (curNode->left)
            {
                que.push(curNode->left);
                ++nextLevel;
            }
            if (curNode->right)
            {
                que.push(curNode->right);
                ++nextLevel;
            }

            que.pop();
            --toBePrinted;
            if (!toBePrinted)
            {
                cout << endl;
                toBePrinted = nextLevel;
                nextLevel = 0;
            }
        }
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

