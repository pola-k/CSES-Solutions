#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& a , pair<int,int>& b)
{
    return a.first < b.first;
}

int main()
{
    int number_of_customers;
    vector<pair<int,int>> customer_times;

    cin >> number_of_customers;
    for (int i = 0; i < number_of_customers; i++)
    {
        int start_time, end_time;
        cin >> start_time >> end_time;
        customer_times.push_back(make_pair(start_time, end_time));
    }

    sort(customer_times.begin(), customer_times.end(), cmp);

    int max_customers = 1;
    int curr_end = customer_times[0].second;
    multiset<int> customers;
    customers.insert(curr_end);

    for(int i = 1 ; i < number_of_customers ; i++)
    {
        int start_time = customer_times[i].first;
        int end_time = customer_times[i].second;

        auto it = customers.lower_bound(start_time);
        customers.erase(customers.begin(), it);

        customers.insert(end_time);

        max_customers = max(max_customers, int(customers.size()));
    }

    cout << max_customers << endl;
    return 0;
}