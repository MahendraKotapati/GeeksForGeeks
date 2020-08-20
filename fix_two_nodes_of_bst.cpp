// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};

void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

struct Node* NewNode(int data)
{
    struct Node* Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
struct Node *correctBST( struct Node* root );
void Inorder(struct Node *root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
int flag=1;
int c=0;
void inorder(struct Node *temp,struct Node *root){
	if(flag==0){
		return;
	}
	if(temp==NULL&&root==NULL)
		return;
	if(root==NULL){
		flag=0;
		return;
	}
	if(temp==NULL){
		flag=0;
		return;
	}
	if(temp->data==root->data){
	    c++;
	}
	inorder(temp->left,root->left);
	inorder(temp->right,root->right);
}
void insert(struct Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
				case 'L':root->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				break;
			}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}

int main()
{   
	int t;
	cin>>t;
	while(t--){
	struct Node *root=NULL;
	struct Node *temp=NULL;
	int n;
	cin>>n;
	int m=n;
	while(n--){
		int a1,a2;
		char lr;
		cin>>a1>>a2>>lr;
		if(root==NULL){
			temp=NewNode(a1);
			root=NewNode(a1);
			switch(lr){
				case 'L':root->left=NewNode(a2);
				        temp->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				        temp->right=NewNode(a2);
				break;
			}
		}
		else{
			insert(root,a1,a2,lr);
			insert(temp,a1,a2,lr);
		}
	}
	flag=1;
	c=0;
	
	root=correctBST(root);

	inorder(temp,root);

	if(c+1==m){
	    cout<<flag<<endl;
	}
	else{
	    cout<<"0\n";
	}
	}
    return 0;
}// } Driver Code Ends

/*Complete the function
Node is as follows:
struct Node
{
    int data;
    struct Node *left, *right;
    
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};
*/

int ans[3],ans_i;

int rec(struct Node *root,int op)
{
    if(root==NULL)
       return 0;

    int l,r;

    if(root->left==NULL)
        l= root->data;
    else  
        l=rec(root->left,0);

    if(root->right==NULL)
        r = root->data;
    else  
        r =rec(root->right,1);

    if(root->data<l)
    {
        ans[ans_i]=l; ans_i++;
        return (op==0)? max(root->data,r):min(root->data,r);
    }   
    
    if(root->data>r)
    {
        ans[ans_i]=r;  ans_i++;
       return  (op==0)? max(root->data,l):min(root->data,l);
    }   
    
    if(op==0)
        return max(root->data,max(l,r));
    else  
        return min(root->data,min(l,r));

}

void swap_nodes(struct Node *root,int a,int b)
{
    if(root==NULL)
        return ;
    swap_nodes(root->left,a,b);
    if(root->data==a)
        root->data=b;
    else if(root->data==b)
        root->data=a;
    swap_nodes(root->right,a,b);
}

struct Node *correctBST(struct Node* root)
{ 
    ans_i=0;
    rec(root,0); 
    //cout<<ans[0]<<" "<<ans[1]<<" ";
    if(ans_i==2)
        swap_nodes(root,ans[0],ans[1]);
    return root;
}