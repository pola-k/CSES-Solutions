#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> arr(size + 1);

    for(int i = 0 ; i < size; i++)
    {
        int num;
        cin >> num;
        arr[num] = i;
    }

    int ans = 1;

    for(int i = 1 ; i < size ; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            ans++;
        }
    }

    cout << ans;
    
    return 0;
}