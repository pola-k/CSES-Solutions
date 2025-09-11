#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<int> arr;
    for(int i = 0; i < size ; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    vector<int> dp(size, 1);

    for(int i = size - 2 ; i >= 0 ; i--)
    {
        if(arr[i] < arr[i + 1])
        {
            dp[i] = 1 + dp[i + 1];
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[0] << endl;
    return 0;
}