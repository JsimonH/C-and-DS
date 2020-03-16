/*Binary Tree Traversal
编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉
树以后，再对二叉树进行中序遍历，输出遍历结果。

notice:输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。每个输出结果占一行。
*/

#include<stdio.h>
#include<malloc.h>

typedef struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* Rebuild(char* a, int* pi)
{
    if(a[*pi] == '#')
    {
        return NULL;
    }
    else
    {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = a[*pi];
        (*pi)++;
        root->left = Rebuild(a, pi);
        (*pi)++;
        root->right = Rebuild(a, pi);
        return root;
    }
}

void Inorder(TreeNode* root)
{
    if(root == NULL)
        return;
    Inorder(root->left);
    printf("%C ",root->val);
    Inorder(root->right);
}

int main()
{
    char arr[100];
    scanf("%s",arr);
    //重建二叉树
    int i = 0;
    TreeNode* root = Rebuild(arr,&i);
    //中序输出
    Inorder(root);
    return 0;
}
