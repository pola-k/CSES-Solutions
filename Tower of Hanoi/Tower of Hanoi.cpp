#include<bits/stdc++.h>
using namespace std;

void Recursive(int n, int src, int middle, int dest, int& count, vector<pair<int,int>>& moves)
{
    if(n > 0)
    {
        Recursive(n - 1, src, dest, middle, count, moves);
        moves.push_back({src, dest});
        count++;
        Recursive(n - 1, middle, src, dest, count, moves);
    }
}

int main()
{
    int n;
    cin >> n;

    int count = 0;
    vector<pair<int,int>> moves;

    Recursive(n, 1, 2, 3, count, moves);

    cout << count << endl;
    for(auto& move : moves)
    {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}