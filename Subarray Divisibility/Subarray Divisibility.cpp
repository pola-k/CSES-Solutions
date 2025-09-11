#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<long long> arr;
    for(int i = 0 ; i < size ; i++)
    {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    vector<long long> prefix;
    prefix.push_back(0);
    long long curr_sum = 0;

    for(int i = 0 ; i < size ; i++)
    {
        curr_sum += arr[i];
        prefix.push_back(curr_sum);
    }

    map<long long, long long> freq;
    long long ans = 0;

    for(int i = 0 ; i < prefix.size() ; i++)
    {
        long long remainder = ((prefix[i] % size) + size) % size;
        if(freq.find(remainder) != freq.end())
        {
            ans += freq[remainder];
        }
        freq[remainder]++;
    }

    cout << ans << endl;
    return 0;
}