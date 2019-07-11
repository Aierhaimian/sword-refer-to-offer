#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :val(x), left(nullptr), right(nullptr) {}
};

// BFS -> 基于队列
// 从上到下之字形按层打印二叉树
// 每一层打印一行
class Solution{
public:
    void printFromTopToBottom(TreeNode *root)
    {
        if (!root)
            return;

        queue<TreeNode *> que;
        stack<TreeNode *> stk;
        que.push(root);
        int nextLevel = 0; // 下一层节点的数目
        int toBePrinted = 1; // 当前层中将要打印的节点数
        bool isRightToLeft = false; // false时从左向右打印，true时从右向左打印
        while(!que.empty())
        {
            TreeNode *curNode = que.front();
            if (!isRightToLeft)
                cout << curNode->val << " ";
            else
                stk.push(curNode);

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
                while (!stk.empty())
                {
                    TreeNode *node = stk.top();
                    cout << node->val << " ";
                    stk.pop();
                }
                cout << endl;
                toBePrinted = nextLevel;
                nextLevel = 0;
                isRightToLeft = isRightToLeft ? false : true;
            }
        }
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

