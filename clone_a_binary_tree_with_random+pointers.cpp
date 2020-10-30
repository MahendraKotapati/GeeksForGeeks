
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};


Node *cloneTree(Node *);
int printInorder(Node* a,Node *b)
{
    if ((a==NULL and b==NULL) or (a->random==NULL and b->random==NULL))
        return 1;

    if(a->random->data == b->random->data and printInorder(a->left,b->left) and printInorder(a->right,b->right))
        return 1;
    return false;

}

void inorder_r(Node *root)
{
    if (root == NULL)
       return;
    if(root->left == NULL && root->right == NULL)
        root = NULL;
    inorder_r(root->left);
    //cout << root->data << " ";
    /*if(root->random)
        cout<<"random:"<<root->random->data<<" ";
    else  
        cout<<"NULL"<<" ";
    */
    cout<<"check";
    inorder_r(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
     
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }


     }

     Node *t = cloneTree(root);
      if(t==root)
        cout<<0<<endl;
     else
     cout<<printInorder(root,t);
     cout<<endl;
  }
  return 0;
}



Node* cloneTree(Node* tree);
// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

/* The function should clone the passed tree and return 
   root of the cloned tree */

Node  *create_clone_nodes(Node **root)
{
    if(*root==NULL)
        return NULL;
  
    create_clone_nodes(&(*root)->left);

    Node *clone_root = (Node *)malloc(sizeof(Node));
    clone_root->data = (*root)->data;
    clone_root->left = (*root)->left;
    (*root)->left = clone_root; 
   
    Node *clone_root_right  =  create_clone_nodes(&(*root)->right);
    
    clone_root->right = clone_root_right;
    clone_root->random = NULL;
    return clone_root;
   
}

Node *copy_random(Node *root)
{
    if(root==NULL)
        return NULL;
    
    if(root->left)
    {
        root->left->random = (root->random) ? root->random->left : NULL ;
        root->left->left = copy_random(root->left->left);
    }
    
    root->right = copy_random(root->right);

    return root;
    
}

void restore_tree(Node *root)
{
    if(root==NULL)
        return ;

    if(root->left)
    {    root->left = root->left->left;
        restore_tree(root->left);
    }    
    restore_tree(root->right);

    //return root;
}


Node* cloneTree(Node* tree)
{

   
    Node *clone_root = create_clone_nodes(&tree);
   
    tree = copy_random(tree);
    restore_tree(tree);  
    //restore_tree(clone_root);
    //if(clone_root == tree->left)  cout<<"check";
    inorder_r(tree);  cout<<"\n"; 
    if(tree==NULL)  cout<<"is null";
    inorder(tree); 
    
 
    
    return clone_root;  

}
