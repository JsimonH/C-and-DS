/*Invert Binary Tree

Invert a binary tree.

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9

Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL) return NULL;

    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
