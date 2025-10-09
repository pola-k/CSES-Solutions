#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int queries;
    cin >> queries;

    vector<pair<long long, long long>> limits;
    limits.push_back({1, 9});

    long long start = 1, end = 9;
    for (int i = 2; i <= 18; i++) 
    {
        long long count = 9 * (long long)pow(10, i - 1);
        long long new_start = end + 1;
        long long new_end = new_start + count * i - 1;
        limits.push_back({new_start, new_end});
        end = new_end;
    }

    while (queries--) 
    {
        long long k;
        cin >> k;

        int digits = 0;
        while (k > limits[digits].second)
        {
            digits++;
        }

        long long start_index = limits[digits].first;
        long long num_digits = digits + 1;

        long long first_num = (digits == 0 ? 1 : (long long)pow(10, digits));
        long long offset = k - start_index;
        long long number = first_num + offset / num_digits;
        int digit_index = offset % num_digits;

        string s = to_string(number);
        cout << s[digit_index] << "\n";
    }

    return 0;
}
