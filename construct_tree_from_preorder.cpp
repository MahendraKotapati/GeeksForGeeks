// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed


struct Node *rec(struct Node *root,int n,int *i,int pre[],char preLN[])
{
    if(*i>=n)  return NULL;
    if(root==NULL)
    {   
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = pre[*i];
        root->left = root->right = NULL; 
        *i=*i+1;
        if(preLN[*i-1]=='N')
        {      
            root->left = rec(root->left,n,i,pre,preLN);
            root->right = rec(root->right,n,i,pre,preLN);
        }
    }
    return root;
}



struct Node *constructTree(int n, int pre[], char preLN[])
{   
    struct Node *root=NULL;
    int i=0; 
    return rec(root,n,&i,pre,preLN);
     
}