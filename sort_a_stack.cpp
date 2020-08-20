// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void stack_push(stack <int>&s,int d)
{
    if(s.empty())
    {    
        s.push(d);
        return ; 
    }

    int top_= s.top(); s.pop();

    if(top_>d)
    {
        stack_push(s,d);
        s.push(top_); 
    }
    else
    { 
        s.push(top_); 
        s.push(d);
    }
}

void stack_pop(stack <int>&s)
{
    if(s.empty())
        return ;

    int top_= s.top();  s.pop();
    stack_pop(s);
    stack_push(s,top_);
}

void SortedStack :: sort()
{
    stack_pop(this->s);
}