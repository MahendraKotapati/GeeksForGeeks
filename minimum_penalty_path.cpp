#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pl pair<int,int>
#define ppl pair<int,p>
#define F first
#define S second
#define inf 1000000000

vector <pl>g[1003];

vector<string> split_string(string);

// Complete the beautifulPath function below.
int beautifulPath(vector<vector<int>> edges, int A, int B) {

    priority_queue<pl,vector<pl>,greater<pl>>pq;  // pq (dis,node)
    int cost,edge_cost,node,u,v,i,j,n=edges.size();
    vector <int>dis(n+1,inf);

    int vis[1003]={0};

    for(i=0;i<n;i++)
    {   
        u = edges[i][0]; v = edges[i][1]; edge_cost = edges[i][2];

        g[u].pb({v,edge_cost});  g[v].pb({u,edge_cost});   
    }
  
    pq.push({0,A});

    while(!pq.empty())
    {   
        //cout<<"loop";
        auto curr = pq.top(); pq.pop();
        cost = curr.F ; 
        u = curr.S; vis[u]=1;

        for(auto child:g[u])
        {
            v = child.F; edge_cost = child.S; 
            if((cost|edge_cost)<dis[v])
            {
                dis[v] = cost|edge_cost;
                if(vis[v]==0)
                    pq.push({dis[v],v});
            }
        }   
    }    

    if(dis[B]==inf) dis[B]=-1;

    return dis[B];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string AB_temp;
    getline(cin, AB_temp);

    vector<string> AB = split_string(AB_temp);

    int A = stoi(AB[0]);

    int B = stoi(AB[1]);

    int result = beautifulPath(edges, A, B);

    cout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


/*

4 5
1 2 1
1 2 2
2 3 10
3 4 2
3 4 1
1 4

output : 10


*/