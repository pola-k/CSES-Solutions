#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int ans = 1, count = 1;

    for (int i = 1; i < str.size(); i++) 
    {
        if (str[i] == str[i - 1]) 
        {
            count++;
        } 
        else 
        {
            count = 1;
        }
        ans = max(ans, count);
    }

    cout << ans;

    return 0;
}