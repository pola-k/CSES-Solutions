#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long Recursive(int index, vector<long long>& arr, long long sum, vector<vector<long long>>& dp)
{
    if(sum == 0)
    {
        return 1;
    }
    if(index >= arr.size() || sum < 0)
    {
        return 0;
    }
    if(dp[index][sum] != -1)
    {
        return dp[index][sum];
    }

    long long include = Recursive(index + 1, arr, sum - arr[index], dp) % MOD;
    long long exclude = Recursive(index + 1, arr, sum, dp) % MOD;
    return dp[index][sum] = (include + exclude) % MOD;
}


int main()
{
    int size;
    cin >> size;

    vector<long long> arr;
    long long sum = 0;
    for(int i = 0; i < size; i++)
    {
        arr.push_back(i + 1);
        sum += (i + 1);
    }

    if(sum % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<long long>> dp(size + 1, vector<long long>(sum / 2 + 1, -1));

    long long ans = Recursive(0, arr, sum / 2, dp);
    long long inv2 = (MOD + 1) / 2;
    cout << (ans * inv2) % MOD << endl;
    return 0;
}