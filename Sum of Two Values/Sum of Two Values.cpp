#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a , pair<int,int> b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    int target_sum;
    vector<pair<int,int>> arr;

    cin >> n >> target_sum;

    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        arr.push_back({x, i});
    }

    sort(arr.begin(), arr.end(), cmp);

    bool found = false;
    int start = 0;
    int end = n - 1;

    while(!found && start < end)
    {
        int sum = arr[start].first + arr[end].first;
        if(sum == target_sum)
        {
            found = true;
            cout << arr[start].second + 1 << " " << arr[end].second + 1 << endl;
        }
        else if(sum > target_sum)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    if(!found)
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}