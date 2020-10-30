#include<bits/stdc++.h>
#define ALPHA_SIZE 26 
using namespace std;

struct Node
{
    struct Node *child[ALPHA_SIZE];
    bool end;

} *root;


Node* getNode()
{
    Node *node = new Node();
    for(int i=0;i<ALPHA_SIZE;i++)
        node->child[i] = NULL;
    node->end = false;

    return node;
}


void InsertTrie(string str)
{

    Node *p = root;
    int index;

    for(int i=0;i<str.length();i++)
    {   
        index = str[i]-'a';
        if(p->child[index]==NULL)
            p->child[index] = getNode();
        p = p->child[index];
    }
    p->end = true;
}

bool SearchTrie(string str)
{
    Node *p = root;
    int index;

    for(int i=0;i<str.length();i++)
    {
        index = str[i]-'a';
        if(p->child[index]==NULL)
            return false;
        p = p->child[index];
    }

    return (p!=NULL && p->end);
}

int main()
{
    int t,n;
    string str;
    cin>>t;

    while(t--)
    {   
        root = getNode();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            InsertTrie(str);
        }
        cin>>str;
        cout<<SearchTrie(str)<<"\n";

    }
}