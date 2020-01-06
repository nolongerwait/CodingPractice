#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>

class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n);
    static std::pair<long long, long long> squaredNumber(long long num);
    static std::vector<long long> listDivisors(long long num);
};

std::vector<long long> SumSquaredDivisors::listDivisors(long long num)
{
    std::vector<long long> listOfDivisors;
    for(long long i = 1; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            listOfDivisors.push_back(i);
            if(i != num / i)
            {
                listOfDivisors.push_back(num / i);
            }
        }
    }
    std::sort(listOfDivisors.begin(), listOfDivisors.end());
    return listOfDivisors;
}

std::pair<long long, long long> SumSquaredDivisors::squaredNumber(long long num)
{
    std::pair<long long, long long> squaredPair;
    std::vector<long long> listOfDivisors = SumSquaredDivisors::listDivisors(num);
    for(auto itor = listOfDivisors.begin(); itor != listOfDivisors.end(); itor++)
    {
        *itor = (*itor) * (*itor);
    }
    long long sumDivisors = std::accumulate(listOfDivisors.begin(), listOfDivisors.end(), 0);
    long long squaredResult = (long long)std::sqrt(sumDivisors);
    if(squaredResult * squaredResult == sumDivisors)
    {
        squaredPair = std::make_pair(num, sumDivisors);
    }
    else
    {
        squaredPair = std::make_pair(-1, -1);
    }
    return squaredPair;
}

std::vector<std::pair<long long, long long>> SumSquaredDivisors::listSquared(long long m, long long n)
{
    std::vector<std::pair<long long, long long>> listSquared;
    for(auto i = m; i <= n; i++)
    {
        std::pair<long long, long long> squaredPair = SumSquaredDivisors::squaredNumber(i);
        if(squaredPair != std::pair<long long, long long> {-1, -1})
        {
            listSquared.push_back(squaredPair);
        }
    }
    return listSquared;
}