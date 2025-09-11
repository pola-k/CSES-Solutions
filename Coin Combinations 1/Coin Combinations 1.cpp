#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() 
{
    int number_of_coins, target_sum;
    cin >> number_of_coins >> target_sum;

    vector<int> coins;
    for (int i = 0; i < number_of_coins; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    vector<int> dp(target_sum + 1, 0);
    dp[0] = 1;

    for (int sum = 1; sum <= target_sum; sum++) 
    {
        long long ways = 0;
        for (int c : coins) 
        {
            if (sum - c >= 0) 
            {
                ways += dp[sum - c];
                if (ways >= MOD)
                {
                    ways -= MOD;
                } 
            }
        }
        dp[sum] = ways;
    }

    cout << dp[target_sum] << "\n";
    return 0;
}
