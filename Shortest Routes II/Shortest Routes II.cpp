#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e15; 

long long Dijkstra(int start, int end, vector<vector<pair<int, long long>>>& adj, int nodes)
{
    vector<bool> visited(nodes + 1, false);
    vector<long long> distances(nodes + 1, LLONG_MAX);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    distances[start] = 0;
    pq.push({0, start});
    bool early_stop = false;

    while(!pq.empty() && !early_stop)
    {
        long long curr_distance = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if(curr_node == end)
        {
            early_stop = true;
            continue;
        }

        if (curr_distance > distances[curr_node]) 
        {
            continue;
        }

        for(auto nbr : adj[curr_node])
        {
            int nbr_node = nbr.first;
            long long path_cost = nbr.second;
            long long new_cost = curr_distance + path_cost;

            if(new_cost <= distances[nbr_node])
            {
                distances[nbr_node] = new_cost;
                pq.push({new_cost, nbr_node});
            }
        }
    }

    if(distances[end] == LLONG_MAX)
    {
        return -1;
    }
    return distances[end];
}

vector<vector<long long>> FloydWarshall(int nodes, vector<map<int, long long>>& adj)
{
    vector<vector<long long>> distances(nodes + 1, vector<long long>(nodes + 1, INF));
    for(int i = 1 ; i <= nodes ; i++)
    {
        distances[i][i] = 0;
    }

    for(int i = 1 ; i <= nodes ; i++)
    {
        for(auto path: adj[i])
        {
            int v = path.first;
            long long cost = path.second;
            if(i != v)
            {
                distances[i][v] = cost;
            }
        }
    }

    for(int middle = 1 ; middle <= nodes ; middle++)
    {
        for(int i = 1 ; i <= nodes ; i++)
        {
            for(int j = 1 ; j <= nodes ; j++)
            {
                if(distances[i][middle] != INF && distances[middle][j] != INF)
                {
                    distances[i][j] = min(distances[i][middle] + distances[middle][j], distances[i][j]);
                }
            }
        }
    }

    for(int i = 1 ; i <= nodes ; i++)
    {
        for(int j = 1 ; j <= nodes ; j++)
        {
            if(distances[i][j] == INF)
            {
                distances[i][j] = -1;
            }
        }
    }

    return distances;
}

int main()
{
    int nodes, edges, queries;
    cin >> nodes >> edges >> queries;

    vector<map<int, long long>> adj(nodes + 1);

    for(int i = 0 ; i < edges ; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        if(adj[u].find(v) != adj[u].end())
        {
            adj[u][v] = min(w, adj[u][v]);
            adj[v][u] = min(w, adj[v][u]);
        }
        else
        {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }

    vector<vector<long long>> distances = FloydWarshall(nodes, adj);
    
    /* for(int i = 0 ; i < queries ; i++)
    {
        int start_node, end_node;
        cin >> start_node >> end_node;

        long long shortest_distance = Dijkstra(start_node, end_node, adj, nodes);
        cout << shortest_distance << endl;
    } */

    for(int i = 0; i < queries ; i++)
    {
        int start_node, end_node;
        cin >> start_node >> end_node;
        cout << distances[start_node][end_node] << endl;
    }

    return 0;
}