#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number_of_tests;
    cin >> number_of_tests;

    for(int i = 0 ; i < number_of_tests ; i++)
    {
        long long left, right;
        cin >> left >> right;

        if(right > left)
        {
            swap(left, right);
        }
        
        if((left + right) % 3 != 0 || (left > 2 * right))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}