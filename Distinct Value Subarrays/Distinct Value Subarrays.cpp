#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> seen;
    int size;
    vector<int> arr;

    cin >> size;

    for(int i = 0 ; i < size ; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int start = 0;
    int end = 0;
    long long ans = 0;

    while(start < size)
    {
        if(seen.find(arr[end]) == seen.end())
        {
            seen.insert(arr[end]);
            end++;
            ans += (long long)(end - start);
        }
        else
        {
            seen.erase(arr[start]);
            start++;
        }

        if(end >= size)
        {
            start = end;
        }
    }

    cout << ans;
    return 0;
}