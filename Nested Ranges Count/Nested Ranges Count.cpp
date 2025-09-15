#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<pair<int,int>> times;

    for(int i = 0 ; i < size ; i++)
    {
        int start, end;
        cin >> start >> end;
        times.push_back({start, end});
    }

    vector<int> contains(size, 0);
    vector<int> other_contains(size, 0);

    for(int i = 0 ; i < size ; i++)
    {
        int start_time = times[i].first;
        int end_time = times[i].second;
        for(int j = 0 ; j < size ; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(times[j].first >= start_time && times[j].second <= end_time)
            {
                contains[i]++;
            }
        }
        for(int j = 0 ; j < size ; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(times[j].first <= start_time && times[j].second >= end_time)
            {
                other_contains[i]++;
            }
        }
    }

    for(int i = 0; i < size ; i++)
    {
        cout << contains[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < size ; i++)
    {
        cout << other_contains[i] << " ";
    }
    cout << endl;
    
    return 0;
}