#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long number;
    cin >> number;
    long long size = number;

    long long sum = ((number) * (number + 1)) / 2;

    if(sum % 2)
    {
        cout << "NO";
        return 0;
    }

    long long target = sum / 2.0;

    unordered_map<int,int> mp;
    vector<int> arr;

    long long sum1 = 0;

    while(sum1 != target)
    {
        if(sum1 + number <= target)
        {
            sum1 += number;
            mp[number]++;
        }

        number -= 1;
    }


    for(int i = 1 ; i <= size ; i++)
    {
        if(mp.find(i) == mp.end())
        {
            arr.push_back(i);   
        }
    }

    cout << "YES" << "\n";
    cout << arr.size() << "\n";
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    cout << mp.size() << "\n";
    for(auto i:mp)
    {
        cout << i.first << " ";
    }

    return 0;
}