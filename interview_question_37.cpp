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
    // 前序遍历——序列化
    void serialize(TreeNode *root, ostream &stream)
    {
        if (!root)
        {
            stream << "$,";
            return;
        }

        stream << root->val << ',';
        serialize(root->left, stream);
        serialize(root->right, stream);
    }

    // 反序列化
    void deserialize(TreeNode **root, istream &stream)
    {
        int number;
        if (readStream(stream, &number))
        {
            *root = new TreeNode(number);

            deserialize(&((*root)->left), stream);
            deserialize(&((*root)->right), stream);
        }
    }
private:
    // 每次从流中读出一个数字或者一个字符'$'
    // 当从流中读出一个数字时返回true，否则返回false
    bool readStream(istream& stream, int* number)
    {
        if(stream.eof())
            return false;

        char buffer[32];
        buffer[0] = '\0';

        char ch;
        stream >> ch;
        int i = 0;
        while(!stream.eof() && ch != ',')
        {
            buffer[i++] = ch;
            stream >> ch;
        }

        bool isNumeric = false;
        if(i > 0 && buffer[0] != '$')
        {
            *number = atoi(buffer);
            isNumeric = true;
        }

        return isNumeric;
    }
};

int main()
{
    return 0;
}

