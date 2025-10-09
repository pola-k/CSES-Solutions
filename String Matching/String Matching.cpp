#include<bits/stdc++.h>
using namespace std;

vector<int> LPS(string str)
{
    int size = str.size();
    vector<int> lps(size, 0);
    int j = 0;
    int i = 1;

    while(i < size)
    {
        if(str[i] == str[j])
        {
            j += 1;
            lps[i] = j;
            i += 1;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i += 1;
            }
        }
    }

    return lps;
}

int main()
{
    string str, substr;
    getline(cin, str);
    getline(cin, substr);

    vector<int> lps = LPS(substr);
    int count = 0;
    int j = 0;
    int i = 0;

    while(i < str.size())
    {
        if(str[i] != substr[j])
        {
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i += 1;
            }
        }
        else
        {
            i += 1;
            j += 1;
            
            if(j >= substr.size())
            {
                count++;
                j = lps[j - 1];
            }
        }
    }

    cout << count << endl;
    return 0;
}