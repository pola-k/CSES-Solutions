#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    long long target_sum;
    cin >> size >> target_sum;

    vector<pair<long long,int>> arr;
    
    for (int i = 0; i < size; i++) 
    {
        long long num;
        cin >> num;
        arr.push_back({num, i + 1});
    }

    sort(arr.begin(), arr.end());

    for (int start = 0; start < size; start++) 
    {
        int mid = start + 1;
        int end = size - 1;

        while (mid < end) 
        {
            long long sum = arr[start].first + arr[mid].first + arr[end].first;
            if (sum == target_sum) 
            {
                cout << arr[start].second << " " << arr[mid].second << " " << arr[end].second << endl;
                return 0;
            }
            if (sum < target_sum)
            {
                mid++;
            }
            else
            {
                end--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
