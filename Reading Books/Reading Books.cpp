#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number_of_books;
    cin >> number_of_books;

    vector<long long> reading_times;

    for(int i = 0 ; i < number_of_books ; i++)
    {
        long long time;
        cin >> time;
        reading_times.push_back(time);
    }

    sort(reading_times.begin(), reading_times.end());

    long long max_reading_time = reading_times[number_of_books - 1];
    long long sum_of_reading_time = accumulate(reading_times.begin(), reading_times.end() - 1, 0LL);

    if (max_reading_time <= sum_of_reading_time) 
    {
        cout << max_reading_time + sum_of_reading_time << endl;
    }
    else
    {
        cout << 2 * max_reading_time << endl;
    }

    return 0;
}