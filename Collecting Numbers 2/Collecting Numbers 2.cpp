#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size, number_of_swaps;

    cin >> size >> number_of_swaps;

    vector<int> arr(size + 1);
    vector<pair<int,int>> swaps;
    vector<int> position(size + 1);

    for(int i = 1 ; i <= size ; i++)
    {
        int number;
        cin >> number;
        arr[number] = i;
        position[i] = number;
    }

    for(int i = 0 ; i < number_of_swaps ; i++)
    {
        int start, end;
        cin >> start >> end;
        swaps.push_back(make_pair(start,end));
    }

    int ans = 1;
    for(int j = 1 ; j < size ; j++)
    {
        if(arr[j] > arr[j + 1])
        {
            ans++;
        }
    }

    for(int i = 0 ; i < number_of_swaps ; i++)
    {
        int start = swaps[i].first;
        int end = swaps[i].second;
        int num1 = position[start];
        int num2 = position[end];

        set<pair<int,int>> affected;
        affected.insert({num1 - 1, num1});
        affected.insert({num1, num1 + 1});
        affected.insert({num2 - 1, num2});
        affected.insert({num2, num2 + 1});

        for(auto p:affected)
        {
            int val1 = p.first;
            int val2 = p.second;

            if((val1 > 0 && val2 > 0) && (val1 <= size && val2 <= size))
            {
                if(arr[val1] > arr[val2])
                {
                    ans--;
                }
            }
        }

        swap(arr[num1], arr[num2]);
        position[start] = num2;
        position[end] = num1;

        for(auto p:affected)
        {
            int val1 = p.first;
            int val2 = p.second;

            if((val1 > 0 && val2 > 0) && (val1 <= size && val2 <= size))
            {
                if(arr[val1] > arr[val2])
                {
                    ans++;
                }
            }
        }                

        cout << ans << endl;
    }

    return 0;
}