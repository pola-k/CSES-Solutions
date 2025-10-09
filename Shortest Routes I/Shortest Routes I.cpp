#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<pair<int,long long>>> adj(nodes + 1);

    for(int i = 0 ; i < edges; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source = 1;

    vector<long long> distances(nodes + 1, LLONG_MAX);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    pq.push({0, source});
    distances[source] = 0;

    while(!pq.empty())
    {
        long long curr_cost = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (curr_cost > distances[curr_node]) 
        {
            continue;
        }

        for(auto edge : adj[curr_node])
        {
            int edge_node = edge.first;
            long long edge_cost = edge.second;
            long long new_cost = curr_cost + edge_cost;
            if(new_cost < distances[edge_node])
            {
                distances[edge_node] = new_cost;
                pq.push({new_cost, edge_node});
            }
        }
    }

    for(int i = 1 ; i <= nodes; i++)
    {
        cout << distances[i] << " ";
    }
    cout << endl;

    return 0;
}   