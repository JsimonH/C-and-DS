/*Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3

*/

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

int isMirror(struct TreeNode* l_root, struct TreeNode* r_root)
{
    if (l_root == NULL && r_root == NULL) return true;
    if (l_root == NULL || r_root == NULL) return false;

    return    (l_root->val == r_root->val)   &&
           isMirror(l_root->left,  r_root->right) &&
           isMirror(l_root->right, r_root->left);
}
