#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int number_of_machines, products_to_make;
    cin >> number_of_machines >> products_to_make;

    vector<long long> machine_times;
    long long min_value = LLONG_MAX;

    for (int i = 0; i < number_of_machines; i++) 
    {
        long long time;
        cin >> time;
        machine_times.push_back(time);
        min_value = min(min_value, time);
    }

    long long low = 1;
    long long high = min_value * products_to_make; 

    while (low < high) 
    {
        long long mid = (low + high) / 2;
        long long products_made = 0;

        for (long long t : machine_times) 
        {
            products_made += mid / t;
            if (products_made >= products_to_make)
            { 
                break;
            }
        }

        if (products_made >= products_to_make)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}
