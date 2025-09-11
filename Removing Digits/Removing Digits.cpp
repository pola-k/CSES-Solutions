#include<bits/stdc++.h>
using namespace std;


set<int> getDigits(int num)
{
    set<int> digits;

    while(num)
    {
        int digit = num % 10;
        if(digit)
        {
            digits.insert(digit);
        }
        num /= 10;
    }

    return digits;
}

int Recursion(int num, vector<int>& dp)
{
    if(num == 0)
    {
        return 0;
    }
    if(dp[num] != -1)
    {
        return dp[num];
    }

    set<int> digits = getDigits(num);
    int ans = INT_MAX;

    for(auto digit: digits)
    {
        ans = min(ans, Recursion(num - digit, dp) + 1);
    }

    return dp[num] = ans;
}

int main()
{
    int num;
    cin >> num;

    vector<int> dp(num + 1 , -1);

    cout << Recursion(num, dp) << endl;
    return 0;
}