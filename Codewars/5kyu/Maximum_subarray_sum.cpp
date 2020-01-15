#include <vector>

using namespace std;

int maxSequence(const vector<int>& arr)
{
    if(arr.empty())
    {
        return 0;
    }
    
    vector<int> dp;
    dp.push_back(arr[0]);
    for(int i =1; i < arr.size(); i++)
    {
        dp.push_back(arr[i] > (dp[i-1] + arr[i]) ? arr[i] : dp[i-1] + arr[i]);
    }
    int k = 0;
    for(int i = 1; i < arr.size(); i++)
    {
        if(dp[i] > k)
        {
            k = dp[i];
        }
    }

    return k;
}