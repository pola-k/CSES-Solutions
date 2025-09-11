#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num_of_children, k;
    cin >> num_of_children >> k;

    int total_cases = pow(k, 2);
    float curr = 1.0;
    float num = 0.0;

    for(int i = 1 ; i <= k ; i++)
    {
        num += (i * curr);
        curr += 2;
    }

    double ans = num / total_cases;

    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}