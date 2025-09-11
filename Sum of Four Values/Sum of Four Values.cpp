#include<bits/stdc++.h>
using namespace std;


bool allDifferent(int a, int b, int c, int d) 
{
    return a != b && a != c && a != d && b != c && b != d && c != d;
}

int main()
{
    long long size , target_sum;
    cin >> size >> target_sum;

    vector<long long> arr;
    map<long long, vector<pair<int,int>>> sum_pairs;

    for(int i = 0 ; i < size ; i++)
    {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    for(int i = 0 ; i < size ; i++)
    {
        for(int j = i + 1 ; j < size ; j++)
        {
            sum_pairs[arr[i] + arr[j]].push_back({i + 1, j + 1});
        }
    }  

    bool found = false;

    for(auto pair: sum_pairs)
    {
        long long sum = pair.first;
        long long other_sum = target_sum - sum;
        if(sum_pairs.find(other_sum) != sum_pairs.end())
        {
            int size1 = pair.second.size();
            int size2 = sum_pairs[other_sum].size();
            for(int i = 0 ; i < size1 && !found ; i++)
            {
                int index1 = pair.second[i].first;
                int index2 = pair.second[i].second;
                for(int j = 0 ; j < size2 && !found ; j++)
                {
                    int index3 = sum_pairs[other_sum][j].first;
                    int index4 = sum_pairs[other_sum][j].second;
                    if(allDifferent(index1, index2, index3, index4))
                    {
                        cout << index1 << " " << index2 << " " << index3 << " " << index4 << endl;
                        found = true;
                    }
                }
            }
        }

        if(found)
        {
            break;
        }
    }

    if(!found)
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}