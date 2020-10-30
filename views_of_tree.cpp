void left_view(Node *root,int curr_lvl,int &level)
{   
    if(root==NULL)
        return ;
    if(curr_lvl==level){
        cout<<root->data<<" ";
        level++;
    }
        
    left_view(root->left,curr_lvl+1,level);
    left_view(root->right,curr_lvl+1,level);
}

void leftView(Node *root)
{
    int level=0;
    left_view(root,0,level);
}
