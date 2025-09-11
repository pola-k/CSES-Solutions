#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size, limit;
    cin >> size >> limit;

    vector<int> arr;
    for(int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    map<long long, long long> mp;
    int start = 0;
    int end = 0;
    long long ans = 0;

    while(end < size)
    {
        if((mp.find(arr[end]) == mp.end() && mp.size() < limit) || (mp.find(arr[end]) != mp.end() && mp.size() <= limit))
        {
            mp[arr[end]]++;
            end++;
            ans += (long long)(end - start);
        }
        else
        {
            mp[arr[start]]--;
            if(mp[arr[start]] == 0)
            {
                mp.erase(arr[start]);
            }
            start += 1;
        }
    }   

    cout << ans << endl;
    return 0;
}