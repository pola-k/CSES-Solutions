#include<bits/stdc++.h>
using namespace std;

int Recursive(int i, vector<int> prices, vector<int> pages, int max_prices, vector<vector<int>>& dp)
{
    if(i >= pages.size())
    {
        return 0;
    }
    if(dp[i][max_prices] != -1)
    {
        return dp[i][max_prices];
    }

    int include = INT_MIN;
    if(max_prices - prices[i] >= 0)
    {
        include = pages[i] + Recursive(i + 1, prices, pages, max_prices - prices[i], dp); 
    }
    int exclude = Recursive(i + 1, prices, pages, max_prices, dp);

    return dp[i][max_prices] = max(include, exclude);
}

int main()
{
    int total_books, max_price;
    cin >> total_books >> max_price;

    vector<int> pages;
    vector<int> prices;
    vector<vector<int>> dp(total_books + 1, vector<int>(max_price + 1, 0));

    for(int i = 0 ; i < total_books ; i++)
    {
        int price;
        cin >> price;
        prices.push_back(price);
    }
    for(int i = 0 ; i < total_books ; i++)
    {
        int num_of_pages;
        cin >> num_of_pages;
        pages.push_back(num_of_pages);
    }

    for(int i = total_books - 1; i >= 0 ; i--)
    {
        for(int j = 0; j <= max_price ; j++)
        {
            int include = INT_MIN;
            int exclude = INT_MIN;
            if((j - prices[i]) >= 0 && i + 1 <= total_books)
            {
                include = pages[i] + dp[i + 1][j - prices[i]];
            }
            if(i + 1 <= total_books)
            {
                exclude = dp[i + 1][j];
            }

            dp[i][j] = max(include, exclude);
        }
    }

    cout << dp[0][max_price] << endl;
    return 0;
}