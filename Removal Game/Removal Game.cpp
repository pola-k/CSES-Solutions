#include<bits/stdc++.h>
using namespace std;

long long MinMax(vector<long long>& arr, int l, int r, bool maximize, vector<vector<vector<long long>>>& dp)
{
    if (l > r) 
    {
        return 0;
    }
    if (l == r)
    { 
        if(maximize)
        {
            return arr[l];
        }
        
        return 0;
    }

    if (dp[l][r][maximize] != LLONG_MIN)
    {
        return dp[l][r][maximize];
    }

    if (maximize) 
    {
        return dp[l][r][maximize] = max(arr[l] + MinMax(arr, l + 1, r, false, dp), arr[r] + MinMax(arr, l, r - 1, false, dp));
    } 
    else 
    {
        return dp[l][r][maximize] = min(MinMax(arr, l + 1, r, true, dp), MinMax(arr, l, r - 1, true, dp));
    }
}


int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }

    for (int len = 3; len <= n; len++) 
    {
        for (int l = 0; l + len - 1 < n; l++) 
        {
            int r = l + len - 1;

            long long pickLeft = arr[l] + min((l + 2 <= r ? dp[l + 2][r] : 0), (l + 1 <= r - 1 ? dp[l + 1][r - 1] : 0));

            long long pickRight = arr[r] + min((l <= r - 2 ? dp[l][r - 2] : 0), (l + 1 <= r - 1 ? dp[l + 1][r - 1] : 0));

            dp[l][r] = max(pickLeft, pickRight);
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}
