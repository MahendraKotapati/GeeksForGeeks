/* https://www.youtube.com/watch?v=gcULXE7ViZw&vl=en   mycodeschool */
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



struct Node* deleteNode(struct Node* root, int key);

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
    Node* root1 = buildTree(s);
    getline(cin, s);
    int k = stoi(s);
    root1  = deleteNode(root1, k);
    vector<int> v;
    inorder(root1, v);
    for(auto i:v)
        cout << i << " ";
    cout << endl;
   }
   return 0;
} 

/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified BST after deleting the node with value X
 

Node * find_min(Node *root)
{
    while(root->left) root = root->left;
    return root;
}


Node *deleteNode(Node *root,  int key)
{   
    if(root==NULL) return NULL;

    if(root->data>key)
      root->left = deleteNode(root->left,key);

    else if(root->data<key)
      root->right = deleteNode(root->right,key);

    else  // if node to be deleted is found
    {
        if(root->left==NULL && root->right==NULL)  // if leaf child 
            return NULL;
        else if(root->left==NULL)  // if node has only right child;
        {
            root = root->right;
        }
        else if(root->right==NULL) // if node has only left child;
        {
            root = root->left;
        }
        else  // if node has two children;
        {
            Node *min_node = find_min(root->right);  // find min in right subtree 
            root->data = min_node->data;   // assign min->data to root->data;
            root->right = deleteNode(root->right,min_node->data);  // now ,delete min in right subtree of root;
        }

    }
    return root;
}


/*

2
2 1 3 N N N N
12
1 N 2 N 8 5 11 4 7 9 12
9

*/