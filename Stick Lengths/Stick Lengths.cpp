#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number_of_sticks;
    cin >> number_of_sticks;

    vector<int> stick_lengths;
    for(int i = 0; i < number_of_sticks; i++)
    {
        int length;
        cin >> length;
        stick_lengths.push_back(length);
    }
    
    sort(stick_lengths.begin(), stick_lengths.end());

    int median_value = stick_lengths[number_of_sticks / 2];

    long long total_cost = 0;

    for(int length : stick_lengths)
    {
        total_cost += abs(median_value - length);
    }

    cout << total_cost << "\n";
    return 0;
}
