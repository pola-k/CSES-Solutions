#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int Recursive(vector<int> &arr, int required_sum, vector<int> &dp) 
{
    if (required_sum == 0) return 1; 
    if (required_sum < 0) return 0;
    if (dp[required_sum] != -1) return dp[required_sum];

    long long ans = 0;
    for (int i = 0; i < arr.size(); i++) 
    {
        ans = (ans + Recursive(arr, required_sum - arr[i], dp)) % mod;
    }
    return dp[required_sum] = ans;
}

int main() 
{
    vector<int> arr = {1,2,3,4,5,6};
    int required_sum;
    cin >> required_sum;
    vector<int> dp(required_sum + 1, -1);

    int ans = Recursive(arr, required_sum, dp);
    cout << ans;
    return 0;
}
