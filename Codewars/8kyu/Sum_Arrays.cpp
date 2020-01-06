#include <vector>

int sum(std::vector<int> nums)
{
    int sum = 0;
    for(auto itor:nums)
    {
        sum += itor;
    }
    return sum;
}