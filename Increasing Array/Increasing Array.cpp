#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long size;
    cin >> size;

    vector<long long> arr;

    for(int i = 0 ; i < size ; i++)
    {
        long long number;
        cin >> number;
        arr.push_back(number);
    }

    long long moves = 0;

    for(int i = 1; i < size ; i++)
    {
        if(arr[i] < arr[i-1])
        {
            long long difference = arr[i - 1] - arr[i];
            moves += difference;
            arr[i] = arr[i - 1];
        }
    }

    cout << moves;

    return 0;
}