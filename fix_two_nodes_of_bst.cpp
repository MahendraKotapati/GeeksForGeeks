/*   
	https://leetcode.com/problems/recover-binary-search-tree/discuss/32535/No-Fancy-Algorithm-just-Simple-and-Powerful-In-Order-Traversal
    
  adj :  5 4  6 7 8 9
  apart: 4 5  9 7 8 6
*/

class Solution {
    
TreeNode *pre,*first,*second;    

public:
    void recoverTree(TreeNode *root)
    {
        if(root==NULL) return ;
        pre = new TreeNode(INT_MIN);
        first = second = NULL;
        recoverTreeUtil(root);
    
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        
    }

public:
    void recoverTreeUtil(TreeNode* root) {
        
        if(root==NULL)
            return ;
        
        recoverTreeUtil(root->left);
        
        if(first==NULL && pre->val>root->val)  // see ex2 9 6 
            first = pre;
        
        if(first!=NULL && pre->val>root->val)  // see ex1 5 4
            second = root;
        
        pre = root;
        
        recoverTreeUtil(root->right);
    }
};
