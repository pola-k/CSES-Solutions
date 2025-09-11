#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long number;
    cin >> number;

    while(number != 1)
    {
        cout << number << " ";
        if(number % 2 == 0)
        {
            number /= 2;
        }
        else
        {
            number = number * 3 + 1;
        }
    }

    cout << number;
    return 0;
}