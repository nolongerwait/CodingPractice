#include <vector>
#include <iostream>

using namespace std;

class Same {
    public :static bool comp(vector<int>, vector<int>);
};

bool Same::comp(vector<int> a, vector<int> b)
{
    bool flag = true;
    vector<int> square_of_a;
    for(auto itor:a)
    {
        square_of_a.push_back(itor * itor);
    }

    sort(square_of_a.begin(), square_of_a.end());
    sort(b.begin(), b.end());
    
    cout << "a = ";
    for(auto itor:square_of_a)
    {
        cout << itor << " ";
    }
    cout << endl;
    cout << "b = ";
    for(auto itor:b)
    {
        cout << itor << " ";
    }
    cout << endl;

    if(b == square_of_a)
    {
        return true;
    }
    else
    {
        return false;
    }
}