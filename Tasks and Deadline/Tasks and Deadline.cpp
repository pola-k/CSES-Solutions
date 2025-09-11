#include<bits/stdc++.h>
using namespace std;


bool cmp(pair<long long,long long> a, pair<long long,long long> b)
{
    if(a.first == b.first)
    {
        a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    long long number_of_tasks;
    cin >> number_of_tasks;

    vector<pair<long long,long long>> tasks;

    for(long long i = 0 ; i < number_of_tasks ; i++)
    {
        long long duration, deadline;
        cin >> duration >> deadline;
        tasks.push_back({duration, deadline});
    }

    sort(tasks.begin(), tasks.end(), cmp);

    long long start_time = 0;
    long long reward = 0;

    for(long long i = 0 ; i < number_of_tasks ; i++)
    {
        long long duration = tasks[i].first;
        long long end_time = start_time + duration;
        reward += tasks[i].second - end_time;
        start_time = end_time;
    }

    cout << reward << endl;
    return 0;
}