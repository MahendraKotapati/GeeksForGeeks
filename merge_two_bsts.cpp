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



vector<int> merge(Node *root1,Node *root2);

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
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* The structure of Node is

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// Return a integer of integers having all the nodes in both the BSTs in a sorted order.


vector<int> merge(Node *root1, Node *root2)
{   
    
    vector<int>arr;
    stack<Node*>s1,s2;
    Node *temp1,*temp2,*curr1,*curr2;
    bool flag1 = true,flag2 = true;

    temp1 = root1;
    while(temp1)
    {   
        s1.push(temp1);
        temp1 = temp1->left;
    }

    temp2 = root2;
    while(temp2)
    {   
        s2.push(temp2);
        temp2 = temp2->left;
    }


    while( !s1.empty() && !s2.empty())
    {   
         
        while(flag1)
        {
            curr1 = s1.top();  s1.pop();
            temp1 = curr1->right;

            while(temp1)
            {   
                s1.push(temp1);
                temp1 = temp1->left;
            }  
            flag1 = false; 
        }

        while(flag2)
        {
            curr2 = s2.top(); s2.pop();
            temp2 = curr2->right;

            while(temp2)
            {   
                s2.push(temp2);
                temp2 = temp2->left;
            }   
            flag2 = false;
        }

        //cout<<curr1->data<<" "<<curr2->data<<"\n";

        if(curr1->data<=curr2->data) 
        {   
            arr.push_back(curr1->data);   curr1 = NULL;
            flag1 = true; 
        }
        else 
        { 
            arr.push_back(curr2->data);  curr2 = NULL;
            flag2 = true; 
        }  
    }

    /*if(curr1)
        arr.push_back(curr1->data);

    if(curr2)
        arr.push_back(curr2->data); */
    

    while(!s1.empty())
    {
        curr1 = s1.top(); 
        s1.pop(); 

        if(curr2!=NULL)
        {
            if(curr1->data>curr2->data)
                arr.push_back(curr2->data),curr2=NULL;   
        }
        arr.push_back(curr1->data);

        arr.push_back(curr1->data);
        temp1 = curr1->right;

        while(temp1)
        {   
            s1.push(temp1);
            temp1 = temp1->left;
        }       
    }

    while(!s2.empty())
    {
        curr2 = s2.top(); s2.pop();
        if(curr1!=NULL)
        {
            if(curr2->data>curr1->data)
                arr.push_back(curr1->data),curr1=NULL;   
        }
        arr.push_back(curr2->data);
        temp2 = curr2->right;

        while(temp2)
        {   
            s2.push(temp2);
            temp2 = temp2->left;
        }  
    }

    return arr;
}