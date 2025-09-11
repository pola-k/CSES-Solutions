#include<bits/stdc++.h>
using namespace std;

int Recursive(int i, int j, vector<int> arr1, vector<int> arr2, vector<vector<int>>& dp)
{
    if(i >= arr1.size() || j >= arr2.size())
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(arr1[i] == arr2[j])
    {
        return dp[i][j] = 1 + Recursive(i + 1, j + 1, arr1, arr2, dp);
    }
    else
    {
        return dp[i][j] = max(Recursive(i + 1, j, arr1, arr2, dp), Recursive(i, j + 1, arr1, arr2, dp));
    }
}

void getSubsequence(vector<int> arr1, vector<int> arr2, vector<vector<int>> dp)
{
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else
        {
            if(dp[i + 1][j] > dp[i][j + 1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    int size1, size2;
    cin >> size1 >> size2;

    vector<int> arr1, arr2;
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

    for(int i = 0; i < size1 ; i++)
    {
        int num;
        cin >> num;
        arr1.push_back(num);
    }

    for(int i = 0 ; i < size2 ; i++)
    {
        int num;
        cin >> num;
        arr2.push_back(num);
    }

    for(int i = size1 - 1 ; i >= 0 ; i--)
    {
        for(int j = size2 - 1; j >= 0 ; j--)
        {
            if(arr1[i] == arr2[j] && (i + 1 <= size1 && j + 1 <= size2))
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                int val1 = INT_MIN;
                int val2 = INT_MIN;
                if(i + 1 <= size1)
                {
                    val1 = dp[i + 1][j];
                }
                if(j + 1 <= size2)
                {
                    val2 = dp[i][j + 1];
                }

                dp[i][j] = max(val1, val2);
            }
        }
    }

    cout << dp[0][0] << endl;
    getSubsequence(arr1, arr2, dp);
    return 0;
}