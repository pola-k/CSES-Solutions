#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;

    bool valid = true;
    vector<int> result;
   
    for(int i = 2 ; i <= size ; i+=2)
    {
        result.push_back(i);
    }

    for(int i = 1 ; i <= size ; i+=2)
    {
        result.push_back(i);
    }

    for(int i = 0 ; i < size - 1 ; i++)
    {
        if(abs(result[i + 1] - result[i]) == 1)
        {
            valid = false;
        }
    }

    if(!valid)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    for(int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}