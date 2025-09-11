#include<bits/stdc++.h>
using namespace std;

long long Factorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main()
{
    string str;
    getline(cin, str);
    map<char, int> count;

    sort(str.begin(), str.end());

    for(int i = 0 ; i < str.size() ; i++)
    {
        count[str[i]]++;
    }

    long long total = Factorial(str.size());

    for(auto ch:count)
    {
        if(ch.second > 1)
        {
            long long val = Factorial(ch.second);
            total = total / val;
        }
    }

    cout << total << endl;
    cout << str << endl;

    while(next_permutation(str.begin(), str.end()))
    {
        cout << str << endl;
    }

    return 0;
}