// { Driver Code Starts
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
    do{
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

/*Node *rec(Node **root,Node *par,int flag)
{
    if(root==NULL) return *root;

    if(flag==0)  // means root
    {
        (*root)->left = rec(&(*root)->left,*root,-1);
        (*root)->right = rec(&(*root)->right,*root,1);
    }
    else if(flag==-1)  // left child 
    {
        (*root)->left = rec(&(*root)->left,*root,-1);
        (*root)->right = par;
    }
    else    // right child
    {
        (*root)->left = par;
        (*root)->right =rec(&(*root)->right,*root,1);
    }

    return (flag==-1)? (*root)->right : (*root)->left;

}
*/


Node *rec(Node *root,Node *par,int flag)
{
    if(root==NULL) return root;

    if(root->left==NULL && root->right==NULL)
    {     
        (flag==-1)? root->right = par : root->left = par;
        return root;
    }    

    if(flag==0)  // means root
    {
        root->left = rec(root->left,root,-1);
        root->right = rec(root->right,root,1);
    }
    else if(flag==-1)  // left child 
    {
        root->left = rec(root->left,root,-1);
        root->right = par;
    }
    else    // right child
    {
        root->left = par;
        root->right =rec(root->right,root,1);
    }

    return (flag==-1)? root->right : root->left;

}

void print(Node *root)
{
    Node *temp=root;

    while(temp!=NULL)
    {
        cout<<temp->data<<" "; temp = temp->right;
    }
}

Node *bTreeToCList(Node *root)
{
    Node *a;
    a = rec(&root,NULL,0);
    print(a);
    return a;
}