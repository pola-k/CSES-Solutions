#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    string palindrome = "";
    getline(cin, str);

    map<char,int> mp;
    char odd_char;
    int odd_count = 0;

    for(int i = 0 ; i < str.size() ; i++)
    {
        mp[str[i]]++;
    }

    for(auto ch:mp)
    {
        if(ch.second % 2)
        {
            odd_count++;
            odd_char = ch.first;
        }
    }

    if(odd_count > 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for(auto ch:mp)
    {
        if(ch.first != odd_char)
        {
            palindrome.append(ch.second / 2, ch.first);
        }
    }

    string half = palindrome;

    if(odd_count)
    {
        palindrome.append(mp[odd_char], odd_char);
    }

    reverse(half.begin(), half.end());
    palindrome.append(half);

    cout << palindrome;
    return 0;
}