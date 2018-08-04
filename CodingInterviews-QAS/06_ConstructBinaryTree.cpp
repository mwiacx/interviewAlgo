/*
 * 心情不好
 * 抄的，改日再写。
 *
 */
#include <iostream>

struct BinaryTreeNode
{
    int             val;
    BinaryTreeNode  *left;
    BinaryTreeNode  *right;
}

BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0)
        return NULL;

    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryTreeNode *ConstructCore(int *startPreorder,
        int *endPreorder,
        int *startInorder,
        int *endInorder)
{
    // 前序遍历的第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->val = rootValue;
    root->left = root->right = NULL;

    // 叶子节点
    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *startInorder
            return root;
        else
            throw std::exception("Invalid input.");
    }

    //在中序遍历中找到根节点的值
    int *rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        rootInorder++;

    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception("Invalid input.");

    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0)
    {
        // 构建左子树
        root->left = ConstructCore(startPreorder+1,
                leftPreorderEnd, startInorder, rootInorder-1);
    }
    if (leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->right = ConstructCore(leftPreorderEnd+1,
                endPreorder, rootInorder+1, endInorder);
    }

    return root;
}
