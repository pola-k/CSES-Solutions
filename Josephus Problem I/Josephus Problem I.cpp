#include<bits/stdc++.h>
using namespace std;

int main()
{
    int number_of_people;
    cin >> number_of_people;

    list<int> people;
    for (int i = 1; i <= number_of_people; i++) 
    {
        people.push_back(i);
    }

    list<int>::iterator curr = people.begin();
    while (!people.empty()) 
    {
        curr++;
        if (curr == people.end())
        {
            curr = people.begin();
        } 

        cout << *curr << " ";
        curr = people.erase(curr);

        if (curr == people.end())
        {
            curr = people.begin();
        } 
    }
}