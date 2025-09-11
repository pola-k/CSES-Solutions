#include<bits/stdc++.h>
using namespace std;

int Recursive(vector<int>& coins, int target_sum, vector<int>& dp)
{
    if(target_sum == 0)
    {
        return 0;
    }
    if(target_sum < 0)
    {
        return INT_MAX;
    }
    if(dp[target_sum] != -1)
    {
        return dp[target_sum];
    }

    int ans = INT_MAX;

    for(int i = 0 ; i < coins.size() ; i++)
    {
        int result = Recursive(coins, target_sum - coins[i], dp);
        if(result != INT_MAX)
        {
            ans = min(ans, result + 1);
        }
    }

    return dp[target_sum] = ans;
}


int main()
{
    int number_of_coins;
    int target_sum;
    cin >> number_of_coins >> target_sum;

    vector<int> coins;
    for(int i = 0 ; i < number_of_coins ; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    vector<int> dp(target_sum + 1, -1);
    int ans = Recursive(coins, target_sum, dp);

    if(ans == INT_MAX)
    {
        ans = -1;
    }

    cout << ans << endl;
    return 0;
}