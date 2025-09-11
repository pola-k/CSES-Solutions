#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size, target_sum;
    cin >> size >> target_sum;

    vector<long long> arr;
    for(int i = 0 ; i < size ; i++)
    {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    int start = 0;
    int end = 0;
    long long curr_sum = 0;
    int ans = 0;

    while(start < size)
    {
        if(curr_sum == target_sum)
        {
            ans++;
            curr_sum -= arr[start];
            start++;
        }
        else if(curr_sum > target_sum)
        {
            curr_sum -= arr[start];
            start++;
        }
        else
        {
            if(end < size)
            {
                curr_sum += arr[end];
                end++;
            }
            else
            {
                curr_sum -= arr[start];
                start++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}