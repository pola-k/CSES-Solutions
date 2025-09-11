#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number_of_tests;
    cin >> number_of_tests;

    for(int i = 0; i < number_of_tests; i++)
    {
        int n, score1, score2;
        cin >> n >> score1 >> score2;
        int start1 = 1;
        int start2 = 1;
        int end1 = n;
        int end2 = n;
        int equal = n - score1 - score2;

        if(equal < 0)
        {
            cout << "NO";
        }
        else
        {
            vector<int> player1, player2;
            while(equal)
            {
                player1.push_back(end1--);
                player2.push_back(end2--);
                equal--;
            }

            while(score1 && start1 <= end1 && start2 <= end2)
            {
                player1.push_back(end1--);
                player2.push_back(start2++);
                score1--;
            }

            while(score2 && start1 <= end1 && start2 <= end2)
            {
                player1.push_back(start1++);
                player2.push_back(end2--);
                score2--;
            }

            if(!score1 && !score2)
            {
                cout << "YES";
                for(int i = 0 ; i < n ; i++)
                {
                    cout << player1[i] << " ";
                }
                cout << "\n";
                for(int i = 0 ; i < n ; i++)
                {
                    cout << player2[i] << " ";
                }
                cout << "\n";
            }
            else
            {
                cout << "NO";
            }

        }
    }

    return 0;
}