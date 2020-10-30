#include<bits/stdc++.h>
#define ALPHA_SIZE 52
using namespace std;

char grid[7][7]; 
int vis[7][7];
int n,m;
map <string,int>ans;
//vector<string>ans;

struct Node
{
    struct Node *child[ALPHA_SIZE];
    bool end;
} *root;

Node *getNode()
{
    Node *node = new Node();
    for(int i=0;i<ALPHA_SIZE;i++)
        node->child[i] = NULL;
    node->end = 0;
}

int get_index(char ch)
{
    if(ch>='A' && ch<='Z')
        return ch-'A';
    return ch-'a'+26;

}

void InsertTrie(Node *root,string str)
{
    Node *p = root;
    int index;

    for(int i=0;i<str.length();i++)
    {   
        index = get_index(str[i]);
        if(p->child[index]==NULL)
            p->child[index] = getNode();
        p = p->child[index];
    }
    p->end = 1;
}


bool is_valid(int i,int j)
{
    return (i>=0 && i<n && j>=0 && j<m && vis[i][j]==0); 
}

void dfs(int i,int j,string str,Node *curr)
{
   
    if(!is_valid(i,j))
        return ;
    
    if(curr==NULL) 
        return ;

    int  index = get_index(grid[i][j]);

    if(curr->child[index]==NULL)  // if curr pattern not found in Trie no need to proceed further 
        return ;
        
    vis[i][j]=1;
    str += grid[i][j];


    if(curr->child[index]->end==1)  // if str word is in Trie and it is Leaf node 
        ans[str]=1;

    for(int dx=-1;dx<=1;dx++)
    {
        for(int dy=-1;dy<=1;dy++)
        {
            if(dx==0 && dy==0) continue;
            dfs(i+dx,j+dy,str,curr->child[index]);
        }
    }
    vis[i][j]=0;
        
}

int main()
{

    int i,j,t,len;
    string str;
    cin>>t;

    while(t--)
    {   
        cin>>len; root = getNode();

        for(i=0;i<len;i++) {    
            cin>>str;
            InsertTrie(root,str);
        }
        
        cin>>n>>m;

         for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>grid[i][j]; 
        
        memset(vis,0,sizeof(vis));
         

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                dfs(i,j,"",root);
        
        
         if(ans.size()==0)
            ans["-1"]=1; 
            
        for(auto itr:ans) cout<<itr.first<<" ";
       
        cout<<"\n";
        
        ans.clear();
    }

    return 0;
}

/*

1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E


*/