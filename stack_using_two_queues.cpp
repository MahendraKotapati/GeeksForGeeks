// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)   // inserting element at front of queue
{
    
    while(!q1.empty())   // poping all element from q1 and pushing into q2
        q2.push(q1.front()),q1.pop();
        
    q1.push(x);  // simply insert new element into q1
    
    while(!q2.empty()) // again insert all elements into q1
        q1.push(q2.front()),q2.pop();
    
    /*  instead of doing   we can also push new element into q2 and then push all elements(from q1) into q2 then swap name of q1,q2 */
    
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
     
     if(q1.empty())
        return -1;
     int ans = q1.front(); q1.pop();
     return ans;
}