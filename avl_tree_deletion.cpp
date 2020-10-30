// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

int setHeights(Node* n)
{
	if(!n) return 0;
	n->height = 1 + max( setHeights(n->left) , setHeights(n->right) );
	return n->height;
}

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
    
    setHeights(root);
    return root;
}

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}

struct Node* deleteNode(struct Node* root, int data);

int main()
{
	int t;
	cin>>t;
	getchar();

	while(t--)
	{
		string s;
		getline(cin,s);
		Node* root = buildTree(s);
        
		int n;
		cin>> n;
		int ip[n];
		for(int i=0; i<n; i++)
			cin>> ip[i];
        
		for(int i=0; i<n; i++)
		{
			root = deleteNode(root, ip[i]);
			
			if( !isBalancedBST(root) )
				break;
		}
        
		if(root==NULL)
			cout<<"null";
		else
			printInorder(root);
		cout<< endl;
        
		getline(cin,s); // to deal with newline char
	}
	return 1;
}
// } Driver Code Ends


/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/

int height(Node *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}

int get_balance(Node *root)
{
    if(root==NULL)
        return 0;
    return height(root->left) - height(root->right);
}

Node *RightRotate(Node *z)
{   
    /*  No need check null condition ,we come here z in not null */
    //if(z==NULL) 
    //    return NULL;

    Node *y = z->left;
    Node *T3 = y->right;

    y->right = z;
    z->left = T3;
    
    // important order of updating heights also important
    z->height = 1 + max(height(z->left),height(z->right)); 
    y->height = 1 + max(height(y->left),height(y->right));
    
    return y;
}

Node *LeftRotate(Node *z)
{
    /*  No need check null condition ,we come here z in not null */
    //if(z==NULL)
    //    return NULL;

    Node *y = z->right;
    Node *T2 = y->left;

    y->left = z;
    z->right = T2;
    
    // important order of updating heights also important
    z->height = 1 + max(height(z->left),height(z->right)); 
    y->height = 1 + max(height(y->left),height(y->right));

    return y;
}



Node *min_right(Node *root)
{
    while(root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int data)
{
    if(root==NULL)
        return NULL;
    
    if(root->data<data)
        root->right = deleteNode(root->right,data);
    
    else if(root->data>data)
        root->left = deleteNode(root->left,data);
    
    else    
    {
        if(root->left==NULL && root->right==NULL)
            root=NULL;
        else if(root->left==NULL)
            root = root->right;
        else if(root->right==NULL)
            root = root->left;
        else   
        {
            Node *min_node = min_right(root->right);
            root->data = min_node->data;
            root->right = deleteNode(root->right,min_node->data);
        }  
    }

    if(root==NULL)
        return root;

    root->height = 1+max(height(root->left),height(root->right));
    
    int balance = get_balance(root);

    //LL case
    if(balance>1 && get_balance(root->left)>=0)
    {
        root = RightRotate(root);
    }
    //LR case
    else if(balance>1 && get_balance(root->left)<0)   
    {
        root->left = LeftRotate(root->left);
        root = RightRotate(root);
    }
    //RR case
    else if(balance<-1 && get_balance(root->right)<=0)
    {
        root = LeftRotate(root);
    }
    //RL case 
    else if(balance<-1 && get_balance(root->right)>0) 
    {
        root->right = RightRotate(root->right);
        root = LeftRotate(root);
    }

    return root;
    
}


/*

        z
      /   \       Right Rotate             x
    x       T4    ------------>          /    \
   /  \                                 a      z
   a   T1                              / \     / \ 
  / \                                  T2 T3   T1 T4
 T2 T3


        z                                    y
       / \                                  /  \
      T1  y      LeftRotate                Z      a
         / \     -------------->          / \    / \
         T2 a                             T1 T2  T3   T4  
            /\
            T3 T4 
*/

