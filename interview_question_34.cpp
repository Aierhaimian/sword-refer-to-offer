#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        :val(x), left(nullptr), right(nullptr) {}
};

// 前序遍历
class Solution{
public:
    vector<vector<int>> findPath(TreeNode *root, int theValue)
    {
        res.clear();
        if(!root)
            return res;

        path.clear();
        generatePath(root, 0, theValue);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
    void generatePath(TreeNode *root, int curSum, int expSum)
    {
        curSum += root->val;
        path.push_back(root->val);

        // 如果是叶节点，并且路径上节点的值的和等于输入的值
        // 则将路径存入最终结果
        if (root->left == nullptr && root->right == nullptr && curSum == expSum)
        {
            res.push_back(path);
        }

        // 如果不是叶节点，则递归遍历它的子节点
        if (root->left)
            generatePath(root->left, curSum, expSum);
        if (root->right)
            generatePath(root->right, curSum, expSum);

        // 在返回父节点前，删除路径上的该节点
        path.pop_back();
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

