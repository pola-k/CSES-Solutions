#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int main()
{
    int size;
    cin >> size;
    
    vector<vector<int>> grid(size, vector<int>(size, 1));
    vector<vector<long long>> dp(size, vector<long long>(size, 0));

    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0; j < size; j++)
        {
            char val;
            cin >> val;

            if(val == '*')
            {
                grid[i][j] = -1;
            }
        }
    }
    
    if (grid[0][0] != -1)
    {
        dp[0][0] = 1;
    }
    else
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (grid[i][j] == -1) 
            {
                continue;
            }
            if (i == 0 && j == 0) 
            {
                continue;
            }

            if (j > 0)
            { 
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
            if (i > 0)
            { 
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }

    cout << dp[size - 1][size - 1];
    return 0;
}