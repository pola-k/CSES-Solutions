#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<int> arr;
    for(int i = 0 ; i < size ; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    vector<int> tower_top;

    for(int i = 0 ; i < size ; i++)
    {
        if(tower_top.empty())
        {
            tower_top.push_back(arr[i]);
        }
        else
        {
            vector<int>::iterator upper = upper_bound(tower_top.begin(), tower_top.end(), arr[i]);
            if(upper == tower_top.end())
            {
                tower_top.push_back(arr[i]);
            }
            else
            {
                *upper = arr[i];
            }
        }
    }

    cout << tower_top.size() << endl;
    return 0;
}