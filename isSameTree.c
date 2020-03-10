/*Same Tree
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true


Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
*/



bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL)
    return true;
    
    if(p == NULL || q == NULL)
    return false;

    if(p->val != q->val)
    return false;
    
    return isSameTree(p->left, q->left)
      && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){    
    return isSameTree(s, t)
        || isSameTree(s->left, t)
        || isSameTree(s->right, t);
}
