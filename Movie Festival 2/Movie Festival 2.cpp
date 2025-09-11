#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

int main()
{
    int num_of_movies, num_of_members;
    cin >> num_of_movies >> num_of_members;

    vector<pair<long long, long long>> movies;
    for(int i = 0 ; i < num_of_movies ; i++)
    {
        long long start, end;
        cin >> start >> end;
        movies.push_back({start, end});
    }

    sort(movies.begin(), movies.end(), cmp);
    multiset<long long> times;

    for(int i = 0 ; i < num_of_members ; i++)
    {
        times.insert(0);
    }

    long long ans = 0;

    for(int i = 0 ; i < num_of_movies ; i++)
    {
        long long start = movies[i].first;
        long long end = movies[i].second;

        auto val = times.upper_bound(start);
        if(val == times.begin())
        {
            continue;
        }

        val--;
        times.erase(val);
        times.insert(end);
        ans++;
    }

    cout << ans << endl;
    return 0;
}