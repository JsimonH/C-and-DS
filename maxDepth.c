/*Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
*/

int maxDepth(struct TreeNode* root){
    if(root == 0) return 0;
    int heightLeft=1,heightRight=1;
    if(root->left)
        heightLeft+=maxDepth(root->left);
    if(root->right)
        heightRight+=maxDepth(root->right);
    return heightLeft>heightRight?heightLeft:heightRight;
}
