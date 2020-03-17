/*Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
*/


int TreeSize(struct TreeNode* root)
{
    if(root == NULL) return 0;
    return 1+TreeSize(root->left)+TreeSize(root->right);
}

void postOrder(struct TreeNode* root, int* ret, int* pi)
{
    if(root == NULL) return;
 
    postOrder(root->left, ret, pi);
    postOrder(root->right, ret, pi);
    ret[(*pi)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int size = TreeSize(root);
    int* ret=malloc(sizeof(int)*size);
    *returnSize = size;

    int i = 0;
    postOrder(root, ret, &i);
    return ret;
}
