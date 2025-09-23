#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>, long long>& a, pair<pair<int,int>, long long>& b)
{
    if(a.first.first == b.first.first)
    {
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

long long Recursive(int index,  vector<pair<pair<int,int>, long long>>& projects, vector<long long>& dp, vector<int>& nextIndex)
{
    if(index >= projects.size())
    {
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }

    long long take = projects[index].second + Recursive(nextIndex[index], projects, dp, nextIndex);
    long long skip = Recursive(index + 1, projects, dp, nextIndex);

    return dp[index] = max(take, skip);
}

int main()
{
    int number_of_projects;
    cin >> number_of_projects;

    vector<pair<pair<int,int>, long long>> projects;
    vector<long long> dp(number_of_projects + 1, -1);

    for(int i = 0 ; i < number_of_projects ; i++)
    {
        int start, end;
        long long reward;
        cin >> start >> end >> reward;
        projects.push_back({{start, end}, reward});
    }

    sort(projects.begin(), projects.end(), cmp);

    vector<int> nextIndex(number_of_projects, number_of_projects);
    vector<int> startTimes;

    for (int i = 0 ; i < number_of_projects ; i++)
    {
        startTimes.push_back(projects[i].first.first);
    } 
    for (int i = 0; i < number_of_projects; i++) 
    {
        int pos = lower_bound(startTimes.begin(), startTimes.end(), projects[i].first.second + 1) - startTimes.begin();
        nextIndex[i] = pos;
    }

    long long ans = Recursive(0, projects, dp, nextIndex);
    cout << ans << endl;
    return 0;
}