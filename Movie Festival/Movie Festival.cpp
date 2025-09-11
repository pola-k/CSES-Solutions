#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b)
{
    if(a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}


int main()
{
    int number_of_movies;
    cin >> number_of_movies;

    vector<pair<int,int>> movies;

    for(int i = 0 ; i < number_of_movies ; i++)
    {
        int start_time, end_time;
        cin >> start_time >> end_time;
        movies.push_back(make_pair(start_time,end_time));
    }

    sort(movies.begin(), movies.end(), cmp);

    int curr_end = movies[0].second;
    int max_movies = 1;

    for(int i = 1 ; i < number_of_movies ; i++)
    {
        if(movies[i].first >= curr_end)
        {
            max_movies++;
            curr_end = movies[i].second;
        }
    }

    cout << max_movies;
    return 0;
}