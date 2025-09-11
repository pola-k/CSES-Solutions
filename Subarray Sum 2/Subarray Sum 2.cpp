#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size, target_sum;
    cin >> size >> target_sum;

    vector<long long> arr;
    for(int i = 0; i < size; i++)
    {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    vector<long long> prefix;
    prefix.push_back(0);
    long long sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
        prefix.push_back(sum);
    }

    map<long long, long long> freq;
    long long ans = 0;

    for(int i = 0 ; i < prefix.size() ; i++)
    {
        long long required = prefix[i] - target_sum;

        if(freq.find(required) != freq.end())
        {
            ans += freq[required];
        }

        freq[prefix[i]]++;
    }

    cout << ans << endl;
    return 0;
}