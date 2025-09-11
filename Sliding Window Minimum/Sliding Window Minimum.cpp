#include<bits/stdc++.h>
using namespace std;

int main()
{
    int start = 0;
    int end = 0;
    int size, window_size;
    cin >> size >> window_size;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> arr;
    arr.push_back(x);
    int temp = x;

    for(int i = 1 ; i < size ; i++)
    {
        temp = (a * temp + b) % c;
        arr.push_back(temp); 
    }

    multiset<int> window_content;
    long long ans = 0;

    while(end < size)
    {
        window_content.insert(arr[end]);
        end++;
        if(end - start == window_size)
        {
            long long min_value = *(window_content.begin());
            ans = ans ^ min_value;
            window_content.erase(window_content.find(arr[start]));
            start++;
        }
    }

    if(end - start == window_size)
    {
        long long min_value = *(window_content.begin());
        ans = ans ^ min_value;
        window_content.erase(window_content.find(arr[start]));
        start++;
    }

    cout << ans;
    return 0;
}