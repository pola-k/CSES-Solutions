#include<bits/stdc++.h>
using namespace std;


bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
    if(a.second.first == b.second.first)
    {
        return a.second.second > b.second.second;
    }
    else
    {
        return a.second.first < b.second.first;
    }
}

int main()
{
    int size;
    cin >> size;

    vector<pair<int, pair<int,int>>> times;

    for(int i = 0 ; i < size ; i++)
    {
        int start, end;
        cin >> start >> end;
        times.push_back({i, {start, end}});
    }

    sort(times.begin(), times.end(), cmp);

    vector<int> contains_other(size, 0);
    vector<int> other_contains(size, 0);

    int min_curr_end = times[size - 1].second.second;
    for(int i = size - 2 ; i >= 0 ; i--)
    {
        int end_time = times[i].second.second;
        int index = times[i].first;
        if(end_time >= min_curr_end)
        {
            contains_other[index] = 1;
        }
        else
        {
            min_curr_end = end_time;
        }
    }

    int max_curr_end = times[0].second.second;
    for(int i = 1 ; i < size ; i++)
    {
        int end_time = times[i].second.second;
        int index = times[i].first;

        if(end_time <= max_curr_end)
        {
            other_contains[index] = 1;
        }
        else
        {
            max_curr_end = end_time;
        }
    }

    for(int i = 0 ; i < size ; i++)
    {
        cout << contains_other[i] << " ";
    }
    cout << endl;

    for(int i = 0 ; i < size ; i++)
    {
        cout << other_contains[i] << " ";
    }
    cout << endl;

    return 0;
}