#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long curr_sum = 0;
    long long total_sum = 0;
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


    while(end < size)
    {
        curr_sum += arr[end];
        end++;
        if(end - start == window_size)
        {
            total_sum = total_sum ^ curr_sum;
            curr_sum -= arr[start];
            start++;
        }
    }

    if(end - start == window_size)
    {
        total_sum = total_sum ^ curr_sum;
        curr_sum -= arr[start];
        start++;
    }

    cout << total_sum;
    return 0;
}