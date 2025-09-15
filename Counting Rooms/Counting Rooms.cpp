#include<bits/stdc++.h>
using namespace std;

void DFS(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited)
{
    int rows = grid.size();
    int cols = grid[0].size();

    visited[i][j] = true;
    if(i + 1 < rows && !visited[i + 1][j] && grid[i + 1][j] == '.')
    {
        DFS(i + 1, j, grid, visited);
    }
    if(i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == '.')
    {
        DFS(i - 1, j, grid, visited);
    }
    if(j + 1 < cols && !visited[i][j + 1] && grid[i][j + 1] == '.')
    {
        DFS(i, j + 1, grid, visited);
    }
    if(j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == '.')
    {
        DFS(i, j - 1, grid, visited);
    }
}

int main()
{
    int rows, columns;
    cin >> rows >> columns;

    vector<vector<char>> grid(rows, vector<char>(columns));

    for(int i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j < columns ; j++)
        {
            char type;
            cin >> type;
            grid[i][j] = type;
        }
    }

    vector<vector<bool>> visited(rows, vector<bool>(columns, false));
    int ans = 0;

    for(int i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j < columns ; j++)
        {
            if(!visited[i][j] && grid[i][j] == '.')
            {
                DFS(i, j, grid, visited);
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}