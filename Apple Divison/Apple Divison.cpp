#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int size;
    cin >> size;
    vector<long long> arr;

    long long total_sum = 0;
    long long ans = LLONG_MAX;

    for(int i = 0 ; i < size ; i++)
    {
        long long num;
        cin >> num;
        arr.push_back(num);
        total_sum += num;
    }

    long long total = 1 << size;

    for(int i = 0 ; i < total ; i++)
    {
        long long curr_sum = 0;
        for (int j = 0; j < size; j++)
        {
            if (i & (1 << j))
            {  
                curr_sum += arr[j];
            }
            long long other_sum = total_sum - curr_sum;
            ans = min(ans, abs(other_sum - curr_sum));
        }
    }

    cout << ans;
    return 0;
}
