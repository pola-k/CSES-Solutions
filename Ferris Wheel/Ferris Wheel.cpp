#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num_of_children, max_allowed_weight;

    cin >> num_of_children >> max_allowed_weight;

    vector<int> children_weights;
    vector<bool> children_used(num_of_children, false);

    for(int i = 0 ; i < num_of_children ; i++)
    {
        int weight;
        cin >> weight;
        children_weights.push_back(weight);
    }

    sort(children_weights.begin(), children_weights.end());

    int start = 0;
    int end = num_of_children - 1;
    int min_gondolas = 0;

    while(start < end)
    {
        if(!children_used[start] && !children_used[end])
        {
            int weight_sum = children_weights[start] + children_weights[end];
            if(weight_sum <= max_allowed_weight)
            {
                children_used[start] = true;
                children_used[end] = true;
                min_gondolas++;
                start++;
                end--;
            }
            else
            {
                end--;
            }
        }
        else
        {
            if(children_used[end])
            {
                end--;
            }
            else
            {
                start++;
            }
        }
    }

    for(int i = 0 ; i < num_of_children ; i++)
    {
        if(!children_used[i] && children_weights[i] <= max_allowed_weight)
        {
            min_gondolas++;
        }
    }

    cout << min_gondolas;
    return 0;
}