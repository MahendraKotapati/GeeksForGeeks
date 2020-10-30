// { Driver Code Starts
#include<bits/stdc++.h>
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


 // } Driver Code Ends


/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class solver
{
private:



public:

    void DistanceNodesDown(Node *root,int lvl,int k,vector<int>&arr)
    {
        if(root==NULL)
            return ;
        
        if(lvl==k)
            arr.push_back(root->data);
        DistanceNodesDown(root->left,lvl+1,k,arr);
        DistanceNodesDown(root->right,lvl+1,k,arr);
    }

    int KDistanceNodesUtil(Node *root,int target,int k,vector<int>&arr)
    {
        if(root==NULL)
            return -1;
        
        if(target==root->data) {
            DistanceNodesDown(root,0,k,arr);
            return 0;
        }
        
        int ld = KDistanceNodesUtil(root->left,target,k,arr);

        if(ld!=-1) // if node found on left subtree
        {
            if(1+ld==k)
                arr.push_back(root->data);
            else  
                DistanceNodesDown(root->right,0,k-(ld+1)-1,arr);   // if node is in left subtree and from target to curr_root distance<k 
                //so, from curr_root we can go to other end(right substree) , which have nodes at distance k from target ,but from curr_root distance is k- (ld+1)
                // similarly , from curr_root->right is k-(ld+1)-1; 
            
            return 1+ld;
        }

        int rd = KDistanceNodesUtil(root->right,target,k,arr);

        if(rd!=-1)  //  // if node found on right subtree
        {
            if(1+rd==k)
                arr.push_back(root->data);
            else  
                DistanceNodesDown(root->left,0,k-(rd+1)-1,arr);
            return 1+rd;
        }

        return -1;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int>arr;
        KDistanceNodesUtil(root,target,k,arr);
        sort(arr.begin(),arr.end());

        return arr;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    solver x = solver();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends


  /*

1
20 8 22 4 12 N N N N 10 14
8
2


  */