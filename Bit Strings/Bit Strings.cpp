#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long mod = 1e9 + 7;
    int number;
    cin >> number;
    long long ans = 1;
    while(number)
    {
        ans = (ans * 2) % mod;
        number -= 1;
    }
    cout << ans;
    return 0;
}