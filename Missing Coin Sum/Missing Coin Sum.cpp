#include <bits/stdc++.h>
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

    sort(arr.begin(), arr.end());

    long long ans = 1;
    int i = 0;

    while(i < size && arr[i] <= ans)
    {
        ans += arr[i];
        i++;
    }

    cout << ans;
    return 0;
}