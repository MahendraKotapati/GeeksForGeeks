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

bool v1,v2;

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
        
       TreeNode *l = LCA(root->left,p,q);
       TreeNode *r = LCA(root->right,p,q);
        
        if((root==p || root==q))
        {
            v1 = (root==p); v2 = (root==q);  
            return root;
        }    
    
        else if(l&&r)
            return root;
        
        return (l)? l: r;
        
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     
        v1 = v2 = false;  // v1,v2 is true if p,q is present in tree respectively
        TreeNode *lca = LCA(root,p,q);
        // if if p is root and q is some node then v1 is true but v2 is false (because we return immediately) but q may be present below p 

        if( (v1 && v2) || (v1 && find(lca,q)) || (v2 && find(lca,p)) )  // instead of doing these find LCA then find whether p,q present in tree or not.
            return root;
        return NULL;
    }
};