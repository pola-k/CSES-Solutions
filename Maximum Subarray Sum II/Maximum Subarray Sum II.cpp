#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size, min_length, max_length;
    cin >> size >> min_length >> max_length;

    vector<long long> arr;
    for(int i = 0 ; i < size ; i++)
    {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    long long ans = LLONG_MIN;
    vector<long long> prefix;
    prefix.push_back(0);

    for(int i = 0 ; i < size ; i++)
    {
        prefix.push_back(prefix[i] + arr[i]);
    }

    set<pair<long long, int>> window;
    int start = 0;
    int low = start + min_length;
    int high = start + max_length;

    for(int i = low ; i <= high ; i++)
    {
        window.insert({prefix[i], i});
    }

    for(int start = 0; start < size && low <= size ; start++)
    {
        long long max_prefix = window.rbegin()->first;
        long long curr_sum = max_prefix - prefix[start];
        ans = max(ans, curr_sum);
        window.erase({prefix[low], low});
        low++;
        high++;
        if(high <= size)
        {
            window.insert({prefix[high], high});
        }
    }

    cout << ans << endl;
    return 0;
}