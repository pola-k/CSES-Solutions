#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++) 
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    vector<int> ans;
    stack<pair<int,int>> st;

    for (int i = 0; i < size; i++) 
    {
        while (!st.empty() && st.top().first >= arr[i]) 
        {
            st.pop();
        }

        if (st.empty()) 
        {
            ans.push_back(0);
        } 
        else 
        {
            ans.push_back(st.top().second);
        }

        st.push({arr[i], i + 1});
    }

    for (int i = 0; i < size; i++) 
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
