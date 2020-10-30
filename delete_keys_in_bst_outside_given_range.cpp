 TreeNode* trimBST(TreeNode* root, int low, int high) {
       
        if(root==NULL)
            return root;   
        
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        
        if(root->val>=low && root->val<=high)   // if node is [low,high] return 
            return root;
        
        if(root->left==NULL)     // if one of substrees if null and curr node is outside range assign other substree (left or right)
            root = root->right;
        
        else if(root->right==NULL)
            root = root->left;
        else  // if both subtrees are not null and curr node out of range definately we have to discard one of subtrees because 
        {
            if( !(root->left->val>=low && root->left->val<=high) )
                root = root->right;
            else 
                root = root->left;
        }
        
        return root;
    }