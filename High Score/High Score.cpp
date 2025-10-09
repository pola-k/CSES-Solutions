#include<bits/stdc++.h>
using namespace std;


long long GetMaxScore(int start, int end, vector<vector<pair<int, long long>>>& adj)
{
    
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<pair<int, long long>>> adj(nodes + 1);

    for(int i = 0 ; i < edges ; i++)
    {
        int u, v;
        long long score;
        cin >> u >> v >> score;

        adj[u].push_back({v, score});
    }

    int start_node = 1;
    int end_node = nodes;

    long long max_score = GetMaxScore(start_node, end_node, adj);
    cout << max_score << endl;
    return 0;
}