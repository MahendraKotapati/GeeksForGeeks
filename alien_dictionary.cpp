// { Driver Code Starts
// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>

using namespace std;

string findOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = findOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/
 
string findOrder(string dict[], int n, int k) {
     
    int i,j,len1,len2,in[k+1],u,v,node;  // in[i] stores indegree of node i
    vector<int>g[k+1];  // creating graph with k charcters as nodes.

    memset(in,0,sizeof(in));

    for(i=1;i<n;i++)
    {   
        len1 = dict[i-1].length(); len2 = dict[i].length();

        j=0;
        while(j<len1 && j<len2)   // compare adjacent words , till mismatch of characters
            if(dict[i-1][j]!=dict[i][j])
                break;
            else   
                j++;

        if(j==len1||j==len2) // if reached end of anyword 
            continue;

        u = dict[i-1][j]-'a';  v = dict[i][j]-'a';   

        g[u].push_back(v);
        in[v]++;
    }

    string ans="";

    // using khan's algorithm for finding topological ordering.
    queue<int>q;

    for(i=0;i<k;i++) 
        if(in[i]==0) q.push(i);
    

    while(!q.empty())
    {
        node = q.front();     q.pop();
        ans+= char(node+'a');
        
        for(int child:g[node])
        {
            in[child]--;
            if(in[child]==0) 
                q.push(child);
        }
    }
    
    
    return ans; 
     
     
}