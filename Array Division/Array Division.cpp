#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size, number_of_subarrays;
    cin >> size >> number_of_subarrays;

    vector<int> arr;
    long long sum = 0;
    int max_val = INT_MIN;

    for(int i = 0 ; i < size ; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
        sum += num;
        max_val = max(max_val, num);
    }

    long long low = max_val;
    long long high = sum;

    while(low < high)
    {
        long long mid = (low + high) / 2;
        long long curr = 0;
        int number = 1;
        for(int i = 0 ; i < size ; i++)
        {
            curr += arr[i];
            if(curr > mid)
            {
                number++;
                curr = arr[i];
            }
        }

        if(number <= number_of_subarrays)
        {
            high = mid;
        }
        else if(number > number_of_subarrays)
        {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}