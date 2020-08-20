// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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
            // Create the left child for the current Node
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

int NumberOFTurns(struct Node* root, int first, int second);

 // } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/
// function should return the number of turns required to go from first node to second node 

int ans;

struct Node *lca(struct Node *root,int a,int b)
{
    if(root==NULL)
        return NULL;
        
    struct Node *l,*r;
    
    if(root->data==a||root->data==b)
        return root;
    
    l = lca(root->left,a,b);
    r = lca(root->right,a,b);
    
    if(l&&r)  return root;

    return (l)?l:r;
}

void no_of_turns(struct Node *root,int key,int pre_op,int turns)
{
    if(root==NULL)
        return ;
    
    if(root->data==key){
        ans = turns;  
        return ;
    }

      
    int inc_l=0,inc_r =0;
    
    if(pre_op!=0) inc_l = 1;
    if(pre_op!=1) inc_r = 1;
    
    no_of_turns(root->left,key,0,turns+inc_l);
    no_of_turns(root->right,key,1,turns+inc_r);
    
}


int NumberOFTurns(struct Node* root, int first, int second)
{
   
   struct Node * lca_node = lca(root,first,second);
   
   no_of_turns(lca_node,first,-1,0);
   int ans_a = ans;
   no_of_turns(lca_node,second,-1,0);
   int ans_b= ans;
   
   if(ans_a+ans_b==1)
        return -1;
        
    return ans_a+ans_b-1;
   
}

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        if ((turn = NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
  // } Driver Code Ends