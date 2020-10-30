/*  
    for Rotations and code refer
    https://www.geeksforgeeks.org/avl-tree-set-1-insertion

*/
#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}

Node* insertToAVL( Node* node, int data);

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        
        for(int i=0; i<n; i++)
        {
            root = insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}// } Driver Code Ends


/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

int height(Node *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}

int get_balance(Node *root)
{
    if(root==NULL)
        return 0;
    return height(root->left) - height(root->right);
}

Node *RightRotate(Node *z)
{   
    /*  No need check null condition ,we come here z in not null */
    //if(z==NULL) 
    //    return NULL;

    Node *y = z->left;
    Node *T3 = y->right;

    y->right = z;
    z->left = T3;
    
    // important order of updating heights also important
    z->height = 1 + max(height(z->left),height(z->right)); 
    y->height = 1 + max(height(y->left),height(y->right));
    
    return y;
}

Node *LeftRotate(Node *z)
{
    /*  No need check null condition ,we come here z in not null */
    //if(z==NULL)
    //    return NULL;

    Node *y = z->right;
    Node *T2 = y->left;

    y->left = z;
    z->right = T2;
    
    // important order of updating heights also important
    z->height = 1 + max(height(z->left),height(z->right)); 
    y->height = 1 + max(height(y->left),height(y->right));

    return y;
}


Node* insertToAVL(Node* root,int data)
{
    if(root==NULL)
        return new Node(data);
    if(data<root->data)
        root->left = insertToAVL(root->left,data);
    if(data>root->data)
        root->right = insertToAVL(root->right,data);
    if(data==root->data)  // duplicate values not allowed
        return root;
        
    //update heights
    root->height = 1 + max(height(root->left),height(root->right));

    int balance = get_balance(root);

    /* 
        we should use else if ladder (if we don't use else if ladder after executing first if ,it changes tree structure ),
        now modified tree also satisfies second if, because of change in structure  
        (OR) Instead of  we can return immediately. 
    */
    //LL case
    if(balance>1 && data<root->left->data)
    {
        root = RightRotate(root);
    }

    //LR case
    else if(balance>1 && data>root->left->data)
    {
        root->left = LeftRotate(root->left);
        root = RightRotate(root);
    }

    //RR case
    else if(balance<-1 && data>root->right->data)
    {
        root = LeftRotate(root);
    }

    //RL case
    else if(balance<-1 && data<root->right->data)
    {
        root->right = RightRotate(root->right);
        root = LeftRotate(root);
    }

    return root;
}


