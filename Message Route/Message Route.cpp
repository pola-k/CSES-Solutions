#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, connections;
    cin >> nodes >> connections;

    vector<vector<int>> adj(nodes + 1);

    for(int i = 0 ; i < connections ; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(nodes + 1, false);
    vector<int> parent(nodes + 1, -1);
    queue<pair<int,int>> q;
    q.push({1, -1});

    while(!q.empty())
    {
        int curr = q.front().first;
        int node_parent = q.front().second;
        q.pop();
        
        if(visited[curr])
        {
            continue;
        }

        visited[curr] = true;
        parent[curr] = node_parent;

        for(int i = 0 ; i < adj[curr].size() ; i++)
        {
            int neighbor = adj[curr][i];
            if(!visited[neighbor])
            {
                q.push({neighbor, curr});
            }
        }
    }

    if(!visited[nodes])
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path;
        int curr = nodes;
        while(curr != -1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for(int i = 0 ; i < path.size() ; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}