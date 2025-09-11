#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int size, test_cases;
    cin >> size >> test_cases;

    set<int> road;
    road.insert(0);
    road.insert(size);

    map<int,int> differences;
    differences[size]++;

    for(int i = 0; i < test_cases; i++) 
    {
        int num; 
        cin >> num;

        auto upper = road.upper_bound(num);
        auto lower = prev(upper);

        int old_diff = *upper - *lower;
        if(--differences[old_diff] == 0) differences.erase(old_diff);

        differences[num - *lower]++;
        differences[*upper - num]++;
        road.insert(num);

        cout << differences.rbegin()->first << " ";
    }

    return 0;
}
