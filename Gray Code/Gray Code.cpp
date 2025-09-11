#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int num = 0;
    int limit = 1 << size;

    while(num < limit)
    {
        int gray_code_num = num ^ (num >> 1);
        string s = bitset<16>(gray_code_num).to_string();  
        cout << s.substr(16 - size) << endl;
        num++;
    }

    return 0;
}