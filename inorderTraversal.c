/*Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
*/


int TreeSize(struct TreeNode* root)
{
    if(root == NULL) return 0;
    return 1+TreeSize(root->left)+TreeSize(root->right);
}

void InOrder(struct TreeNode* root, int* ret, int* pi)
{
    if(root == NULL) return;
 
    InOrder(root->left, ret, pi);
    ret[(*pi)++] = root->val;
    InOrder(root->right, ret, pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int* ret=malloc(sizeof(int)*size);
    *returnSize = size;

    int i = 0;
    InOrder(root, ret, &i);
    return ret;
}
