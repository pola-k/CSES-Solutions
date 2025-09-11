#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<long long> arr;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }

    int i = 0;
    int start = 0;
    int end = 0;
    long long curr_sum = 0;
    long long max_sum = LLONG_MIN;

    while(i < n)
    {
        if(curr_sum + arr[i] < arr[i])
        {
            curr_sum = arr[i];
            start = i;
        }
        else
        {
            curr_sum += arr[i];
        }

        if(max_sum < curr_sum)
        {
            max_sum = curr_sum;
            end = i;
        }

        i++;
    }

    cout << max_sum << "\n";
    cout << "Start: " << start << "\nEnd: " << end << "\n"; 
    return 0;
}