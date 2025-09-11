#include<bits/stdc++.h>
using namespace std;


int main()
{
    int num_of_applications;
    int num_of_apartments;
    int allowed_difference;

    cin >> num_of_applications >> num_of_apartments >> allowed_difference;

    priority_queue<int, vector<int>, greater<int>> apartment_sizes;
    vector<int> desired_sizes;

    for(int i = 0 ; i < num_of_applications ; i++)
    {
        int size;
        cin >> size;
        desired_sizes.push_back(size);
    }

    for(int i = 0 ; i < num_of_apartments ; i++)
    {
        int apartment_size;
        cin >> apartment_size;
        apartment_sizes.push(apartment_size);
    }

    sort(desired_sizes.begin(), desired_sizes.end());

    int ans = 0;
    for(int i = 0 ; i < num_of_applications ; i++)
    {
        int lower_val = desired_sizes[i] - allowed_difference;
        int upper_val = desired_sizes[i] + allowed_difference;
        bool value_found = false;

        while(!apartment_sizes.empty() && !value_found)
        {
            int min_value = apartment_sizes.top();
            if(min_value >= lower_val && min_value <= upper_val)
            {
                ans++;
                value_found = true;
            }
            else if(min_value >= lower_val)
            {
                break;
            }
            apartment_sizes.pop();
        }
    }

    cout << ans;
    return 0;
}