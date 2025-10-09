#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    // Each cell stores the coordinates of the lexicographically best next cell
    vector<vector<pair<int,int>>> nextCell(n, vector<pair<int,int>>(n, {-1,-1}));

    // Bottom-up DP
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == n - 1 && j == n - 1) continue;

            pair<int,int> down = {-1,-1}, right = {-1,-1};

            if (i + 1 < n) down = {i + 1, j};
            if (j + 1 < n) right = {i, j + 1};

            if (down.first != -1 && right.first != -1) {
                // Compare characters of both possible next cells
                if (grid[down.first][down.second] == grid[right.first][right.second]) {
                    // Same char, compare deeper lexicographically
                    if (nextCell[down.first][down.second] == nextCell[right.first][right.second])
                        nextCell[i][j] = down; // arbitrary, same result
                    else {
                        // simulate next comparison
                        pair<int,int> a = nextCell[down.first][down.second];
                        pair<int,int> b = nextCell[right.first][right.second];
                        // fallback: choose lexicographically smaller path
                        nextCell[i][j] = (a < b ? down : right);
                    }
                } else if (grid[down.first][down.second] < grid[right.first][right.second]) {
                    nextCell[i][j] = down;
                } else {
                    nextCell[i][j] = right;
                }
            } else if (down.first != -1) {
                nextCell[i][j] = down;
            } else {
                nextCell[i][j] = right;
            }
        }
    }

    // Reconstruct path
    string ans = "";
    int x = 0, y = 0;
    while (x != -1 && y != -1) {
        ans += grid[x][y];
        auto [nx, ny] = nextCell[x][y];
        x = nx;
        y = ny;
    }

    cout << ans << "\n";
    return 0;
}
