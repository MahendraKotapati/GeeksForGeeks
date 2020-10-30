/*  https://www.youtube.com/watch?v=FsxTX7-yhOw */
#include <bits/stdc++.h>
using namespace std;

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


Node *bTreeToCList(Node *root);
void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;

    } while (head!=itr);
    cout <<endl;

    itr=itr->left;
    do
    {
        cout<<itr->data<<" ";
        itr=itr->left;
    }while(head!=itr);
    cout<<itr->data<<endl;
}

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
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Node *head = bTreeToCList(root);
        displayCList(head);
    }
    return 0;
}
// } Driver Code Ends

/*Complete the function below
Node is as follows:
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

Node *simpleTreeToList(Node *root)
{
    Node *head;

    if(root==NULL)
        return root;

    if(root->left==NULL && root->right==NULL)
        return root;
    
    if(root->left==NULL)
    {   
        head = root;
        head->left = NULL;
        head->right = root->right;
    }
    else if(root->right==NULL)
    {   
        head = root->left;
        head ->left = root;
        head ->right = NULL;
    }
    else   
    {
        head = root->left;
        head ->left = root;
        head ->right = root->right;
    }
    return head->right;
}

/*   
     1
   /   \
  2     3

  2->1->3

 */

Node *pre;

void btree_to_list(Node *root,Node **head)
{

    if(root==NULL)
        return ;
        
    btree_to_list(root->left,head); 
    
    if(pre==NULL)
        *head = root;        
    else   
    {   
        root->left = pre;
        pre->right = root;
    }
    pre = root;
    btree_to_list(root->right,head);
} 

Node* bTreeToCList(Node *root)
{   
    /* convert btree to circulardouble linked list use left and right pointers as prev and next pointers  */  
    if(root==NULL)
        return NULL;
        
    Node *head; pre = NULL;
    btree_to_list(root,&head);
    
    Node *temp = head;
    
    while(temp->right!=NULL)   // moving till end of list
        temp = temp->right;
    
    temp->right = head;   // making list circular 
    head->left = temp;    // in cicular dll head->prev points tail
    
    return head;
}
