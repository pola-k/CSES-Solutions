#include <bits/stdc++.h>
using namespace std;
int main() 
{
    long long size;
    long long input_sum = 0;
    cin >> size;
    for(int i = 1 ; i < size ; i++)
    {
        int number;
        cin >> number;
        input_sum += (long long)number;
    }
    
    long long total_sum = (size * (size + 1)) / 2;
    long long ans = total_sum - input_sum;
    cout << ans << '\n';
    return 0;
}