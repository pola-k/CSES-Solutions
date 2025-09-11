#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number_of_songs;
    cin >> number_of_songs;
 
    vector<int> songs;
 
    for(int i = 0 ; i < number_of_songs ; i++)
    {
        int song;
        cin >> song;
        songs.push_back(song);
    }
 
    map<int,int> mp;
    int ans = 0;
    int start = 0;
 
    for(int i = 0 ; i < number_of_songs ; i++)
    {
        if(mp.find(songs[i]) != mp.end())
        {
            int end = mp[songs[i]];
            for(int j = start ; j <= end ; j++)
            {
                mp.erase(songs[j]);
            }
            start = end + 1;
        }
 
        mp[songs[i]] = i;
        ans = max(ans, i - start + 1);
    }
 
    cout << ans << endl;
    return 0;
}