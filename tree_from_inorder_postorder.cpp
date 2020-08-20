// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays

Node * construct(int l,int r,int idx,int in[],int post[],int n)
{   
    
    if(l>r)
        return NULL;

    int curr_root = post[idx],curr_idx;    
   
    Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = curr_root;
    node->left = node->right = NULL;
    
    int curr_l=l;  
    while(curr_l<n && in[curr_l]!=curr_root)  // search for curr_root in inorder array 
        curr_l++;
    

    curr_idx = (idx-(r-curr_l+1));
    node->left = construct(l,curr_l-1,curr_idx,in,post,n);
    curr_idx =  idx-1 ;
    node->right = construct(curr_l+1,r,curr_idx,in,post,n);

    return node;
}


Node *buildTree(int in[], int post[], int n) {
    
    return construct(0,n-1,n-1,in,post,n);  // (l,r,curr_root,root,in,post,n,child);
        
}


/*
2
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1
5
9 5 2 3 4
5 9 3 4 2



1
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1

*/