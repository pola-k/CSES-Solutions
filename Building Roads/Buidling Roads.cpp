#include<bits/stdc++.h>
using namespace std;

void DFS(int src, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[src] = true;

    for(int i = 0 ; i < adj[src].size() ; i++)
    {
        int neighbor = adj[src][i];
        if(!visited[neighbor])
        {
            DFS(neighbor, adj, visited);
        }
    }
}

int main()
{
    int number_of_cities, number_of_roads;
    cin >> number_of_cities >> number_of_roads;

    vector<vector<int>> adj(number_of_cities + 1);
    vector<bool> visited(number_of_cities + 1, false);

    for(int i = 0 ; i < number_of_roads ; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    vector<int> subcomponents;

    for(int i = 1 ; i <= number_of_cities ; i++)
    {
        if(!visited[i])
        {      
            DFS(i, adj, visited);
            subcomponents.push_back(i);
        }
    }

    cout << subcomponents.size() - 1 << endl;

    for(int i = 0 ; i < subcomponents.size() - 1 ; i++)
    {
        cout << subcomponents[i] << " " << subcomponents[i + 1] << endl;    
    }
    return 0;
}