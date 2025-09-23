#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree< int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update >
using namespace std;

int main()
{
    int number_of_people, skip;
    cin >> number_of_people >> skip;

    ordered_set peoples;

    for(int i = 1; i <= number_of_people; i++)
    {
        peoples.insert(i);
    }

    int to_remove = skip % peoples.size();

    while(!peoples.empty())
    {
        int removed_value = *peoples.find_by_order(to_remove);
        peoples.erase(removed_value);

        cout << removed_value << " ";
        if(!peoples.empty())
        {
            to_remove = (to_remove + skip) % peoples.size();
        }
    }

    cout << endl;
    return 0;
}