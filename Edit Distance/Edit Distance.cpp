#include <bits/stdc++.h>
using namespace std;

int Recursive(int i, int j, string &str1, string &str2, vector<vector<int>>& dp)
{
    if(i == str1.size())
    { 
        return str2.size() - j;
    }
    if(j == str2.size()) 
    { 
        return str1.size() - i;
    }
    if(dp[i][j] != -1) 
    {
        return dp[i][j];
    }

    if(str1[i] == str2[j]) 
    {
        return dp[i][j] = Recursive(i+1, j+1, str1, str2, dp);
    } 
    else 
    {
        int insertOp  = 1 + Recursive(i, j+1, str1, str2, dp);
        int deleteOp  = 1 + Recursive(i+1, j, str1, str2, dp);
        int replaceOp = 1 + Recursive(i+1, j+1, str1, str2, dp);
        return dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int size1 = str1.size();
    int size2 = str2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, -1));
    
    cout << Recursive(0, 0, str1, str2, dp);
    return 0;
}
