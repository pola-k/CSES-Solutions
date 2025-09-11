#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int total_positions = n * n;
    long long ans = 0;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            int curr_x = i;
            int curr_y = j;
            int count = 0;
            // One Down 2 Right
            if(curr_x + 1 < n && curr_y + 2 < n)
            {
                count++;
            }
            // One Down 2 Left
            if(curr_x + 1 < n && curr_y - 2 >= 0)
            {
                count++;
            }
            // One Up 2 Right
            if(curr_x - 1 >= 0 && curr_y + 2 < n)
            {
                count++;
            }
            // One Up 2 Left
            if(curr_x - 1 >= 0 && curr_y - 2 >= 0)
            {
                count++;
            }
            // One Right 2 Down
            if(curr_x + 2 < n && curr_y + 1 < n)
            {
                count++;
            }
            // One Right 2 Up
            if(curr_x + 2 < n && curr_y - 1 >= 0)
            {
                count++;
            }
            // One Left 2 Down
            if(curr_x + 2 < n && curr_y + 1 < n)
            {
                count++;
            }
            // One Left 2 Up
            if(curr_x - 2 >= 0 && curr_y - 1 >= 0)
            {
                count++;
            }

            ans += (total_positions - count);
        }
    }

    cout << ans;
    return 0;
}