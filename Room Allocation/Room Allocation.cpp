#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b)
{
    return a.second.first < b.second.first;
}

int main()
{
    int number_of_customers;
    vector<pair<int,pair<int,int>>> customers;

    cin >> number_of_customers;
    for(int i = 0 ; i < number_of_customers ; i++)
    {
        int start, end;
        cin >> start >> end;
        customers.push_back({i, {start, end}});
    }

    sort(customers.begin(), customers.end(), cmp);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > rooms;
    vector<int> ans(number_of_customers);

    for(int i = 0 ; i < number_of_customers ; i++)
    {
        int start_time = customers[i].second.first;
        int end_time = customers[i].second.second;
        int index = customers[i].first;

        if(rooms.empty())
        {
            rooms.push({end_time, 1});
            ans[index] = 1;
        }
        else
        {
            int curr_min = rooms.top().first;
            int curr_room = rooms.top().second;

            if(curr_min < start_time)
            {
                rooms.pop();
                rooms.push({end_time, curr_room});
                ans[index] = curr_room;
            }
            else
            {
                rooms.push({end_time, rooms.size() + 1});
                ans[index] = rooms.size();
            }
        }
    }

    cout << rooms.size() << endl;

    for(int i = 0 ; i < number_of_customers ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}