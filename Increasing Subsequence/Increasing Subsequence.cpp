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

    vector<int> dp;
    dp.push_back(arr[0]);

    for(int i = 1 ; i < size ; i++)
    {
        if(arr[i] > dp.back())
        {
            dp.push_back(arr[i]);
        }
        else
        {
            int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[index] = arr[i]; 
        }
    }

    cout << dp.size() << endl;
    return 0;
}