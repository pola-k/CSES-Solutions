#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int size;
    cin >> size;

    vector<int> arr;
    map<int,long long> freq;

    for(int i = 0 ; i < size ; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
        freq[num]++;
    }

    int ans = 1;
    for(auto i:freq)
    {
        long long frequency = i.second + 1;
        ans = (ans * frequency) % MOD;
    }

    ans = (ans - 1) % MOD;
    cout << ans;
    return 0;
}