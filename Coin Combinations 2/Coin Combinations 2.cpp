#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long Recursive(int index, int target_sum, vector<int>& coins, vector<vector<int>>& dp)
{
    if(target_sum == 0)
    {
        return 1;
    }
    if(target_sum < 0)
    {
        return 0;
    }
    if(index >= coins.size())
    {
        return 0;
    }
    if(dp[index][target_sum] != -1)
    {
        return dp[index][target_sum];
    }

    int ans = 0;
    ans = (ans + Recursive(index, target_sum - coins[index], coins, dp)) % mod;
    ans = (ans + Recursive(index + 1, target_sum, coins, dp)) % mod;
    return dp[index][target_sum] = ans;
}

int main()
{
    int number_of_coins, target_sum;
    cin >> number_of_coins >> target_sum;

    vector<int> coins;
    for(int i = 0 ; i < number_of_coins ; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    vector<vector<int>> dp(number_of_coins + 1, vector<int>(target_sum + 1, 0));

    for (int i = 0; i <= number_of_coins; i++) 
    {
        dp[i][0] = 1;
    }

    for (int i = number_of_coins - 1; i >= 0; i--) 
    {
        for (int j = 0; j <= target_sum; j++) 
        {
            long long ans = dp[i + 1][j];
            if (j - coins[i] >= 0) 
            {
                ans = (ans + dp[i][j - coins[i]]) % mod;
            }
            dp[i][j] = ans;
        }
    }

    cout << dp[0][target_sum] % mod;
    return 0;
}