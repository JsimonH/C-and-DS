/*Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
*/


int TreeSize(struct TreeNode* root)
{
    if(root == NULL) return 0;
    return 1+TreeSize(root->left)+TreeSize(root->right);
}

void preOrder(struct TreeNode* root, int* ret, int* pi)
{
    if(root == NULL) return;
    ret[(*pi)++] = root->val;
    preOrder(root->left, ret, pi);
    preOrder(root->right, ret, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int* ret=malloc(sizeof(int)*size);
    *returnSize = size;

    int i = 0;
    preOrder(root, ret, &i);
    return ret;
}
