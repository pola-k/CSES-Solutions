#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    map<char, int> freq;
    string ans = "";
    char prev = ' ';
    int size = str.size();

    for(int i = 0 ; i < size ; i++)
    {
        freq[str[i]]++;
    }

    for(int i = 0 ; i < size ; i++)
    {
        bool exists = false;
        for(auto &elem: freq)
        {
            char curr = elem.first;
            int count = elem.second;

            if(curr == prev || count == 0)
            {
                continue;
            }

            freq[curr] -= 1;
            int remaining_length = size - i - 1;
            bool candidate = true;

            for(auto &entry: freq)
            {
                char entry_char = entry.first;
                int entry_count = entry.second;
                if(entry_count > (remaining_length + 1) / 2)
                {
                    candidate = false;
                    break;
                }
            }

            if(candidate)
            {
                ans += curr;
                prev = curr;
                exists = true;
                break;
            }
            else
            {
                freq[curr] += 1;
            }
        }

        if(!exists)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}