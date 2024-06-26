/*

we can also use inorder traversal 

class Solution {

public:
    bool isBST(TreeNode *root,long long int mini,long long int maxi) {
        
        if(root==NULL)
            return 1;
        
        if(root->val<mini || root->val>maxi)
            return 0;
        
        return isBST(root->left,mini,root->val-1) && isBST(root->right,root->val+1,maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        
        return isBST(root,LLONG_MIN,LLONG_MAX);
    }
};

*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    cout << isBST(root) << endl;
   }
   return 0;
}



 // } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return true if the given tree is a BST, else return false

bool isbst;

int is_bst(Node *root,int flag)
{   
    if(root==NULL)
        return (flag==-1)? -INT_MAX:INT_MAX;
    
    if(root->left==NULL && root->right==NULL)
        return root->data;
    
    
    int left = is_bst(root->left,-1);
    int right = is_bst(root->right,1);
    
  
    if(root->data<=left || root->data>=right)
        isbst = false;
    
    int ans=root->data;
    
    if(flag==-1)   // if left
    {   
        if(right!=INT_MAX) ans = max(ans,right);
        ans = max(ans,left);
    }
    else     // if right
    {
        if(left!=-INT_MAX) ans = min(ans,left);
        ans = max(ans,right);
    }
    
    return ans;
        
}


bool isBST(Node* root) {
    
    isbst = true;
    is_bst(root,0);

    return isbst;
}

