#include<bits/stdc++.h>
using namespace std;

bool DFS(int curr, vector<vector<int>>& edges, vector<int>& colors, int curr_color)
{
    int next_color = (curr_color == 1 ? 2 : 1);
    colors[curr] = curr_color;

    for(int i = 0 ; i < edges[curr].size() ; i++)
    {
        int neighbor = edges[curr][i];
        if(!colors[neighbor])
        {
            bool valid = DFS(neighbor, edges, colors, next_color);
            if(!valid)
            {
                return false;
            }
            
        }
        if(colors[neighbor] == curr_color)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int nodes, number_of_edges;
    cin >> nodes >> number_of_edges;

    vector<vector<int>> edges(nodes + 1);
    vector<int> colors(nodes + 1, 0);

    for(int i = 0 ; i < number_of_edges ; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i = 1 ; i <= nodes ; i++)
    {
        if(!colors[i])
        {
            bool valid = DFS(i, edges, colors, 1);
            if(!valid)
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(int i = 1 ; i <= nodes ; i++)
    {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}   