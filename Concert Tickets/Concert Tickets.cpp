#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number_of_tickets, number_of_customers;
    cin >> number_of_tickets >> number_of_customers;

    multiset<int> ticket_prices;

    for(int i = 0 ; i < number_of_tickets ; i++)
    {
        int ticket;
        cin >> ticket;
        ticket_prices.insert(ticket);
    }

    for(int i = 0 ; i < number_of_customers ; i++)
    {
        int preferred_price;
        cin >> preferred_price;
        auto upper_price = ticket_prices.upper_bound(preferred_price);

        if(upper_price == ticket_prices.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *(--upper_price) << endl;
            ticket_prices.erase(upper_price);
        }
    }

    return 0;
}