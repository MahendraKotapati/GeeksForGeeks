#include<bits/stdc++.h>
using namespace std;

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

vector<int> inorder(struct Node *root);
vector<int> preorder(Node* root);

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


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector <int> res = inOrder(root);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}


vector<int> inorder(Node* root)   // Left -- Root -- Right
{
    Node *curr,*temp;
    vector <int>ans; stack <Node*>s;
    
    temp = root;
    
    while(temp!=NULL)  // traversing till left leaf node at the same time pushing into stack;  
        s.push(temp),temp=temp->left;
    
    while(!s.empty())
    {
        curr = s.top(); s.pop();
        ans.push_back(curr->data);
        
        // we already processed left substree  so move to right substree and repeat same.
        temp = curr->right;  // moving to right subtree

        while(temp!=NULL) 
            s.push(temp),temp = temp->left;
    }
    
    return ans;
}


vector <int> preorder(Node* root)    // Root --Left -- Right 
{
    vector <int>ans;  stack <Node*>s;
    Node *curr;
    s.push(root);
    
    while(!s.empty())
    {
        curr = s.top(); s.pop();

        ans.push_back(curr->data);

        if(curr->right!=NULL)
            s.push(curr->right);
            
        if(curr->left!=NULL)
            s.push(curr->left); // to process left substree first , we are pushing left substree last;
    }
    return ans;
  
}

vector <int> postOrder(Node* root) // Left-right-root
{
    Node *pre,*temp,*curr;
    stack <Node*>s;
    vector <int>ans;

    temp = root; pre = NULL;

    while(temp!=NULL)  // move towards left and push into stack
        s.push(temp),temp = temp->left;

    while(!s.empty())
    {
        curr = s.top();

        if(curr->right!=NULL && curr->right!=pre)  // if curr node has right substree and has not visited ( if visited then curr->right=pre )
        {   
            temp = curr->right;
            while(temp!=NULL) 
                s.push(temp),temp = temp->left;
        }
        else   // if there is no right substree or right substree is visited then pop curr (nothing but printing root)
        {
            pre = curr ; s.pop();
            ans.push_back(curr->data);
        }
    }
    
    return ans;
}