#include<bits/stdc++.h>
using namespace std;

pair<int,int> getCoordinates(vector<vector<char>> grid, char type)
{
    for(int i = 0; i < grid.size() ; i++)
    {
        for(int j = 0; j < grid[0].size() ; j++)
        {
            if(grid[i][j] == type)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

void reconstructPath(pair<int,int> curr_coords, vector<vector<char>> directions)
{
    vector<char> path;
    int curr_row = curr_coords.first;
    int curr_col = curr_coords.second;

    while(directions[curr_row][curr_col] != ' ')
    {
        char direction = directions[curr_row][curr_col];
        path.push_back(direction);

        if(direction == 'U')
        {
            curr_row += 1;
        }
        else if(direction == 'D')
        {
            curr_row -= 1;
        }
        else if(direction == 'R')
        {
            curr_col -= 1;
        }
        else if(direction == 'L')
        {
            curr_col += 1;
        }
    }

    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.size() << endl;
    for(int i = 0 ; i < path.size() ; i++)
    {
        cout << path[i];
    }
    cout << endl;
}

bool BFS(vector<vector<char>> grid, pair<int,int> start_coords, pair<int,int> end_coords)
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<char>> directions(rows, vector<char>(cols, ' '));
    queue<pair<int,int>> q;

    q.push(start_coords);
    
    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        q.pop();
        int curr_row = curr.first;
        int curr_col = curr.second;

        if(curr == end_coords)
        {
            reconstructPath(curr, directions);
            return true;
        }

        if(!visited[curr_row][curr_col])
        {
            visited[curr_row][curr_col] = true;

            if(curr_row + 1 < rows && !visited[curr_row + 1][curr_col] && (grid[curr_row + 1][curr_col] == '.' || grid[curr_row + 1][curr_col] == 'B'))
            {
                q.push({curr_row + 1, curr_col});
                directions[curr_row + 1][curr_col] = 'D';
            }
            if(curr_row - 1 >= 0 && !visited[curr_row - 1][curr_col] && (grid[curr_row - 1][curr_col] == '.' || grid[curr_row - 1][curr_col] == 'B'))
            {
                q.push({curr_row - 1, curr_col});
                directions[curr_row - 1][curr_col] = 'U';
            }
            if(curr_col + 1 < cols && !visited[curr_row][curr_col + 1] && (grid[curr_row][curr_col + 1] == '.' || grid[curr_row][curr_col + 1] == 'B'))
            {
                q.push({curr_row, curr_col + 1});
                directions[curr_row][curr_col + 1] = 'R';
            }
            if(curr_col - 1 >= 0 && !visited[curr_row][curr_col - 1] && (grid[curr_row][curr_col - 1] == '.' || grid[curr_row][curr_col - 1] == 'B'))
            {
                q.push({curr_row, curr_col - 1});
                directions[curr_row][curr_col - 1] = 'L';
            }
        }
    }

    return false;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    for(int i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j < cols ; j++)
        {
            char type;
            cin >> type;
            grid[i][j] = type;
        }
    }

    pair<int,int> start_coords = getCoordinates(grid, 'A');
    pair<int, int> end_coords = getCoordinates(grid, 'B');
    pair<int,int> error = {-1, -1};

    if(start_coords == error || end_coords == error)
    {
        cout << "NO" << endl;
        return 0;
    }

    bool exists = BFS(grid, start_coords, end_coords);

    if(!exists)
    {
        cout << "NO" << endl;
    }

    return 0;
}