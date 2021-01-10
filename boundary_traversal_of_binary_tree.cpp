// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> printBoundary(Node *root);

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int>arr,right_arr;
int max_hgt,flag;
unordered_map <Node*,int>mp;

void left_boundary(Node *root)
{
    if(root==NULL)
        return ;
    
    if(root->left) {
        
        arr.push_back(root->data);
        left_boundary(root->left);
    }
    else if(root->right) {
        
        arr.push_back(root->data);
        left_boundary(root->right);
    }
    
}

void leaf_nodes(Node *root)
{   
    if(root==NULL)
        return ;
        
    leaf_nodes(root->left);
    
    if(root->left==NULL && root->right == NULL) {     
        arr.push_back(root->data);   
    }
        
    leaf_nodes(root->right);
}

void right_boundary(Node *root)
{
    if(root==NULL)
        return ;
    
    if(root->right) {
        
        right_boundary(root->right);
        arr.push_back(root->data);
    }  
    
    else if(root->left) {
        
        right_boundary(root->left);
        arr.push_back(root->data);
    }
     
}

vector <int> printBoundary(Node *root)
{
    
    arr.clear();  
    
    if(root==NULL)
        return arr;
        
    arr.push_back(root->data);

    // because of left or right skewed trees only we have to solve  root->left and root->right separately. 
    left_boundary(root->left); 
    
    leaf_nodes(root->left);
    leaf_nodes(root->right);
    
    right_boundary(root->right);
    
    return arr;
}