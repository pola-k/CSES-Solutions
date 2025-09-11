#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<int> coins;
    int total_sum = 0;

    for(int i = 0 ; i < size ; i++)
    {
        int coin;
        cin >> coin;
        coins.push_back(coin);
        total_sum += coin;
    }

    sort(coins.begin(), coins.end());

    vector<int> sums(total_sum + 1, 0);

    sums[0] = 1;

    for(int i = 0 ; i < size ; i++)
    {
        for(int j = total_sum ; j >= coins[i] ; j--)
        {
            if(j - coins[i] >= 0 && sums[j - coins[i]] == 1)
            {
                sums[j] = 1;
            }
        }
    }

    int count = 0;
    for(int i = 1 ; i <= total_sum ; i++)
    {
        if(sums[i] == 1)
        {
            count++;
        }
    }

    cout << count << endl;

    for(int i = 1 ; i <= total_sum ; i++)
    {
        if(sums[i] == 1)
        {
            cout << i << " ";
        }
    }

    return 0;
}