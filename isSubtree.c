/*Subtree of Another Tree

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a 
subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also 
be considered as a subtree of itself.

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
    //t和s的任意一棵子树进行比较
    if(s == NULL) return false;

    if(isSameTree(s,t)) return true;
    
    return isSubtree(s->left,t) || isSubtree(s->right,t);
}
