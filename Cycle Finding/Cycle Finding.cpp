#include <bits/stdc++.h>
using namespace std;

void BellmanFord(vector<vector<pair<int, long long>>>& adj, int nodes)
{
    vector<long long> distances(nodes + 1, 0);
    vector<int> parent(nodes + 1, -1);

    for (int i = 0; i < nodes - 1; i++)
    {
        for (int u = 1; u <= nodes; u++)
        {
            for (auto [v, w] : adj[u])
            {
                if (distances[u] + w < distances[v])
                {
                    distances[v] = distances[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    int last_updated_node = -1;

    for (int u = 1; u <= nodes; u++)
    {
        for (auto [v, w] : adj[u])
        {
            if (distances[u] + w < distances[v])
            {
                parent[v] = u;
                last_updated_node = v;
            }
        }
    }

    if (last_updated_node == -1)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int y = last_updated_node;
    for (int i = 0; i < nodes; i++)
    {
        y = parent[y];
    }

    vector<int> cycle;
    int curr = y;
    do 
    {
        cycle.push_back(curr);
        curr = parent[curr];
    } while (curr != y && curr != -1);

    cycle.push_back(y);

    reverse(cycle.begin(), cycle.end());

    for (int node : cycle)
    {
        cout << node << " ";
    }
    cout << endl;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<pair<int, long long>>> adj(nodes + 1);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    BellmanFord(adj, nodes);
    return 0;
}
