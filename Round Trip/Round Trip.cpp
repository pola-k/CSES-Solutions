#include <bits/stdc++.h>
using namespace std;

bool BFS(int node, int parent, vector<bool>& visited, vector<int>& parentArr, vector<vector<int>>& adj)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    parentArr[node] = parent;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(auto nbr : adj[curr])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                parentArr[nbr] = curr;
                q.push(nbr);
            }
            else if(visited[nbr] && nbr != parentArr[curr])
            {
               
                vector<int> pathU, pathV;

                int u = curr, v = nbr;
                while (u != -1) 
                { 
                    pathU.push_back(u); u = parentArr[u]; 
                }
                while (v != -1) 
                { 
                    pathV.push_back(v); v = parentArr[v]; 
                }

                reverse(pathU.begin(), pathU.end());
                reverse(pathV.begin(), pathV.end());

                int i = 0;
                while (i < (int)pathU.size() && i < (int)pathV.size() && pathU[i] == pathV[i])
                { 
                    i++;
                }
                i--;

                vector<int> cycle;
                for (int j = pathU.size() - 1; j >= i; j--) 
                {
                    cycle.push_back(pathU[j]);
                }

                for (int j = i + 1; j < (int)pathV.size(); j++) 
                {
                    cycle.push_back(pathV[j]);
                }
                
                cycle.push_back(pathU[pathU.size() - 1]);

                cout << cycle.size() << endl;
                for(auto n : cycle)
                {
                    cout << n << " ";
                }

                return true;
            }
        }
    }

    return false;
}

bool DFS(int node, int parent, vector<bool>& visited, vector<int>& parentArr, vector<vector<int>>& adj)
{
    visited[node] = true;
    parentArr[node] = parent;

    for(auto nbr: adj[node])
    {
        if(!visited[nbr])
        {
            if(DFS(nbr, node, visited, parentArr, adj))
            {
                return true;
            }
        }
        else if(visited[nbr] && nbr != parent)
        {
            vector<int> cycle;
            cycle.push_back(nbr);
            int curr = node;
            while(curr != nbr)
            {
                cycle.push_back(curr);
                curr = parentArr[curr];
            }
            cycle.push_back(nbr);

            cout << cycle.size() << endl;
            for(auto n : cycle)
            {
                cout << n << " ";
            }

            return true;
        }

    }

    return false;
}

int main() 
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    vector<vector<int>> adj(nodes + 1);

    for(int i = 0 ; i < edges ; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(nodes + 1, false);
    vector<int> parent(nodes + 1, -1);
    bool found = false;

    for(int i = 1 ; i <= nodes ; i++)
    {
        if(!visited[i])
        {
            //found = BFS(i, -1, visited, parent, adj);
            found = DFS(i, -1, visited, parent, adj);
            if(found)
            {
                break;
            }
        }
    }

    if(!found)
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
