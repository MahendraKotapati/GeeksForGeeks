#include<bits/stdc++.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public: 
    bool find(TreeNode *root,TreeNode *node) {

        if(root==NULL)
            return false;

        if(root==node)
            return true;

        return find(root->left,node)||find(root->right,node);
    }

    
public:
    TreeNode *LCA(TreeNode *root,TreeNode *p,TreeNode *q) {
        
        if(root==NULL)
            return root;
        
        if(root->val>p->val && root->val>q->val)
            return LCA(root->left,p,q);
        else if(root->val<p->val && root->val<q->val)
            return LCA(root->left,p,q);
        
        return root;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
            TreeNode *lca = LCA(root,p,q);

            if(lca && find(lca,p) && find(lca,q))  // we use find because sometimes p,q nodes may not present in tree
                return lca;
            return NULL;
    }
};