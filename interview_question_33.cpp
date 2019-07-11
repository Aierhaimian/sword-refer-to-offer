#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool isBST(vector<int> seq) {
        return verifySquenceOfBST(seq, 0, seq.size());
    }
private:
    bool verifySquenceOfBST(const vector<int> &seq, int left, int right) {
        if (!seq.size() || right <= 0)
            return false;

        // 首先找到树的根节点
        int root = seq[right - 1];

        // 在BST中左子树的值小于根节点的值
        int i = 0;
        for(; i<right-1; ++i)
        {
            if (seq[i] > root)
                break;
        }

        // 在BST中右子树节点的值大于根节点
        int j = i;
        for(; j<right-1; ++j)
        {
            if (seq[j] < root)
                return false; // 相对于根节点的右子树中的节点不能小于根节点
        }

        // 判断左子树是不是BST
        bool isLeftBST = true;
        if (i>0)
            isLeftBST = verifySquenceOfBST(seq, 0, i);

        // 判断右子树是不是BST
        bool isRightBST = true;
        if (i < right - 1)
            isRightBST = verifySquenceOfBST(seq, i, right-i-1);

        return isLeftBST && isRightBST;
    }
};

int main()
{
    vector<int> arr1 = {4,8,6,12,16,14,10};
    vector<int> arr2 = {4,6,7,5};
    vector<int> arr3 = {1,2,3,4,5};
    vector<int> arr4 = {5,4,3,2,1};
    vector<int> arr5 = {5};
    vector<int> arr6 = {7,4,6,5};
    vector<int> arr7 = {4,6,12,8,16,14,10};
    vector<int> arr8 = {};
    cout << Solution().isBST(arr1) << endl;
    cout << Solution().isBST(arr2) << endl;
    cout << Solution().isBST(arr3) << endl;
    cout << Solution().isBST(arr4) << endl;
    cout << Solution().isBST(arr5) << endl;
    cout << Solution().isBST(arr6) << endl;
    cout << Solution().isBST(arr7) << endl;
    cout << Solution().isBST(arr8) << endl;
    return 0;
}

